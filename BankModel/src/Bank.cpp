#include <iostream>
#include "Bank.h"
#include <chrono>
#include "Customer.h"
#include "Date.h"
#include "Debit.h"
#include "Credit.h"
#include "Deposit.h"
#include "Transfer.h"
#include "Take.h"
#include "Put.h"


int Bank::bankID = 0;

Bank::Bank(long moneyLimit, long suspLimit, double percentage, double commission){
    this->percentage = percentage;
    this->commission = commission;
    this->moneyLimit = moneyLimit;
    this->suspLimit = suspLimit;
    this->thisBankID = ++bankID;
    this->timeB_ = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now() - std::chrono::minutes(5));
}

int Bank::getBankID(){
    return thisBankID;
}

void Bank::addCustomer(Customer* customer){
    customers.push_back(customer);
}

bool Bank::isCustomer(int customerID){
    for(std::vector<Customer*>::iterator i = customers.begin(); i != customers.end(); ++i){
        if((*i)->getIDCustomer() == customerID) return true;
    }
    return false;
}

void Bank::CheckUpdateSusp(int customerID, Account* newAcc){
    bool flag = false, flag2 = false;
    for(std::vector<Customer*>::iterator i = customers.begin(); i != customers.end(); ++i){
        if(customerID == (*i)->getIDCustomer()){
            if(!(*i)->getAddressCustomer().empty() && !(*i)->getPassportCustomer().empty()){
                newAcc->setSuspicious(false);
                flag = true;
            }
            flag2 = true;
        }
    }
    if(!flag) newAcc->setSuspicious(true);
    if(!flag2) throw std::runtime_error("Error! No customer found in customers within the function Bank::CheckUpdateSusp().\n");
}

void Bank::addAccount(int clientID, const std::string& account){
    Account* newAcc;
    int count = 1;
    for(std::map<int, std::vector<Account*>>::iterator i = accounts.begin(); i != accounts.end(); ++i){
        if(i->first == clientID){
            count += i->second.size();
            break;
        }
    }
    if(account == "debit") newAcc = new Debit(this->percentage, count);
    else if(account == "credit"){
        newAcc = new Credit(this->commission, count, moneyLimit);
    }
    else {
        std::cout << "In order to make a deposit account, you need to put some money!\nPlease insert a certain sum:\n";
        long money;
        std::cin >> money;
        std::cout << "Enter the date after which it'll be possible to operate with money:\n";
        int d, m;
        std::cin >> d >> m;
        Date *date = new Date(d, m);
        newAcc = new Deposit(this->percentage, money, count, *date);
    }
    CheckUpdateSusp(clientID, newAcc);
    accounts[clientID].push_back(newAcc);
}

std::vector<Customer*> Bank::getCustomers(){
    if(!customers.empty()) return customers;
    else throw std::runtime_error("Error! Empty vector within the function Bank::getCustomers().\n");
}

double Bank::getComm(){
    return commission;
}

double Bank::getPerc(){
    return percentage;
}

long Bank::getMoneyLim(){
    return moneyLimit;
}

std::vector<Account*> Bank::getAccounts(int cID){
    for(auto& i : accounts) if(i.first == cID) return i.second;
    throw std::runtime_error("Error! This client does not have any account yet within the function std::vector<Account*> Bank::getAccounts().\n");
}

int Bank::setCommandID(){
    return (int)commands.size() + 1;
}

void Bank::takeMoney(int cID, long money){
    if(!isCustomer(cID)) throw std::runtime_error("Error! Such client does not exist within the function Bank::putMoney().\n");
    std::cout << "Your account:\n";
    std::vector<Account*> temp = getAccounts(cID);
    
    int n;
    for(int i = 0; i < temp.size(); i++) 
        std::cout << temp[i]->getAccountID() << " " << temp[i]->getNameAccount() << " " << temp[i]->getMoneyAccount() << "\n";
    std::cout << "Pick from which account you'd like to take money:\n";
    std::cin >> n;
    
    Account* a = nullptr;
    for(auto& i : temp)
        if(i->getAccountID() == n){
            CheckUpdateSusp(cID, i);
            a = i;
        }
    
    if (a->isSuspicious() && money > suspLimit) {
        throw std::runtime_error("Fail! Within isSuspicious()!");
    }
    Command* takee = new Take(setCommandID(), a, money);
    command(takee);
}

