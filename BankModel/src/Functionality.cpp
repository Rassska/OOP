#include <iostream>
#include "Functionality.h"
#include "Bank.h"
#include "Customer.h"
#include "Account.h"


void Functionality::addBank(const std::string &name, long moneyLimit, long suspLimit, double p, double c){
    Bank banka(moneyLimit, suspLimit, p, c);
    auto pr = std::make_pair(name, banka);
    banks.insert(pr);
}

void Functionality::addCustomer(const std::string& bank, Customer* customer){
    auto& Bank = getBank(bank);
    Bank.addCustomer(customer);
}

void Functionality::addAccount(const std::string &bank, int customerID, const std::string& accountName){
    auto& Bank = getBank(bank);
    Bank.addAccount(customerID, accountName);
}

void Functionality::printBank(){
    for(auto& i : banks) {
        i.second.dailyIR();
        i.second.monthlyIR();
        std::cout << i.first << "\n";
        i.second.printCustomers();
        std::cout << "And some accounts...\n";
        i.second.printAccounts();
    }
}

void Functionality::transferMoney(const std::string &bank, int customerID, int customerID2){
    auto& Bank = getBank(bank);
    Bank.transferMoney(customerID, customerID2);
}

void Functionality::putMoney(const std::string &bank, int customerID){
    auto& Bank = getBank(bank);
    long money;
    std::cout << "Please input the amount of money you'd like to put:\n";
    std::cin >> money;
    Bank.putMoney(customerID, money);
}

void Functionality::takeMoney(const std::string &bank, int customerID){
    auto& Bank = getBank(bank);
    long money;
    
    std::cout << "Please input the amount of money you'd like to take:\n";
    std::cin >> money;
    Bank.takeMoney(customerID, money);
}

void Functionality::print(){
    for(auto& i : banks) {
        std::cout << "Bank: " << i.first << "\n";
        i.second.printAll();
    }
}

void Functionality::cancelOperation(const std::string &bank, int ID){
    auto& Bank = getBank(bank);
    Bank.cancel(ID);
}

Bank& Functionality::getBank(const std::string &bank){
    for(std::map<std::string, Bank>::iterator i = banks.begin(); i != banks.end(); ++i)
        if(bank == i->first) return i->second; // bank!
    throw std::runtime_error("Error! Could not find bank within the function Functionality::getBank().\n");
}