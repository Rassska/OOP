//
//  Banks.cpp
//  Banks
//
//  Created by Sara Nikolić on 06.12.2020.
//

#include "Banks.hpp"
#include <iostream>

int Client::clientID = 0;
int Bank::bankID = 0;

// --- DATE ---
Date::Date(int mday, int mth){
    time.tm_mday = mday;
    time.tm_year = 120;
    time.tm_mon = mth;
    time.tm_sec = 0;
    time.tm_yday = 0;
    time.tm_hour = 0;
    time.tm_isdst = 0;
    time.tm_wday = 0;
    time.tm_min = 0;
}

Date::Date(tm time){
    this->time = time;
}

time_t Date::getTime(){
    return mktime(&time);
}

bool Date::operator<(Date &another){
    return getTime() < another.getTime();
}

bool Date::operator==(Date &another){
    return getTime() == another.getTime();
}

Date Date::getNow(){
    time_t now = std::time(nullptr);
    return Date(*gmtime(&now));
}

int Date::getDay(){
    return time.tm_mday;
}


// --- ACCOUNTS ---
Account::Account() = default;

int Account::getAccountID() const {
    return thisAccountID;
}

double Account::getCommission() const {
    return commission;
}

double Account::getInterestRate() const {
    return interestRate;
}

Accounts Account::getNameAccount() const {
    return nameAccount;
}

bool Account::isSuspicious() const{
    return suspicious;
}

std::string Account::getNameAccountString() const {
    if(nameAccount == 0) return "debit";
    else if(nameAccount == 1) return "credit";
    else return "deposit";
}

long Account::getMoneyAccount() const{
    return money_;
}

void Account::setSuspicious(bool var){
    this->suspicious = var;
}

void Account::takeMoney(long money){
    if(money_ >= money && money > 0) money_ -= money;
    else throw std::runtime_error("Error! Impossible to take such amount from the account within the function Account::takeMoney().\n");
}

void Account::putMoney(long money){
    money_ += money;
}

void Account::transferMoney(Account *ac, long money){
    this->takeMoney(money);
    ac->putMoney(money);
}

// - DEBIT
void Debit::setCommission(double comm){
    if(comm != 1) throw std::runtime_error("Error! Debit account cannot have commision within function Debit::setCommission().\n");
    this->commission = comm; // no commission
}

void Debit::setInterestRate(double IR){
    this->interestRate = IR / 365; // fixed
}

Debit::Debit(double ir, int count){
    this->thisAccountID = count;
    this->nameAccount = debit;
    this->setCommission(1);
    this->money_ = 0;
    this->setInterestRate(ir);
}

void Debit::takeMoney(long money) {
    Account::takeMoney(money);
}

void Debit::putMoney(long money){
    Account::putMoney(money);
}

void Debit::transferMoney(Account* ac, long money){
    Account::transferMoney(ac, money);
}

void Debit::addIRDay(){
    this->pocket += money_ * interestRate;
}

void Debit::addIRMonth(){
    this->money_ += this->pocket;
}

// - DEPOSIT
void Deposit::setCommission(double comm){
    if(comm != 1) throw std::runtime_error("Error! Deposit account cannot have commision within function Deposit::setCommission().\n");
    this->commission = comm; // no commission
}

void Deposit::setInterestRate(double IR){ // depends on money
    if(this->money_ < 500) this->interestRate = IR / 365;
    if(this->money_ >= 500 && this->money_ < 1000) this->interestRate = (IR + 0.5) / 365;
    if(this->money_ >= 1000 && this->money_ < 5000) this->interestRate = (IR + 1) / 365;
    if(this->money_ > 5000) this->interestRate = (IR + 1.5) / 365;
}

Deposit::Deposit(double ir, long money, int count, Date finalDate){
    this->thisAccountID = count;
    this->nameAccount = deposit;
    this->setCommission(1);
    this->money_ = money;
    this->setInterestRate(ir);
    this->time_ = finalDate;
}

void Deposit::takeMoney(long money){
    Date now = Date::getNow();
    if(time_ < now) Account::takeMoney(money);
    else throw std::runtime_error("Error! Cannot take money from Deposit account before time limit within the function Deposit::takeMoney().\n");
}

void Deposit::putMoney(long money){
    Account::putMoney(money);
}