void Bank::putMoney(int cID, long money){
    if(!isCustomer(cID)) throw std::runtime_error("Error! Such client does not exist within the function Bank::putMoney().\n");
    std::cout << "Your account:\n";
    auto temp = getAccounts(cID);
    int n;
    for(int i = 0; i < temp.size(); i++) std::cout << temp[i]->getAccountID() << " " << temp[i]->getNameAccount() << " " << temp[i]->getMoneyAccount() << "\n";
    std::cout << "Pick in which account you'd like to put money:\n";
    std::cin >> n;
    
    Account* a = nullptr;
    for(auto& i : temp) if(i->getAccountID() == n) { a = i; CheckUpdateSusp(cID, i);}
    Command* putt = new Put(setCommandID(), a, money);
    command(putt);
}

void Bank::transferMoney(int cID, int cID2){
    if(!isCustomer(cID) || !isCustomer(cID2)) throw std::runtime_error("Error! Such client does not exist within the function Bank::transferMoney().\n");
    
    std::cout << "Your account:\n";
    auto temp = getAccounts(cID);
    int n, n2;
    for(int i = 0; i < temp.size(); i++) std::cout << temp[i]->getAccountID() << " " << temp[i]->getNameAccount() << " " << temp[i]->getMoneyAccount() << "\n";
    std::cout << "Pick from which account you'd like to transfer money:\n";
    std::cin >> n;
    
    std::cout << "\nThese are all accounts from the other client:\n";
    auto temp2 = getAccounts(cID2);
    for(int i = 0; i < temp2.size(); i++) std::cout << temp2[i]->getAccountID() << " " << temp2[i]->getNameAccount() << "\n";
    std::cout << "Pick to which account you'd like to transfer money:\n";
    std::cin >> n2;
    
    long money;
    std::cout << "\nInput the amount of money you'd like to transfer:\n";
    std::cin >> money;
    
    Account *a = nullptr, *a2 = nullptr;
    for(auto& i : temp) if(i->getAccountID() == n) {a = i; CheckUpdateSusp(cID, i);}
    for(auto& i : temp2) if(i->getAccountID() == n2) {a2 = i; CheckUpdateSusp(cID2, i);}
        
    Command* transferr = new Transfer(setCommandID(), a, a2, money);
    command(transferr);
}

void Bank::command(Command* c){
    c->run();
    commands[c->getCommandID()] = c;
}

void Bank::printCustomers(){
    for(auto i = customers.begin(); i != customers.end(); ++i) std::cout << (*i)->getIDCustomer() << " " << (*i)->getNameCustomer() << " " << (*i)->getSurnameCustomer() << " " << (*i)->getPassportCustomer() << " " << (*i)->getAddressCustomer() << "\n";
    std::cout << std::endl;
}

void Bank::printAccounts(){
    for(auto& i : accounts) for(auto& j : i.second) std::cout << j->getAccountID() << " " << j->getNameAccount() << " " << j->getMoneyAccount() << " " << (j->isSuspicious()? "suspicious" : "not suspicious") << "\n";
}

void Bank::printAll(){
    for(auto i = customers.begin(); i != customers.end(); ++i){
        std::cout << "Customer ID: " << (*i)->getIDCustomer()
                  << ", Name and surname: " << (*i)->getNameCustomer()
                  << " " << (*i)->getSurnameCustomer()
                  << ((!(*i)->getPassportCustomer().empty())? (", Passport: " + (*i)->getPassportCustomer()) : "")
                  << ((!(*i)->getAddressCustomer().empty())? (", Address: " + (*i)->getAddressCustomer()) : "")
        << std::endl;
        auto temp = getAccounts((*i)->getIDCustomer());
        for(auto& k : temp){
            CheckUpdateSusp((*i)->getIDCustomer(), k);
            std::cout << k->getAccountID() << " " << k->getNameAccount() << " " << k->getMoneyAccount() << " " << (k->isSuspicious()? "suspicious" : "not suspicious") << "\n";
        }
    }
}

void Bank::cancel(int ID){
    bool flag = false;
    for(auto& i : commands){
        if(i.first == ID){
            Command* c = i.second;
            c->undo();
            flag = true;
        }
    }
    if(!flag) throw std::runtime_error("Error! Invalid ID of the command within the function Bank::cancel().\n");
}

void Bank::dailyIR(){
    std::map<int, std::vector<Account*>>::iterator it;
    for(it = accounts.begin(); it != accounts.end(); ++it){
        for(std::vector<Account*>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            if((*it2)->getNameAccount() != "credit"){
                (*it2)->addIRDay();
            }
        }
        
    }
}

void Bank::monthlyIR(){
    std::map<int, std::vector<Account*>>::iterator it;
    for(it = accounts.begin(); it != accounts.end(); ++it){
        for(std::vector<Account*>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            if((*it2)->getNameAccount() != "credit"){
                Date now = Date::getNow();
                if(now.getDay() == 1) (*it2)->addIRMonth();
                else std::cout << "No money, no family, 16 in the middle of Miami!\n";
            }
        }
        
    }
}