void Deposit::transferMoney(Account* ac, long money){
    Date now = Date::getNow();
    if(time_ < now) Account::transferMoney(ac, money);
    else throw std::runtime_error("Error! Cannot transfer money from Deposit account before time limit within the function Deposit::transferMoney().\n");
}

void Deposit::addIRDay(){
    this->pocket += money_ * interestRate;
}

void Deposit::addIRMonth(){
    this->money_ += this->pocket;
}

// - CREDIT
void Credit::setCommission(double comm){
    this->commission = comm;
}

void Credit::setInterestRate(double IR){
    if(IR != 1) throw std::runtime_error("Error! Credit account cannot have interest rate within function Credit::setInterestRate().\n");
    this->interestRate = IR;
}

Credit::Credit(double ir, int count, long limit){
    this->creditLimit = limit;
    this->thisAccountID = count;
    this->nameAccount = credit;
    this->setCommission(ir); // this is commission!
    this->money_ = 0;
    this->setInterestRate(1);
}

bool Credit::isCredLim_valid(){
    return ((creditLimit >= 0)? true : false);
}

void Credit::takeMoney(long money){
    if(this->money_ >= money) Account::takeMoney(money);
    else{
        if(isCredLim_valid()){
            if(this->money_ - money < 0){
                if(creditLimit < abs(this->money_ - money)) {
                    throw std::runtime_error("Error! Credit account exceeded the limit within the function Credit::takeMoney().\n");
                }
                else {
                    long temp = money - this->money_;
                    this->money_ = 0;
                    creditLimit -= temp * commission + temp;
                    std::cout << "Warning! You are wasting credit limit! Right now it's: " << creditLimit << ".\n" ;
                }
            }
            else Account::takeMoney(money);
        } else throw std::runtime_error("Error! Credit limit exceeded, operation unable within the function Credit::takeMoney().\n");
    }
}

void Credit::putMoney(long money){
    long temp;
    if(!isCredLim_valid()){
        temp = money + creditLimit;
        creditLimit += (int)money - (int)temp;
        if(temp > 0) Account::putMoney(temp);
    } else {Account::putMoney(money);}
}

void Credit::transferMoney(Account* ac, long money){
    Account::transferMoney(ac, money);
}

void Credit::addIRDay(){}
void Credit::addIRMonth(){}

// --- COMMAND ---
int Command::getCommandID(){
    return commandID;
}

Transfer::Transfer(int id, Account* a, Account* a2, long money){
    commandID = id;
    acc_ = a;
    money_ = money;
    acc2_ = a2;
}

void Transfer::run() const{
    acc_->transferMoney(acc2_, money_);
}

void Transfer::undo() const{
    acc2_->transferMoney(acc_, money_);
}

Take::Take(int id, Account* a, long money){
    commandID = id;
    acc_ = a;
    money_ = money;
}

void Take::run() const{
    acc_->takeMoney(money_);
}

void Take::undo() const{
    acc_->putMoney(money_);
}

Put::Put(int id, Account* a, long money){
    commandID = id;
    acc_ = a;
    money_ = money;
}

void Put::run() const{
    acc_->putMoney(money_);
}

void Put::undo() const{
    acc_->takeMoney(money_);
}

// --- CLIENT ---
Client::Client(const std::string& name, const std::string& surname) : nameClient(name), surnameClient(surname){
    this->thisClientID = ++clientID;
}

int Client::getIDClient() const {
    return thisClientID;
}

std::string Client::getNameClient() const {
    return this->nameClient;
}

std::string Client::getSurnameClient() const {
    return this->surnameClient;
}

std::string Client::getAddressClient() const {
    return this->addressClient;
}

std::string Client::getPassportClient() const {
    return this->passportClient;
}

void Client::setAddressClient(const std::string& pass){
    addressClient = pass;
}

void Client::setPassportClient(const std::string& pass){
    passportClient = pass;
}

ClientBuilder::~ClientBuilder(){
    delete client_;
}

void ClientBuilder::setClient(const std::string& name, const std::string& surname) {
    Client* cli = new Client(name, surname);
    client_ = cli;
}

void ClientBuilder::setPassport(const std::string& pass) {
    this->client_->setPassportClient(pass);
}

void ClientBuilder::setAddress(const std::string& pass) {
    this->client_->setAddressClient(pass);
}

Client* ClientBuilder::getClient() {
    if(client_ == nullptr) throw std::runtime_error("Error! Client does not exist within the function ClientBuilder::getClient().\n");
    return client_;
}

void ClientBuilder::reset(){
    this->client_ = nullptr;
}

// --- BANK ---
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

void Bank::addClient(Client* client){
    clients.push_back(client);
}

bool Bank::isClient(int clientID){
    for(std::vector<Client*>::iterator i = clients.begin(); i != clients.end(); ++i){
        if((*i)->getIDClient() == clientID) return true;
    }
    return false;
}

void Bank::CheckUpdateSusp(int clientID, Account* newAcc){
    bool flag = false, flag2 = false;
    for(std::vector<Client*>::iterator i = clients.begin(); i != clients.end(); ++i){
        if(clientID == (*i)->getIDClient()){
            if(!(*i)->getAddressClient().empty() && !(*i)->getPassportClient().empty()){
                newAcc->setSuspicious(false);
                flag = true;
            }
            flag2 = true;
        }
    }
    if(!flag) newAcc->setSuspicious(true);
    if(!flag2) throw std::runtime_error("Error! No client found in clients within the function Bank::CheckUpdateSusp().\n");
}

// grasp creator
void Bank::addAccount(int clientID, Accounts account){
    Account* newAcc;
    int count = 1;
    for(std::map<int, std::vector<Account*>>::iterator i = accounts.begin(); i != accounts.end(); ++i){
        if(i->first == clientID){
            count += i->second.size();
            break;
        }
    }
    if(account == debit) newAcc = new Debit(this->percentage, count);
    else if(account == credit){
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

std::vector<Client*> Bank::getClients(){
    if(!clients.empty()) return clients;
    else throw std::runtime_error("Error! Empty vector within the function Bank::getClients().\n");
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
    if(!isClient(cID)) throw std::runtime_error("Error! Such client does not exist within the function Bank::putMoney().\n");
    std::cout << "Your account:\n";
    std::vector<Account*> temp = getAccounts(cID);
    int n;
    for(int i = 0; i < temp.size(); i++) std::cout << temp[i]->getAccountID() << " " << temp[i]->getNameAccountString() << " " << temp[i]->getMoneyAccount() << "\n";
    std::cout << "Pick from which account you'd like to take money:\n";
    std::cin >> n;
    
    Account* a = nullptr;
    for(auto& i : temp)
        if(i->getAccountID() == n){
            CheckUpdateSusp(cID, i);
            a = i;
        }
    Command* takee = new Take(setCommandID(), a, money);
    command(takee);
}

void Bank::putMoney(int cID, long money){
    if(!isClient(cID)) throw std::runtime_error("Error! Such client does not exist within the function Bank::putMoney().\n");
    std::cout << "Your account:\n";
    auto temp = getAccounts(cID);
    int n;
    for(int i = 0; i < temp.size(); i++) std::cout << temp[i]->getAccountID() << " " << temp[i]->getNameAccountString() << " " << temp[i]->getMoneyAccount() << "\n";
    std::cout << "Pick in which account you'd like to put money:\n";
    std::cin >> n;
    
    Account* a = nullptr;
    for(auto& i : temp) if(i->getAccountID() == n) { a = i; CheckUpdateSusp(cID, i);}
    Command* putt = new Put(setCommandID(), a, money);
    command(putt);
}

void Bank::transferMoney(int cID, int cID2){
    if(!isClient(cID) || !isClient(cID2)) throw std::runtime_error("Error! Such client does not exist within the function Bank::transferMoney().\n");
    
    std::cout << "Your account:\n";
    auto temp = getAccounts(cID);
    int n, n2;
    for(int i = 0; i < temp.size(); i++) std::cout << temp[i]->getAccountID() << " " << temp[i]->getNameAccountString() << " " << temp[i]->getMoneyAccount() << "\n";
    std::cout << "Pick from which account you'd like to transfer money:\n";
    std::cin >> n;
    
    std::cout << "\nThese are all accounts from the other client:\n";
    auto temp2 = getAccounts(cID2);
    for(int i = 0; i < temp2.size(); i++) std::cout << temp2[i]->getAccountID() << " " << temp2[i]->getNameAccountString() << "\n";
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

void Bank::printClients(){
    for(auto i = clients.begin(); i != clients.end(); ++i) std::cout << (*i)->getIDClient() << " " << (*i)->getNameClient() << " " << (*i)->getSurnameClient() << " " << (*i)->getPassportClient() << " " << (*i)->getAddressClient() << "\n";
    std::cout << std::endl;
}

void Bank::printAccounts(){
    for(auto& i : accounts) for(auto& j : i.second) std::cout << j->getAccountID() << " " << j->getNameAccountString() << " " << j->getMoneyAccount() << " " << (j->isSuspicious()? "suspicious" : "not suspicious") << "\n";
}

void Bank::printAll(){
    for(auto i = clients.begin(); i != clients.end(); ++i){
        std::cout << "Client ID: " << (*i)->getIDClient()
                  << ", Name and surname: " << (*i)->getNameClient()
                  << " " << (*i)->getSurnameClient()
                  << ((!(*i)->getPassportClient().empty())? (", Passport: " + (*i)->getPassportClient()) : "")
                  << ((!(*i)->getAddressClient().empty())? (", Address: " + (*i)->getAddressClient()) : "")
        << std::endl;
        auto temp = getAccounts((*i)->getIDClient());
        for(auto& k : temp){
            CheckUpdateSusp((*i)->getIDClient(), k);
            std::cout << k->getAccountID() << " " << k->getNameAccountString() << " " << k->getMoneyAccount() << " " << (k->isSuspicious()? "suspicious" : "not suspicious") << "\n";
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
            if((*it2)->getNameAccount() != credit){
                (*it2)->addIRDay();
            }
        }
        
    }
}

void Bank::monthlyIR(){
    std::map<int, std::vector<Account*>>::iterator it;
    for(it = accounts.begin(); it != accounts.end(); ++it){
        for(std::vector<Account*>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            if((*it2)->getNameAccount() != credit){
                Date now = Date::getNow();
                if(now.getDay() == 1) (*it2)->addIRMonth();
                else std::cout << "No money, no family, 16 in the middle of Miami!\n";
            }
        }
        
    }
}

// --- SYSTEM UTILITY ---
void SystemUtility::addBank(const std::string &name, long moneyLimit, long suspLimit, double p, double c){
    Bank banka(moneyLimit, suspLimit, p, c);
    auto pr = std::make_pair(name, banka);
    banks.insert(pr);
}

std::map<std::string, Bank> SystemUtility::getBanks(){
    return banks;
}

Bank& SystemUtility::getBank(const std::string &bank){
    for(std::map<std::string, Bank>::iterator i = banks.begin(); i != banks.end(); ++i)
        if(bank == i->first) return i->second; // bank!
    throw std::runtime_error("Error! Could not find bank within the function SystemUtility::getBank().\n");
}

void SystemUtility::addClient(const std::string& bank, Client* client){
    auto& Bank = getBank(bank);
    Bank.addClient(client);
}

void SystemUtility::addAccount(const std::string &bank, int clientID, Accounts accountName){
    auto& Bank = getBank(bank);
    Bank.addAccount(clientID, accountName);
}

void SystemUtility::printBank(){
    for(auto& i : banks) {
        i.second.dailyIR();
        i.second.monthlyIR();
        std::cout << i.first << "\n";
        i.second.printClients();
        std::cout << "And some accounts...\n";
        i.second.printAccounts();
    }
}

void SystemUtility::transferMoney(const std::string &bank, int clientID, int clientID2){
    auto& Bank = getBank(bank);
    Bank.transferMoney(clientID, clientID2);
}

void SystemUtility::putMoney(const std::string &bank, int clientID){
    auto& Bank = getBank(bank);
    long money;
    std::cout << "Please input the amount of money you'd like to put:\n";
    std::cin >> money;
    Bank.putMoney(clientID, money);
}

void SystemUtility::takeMoney(const std::string &bank, int clientID){
    auto& Bank = getBank(bank);
    long money;
    std::cout << "Please input the amount of money you'd like to take:\n";
    std::cin >> money;
    Bank.takeMoney(clientID, money);
}

void SystemUtility::print(){
    for(auto& i : banks) {
        std::cout << "Bank: " << i.first << "\n";
        i.second.printAll();
    }
}

void SystemUtility::cancelOperation(const std::string &bank, int ID){
    auto& Bank = getBank(bank);
    Bank.cancel(ID);
}
