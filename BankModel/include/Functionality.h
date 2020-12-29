#pragma once 
#include <map>
#include "Bank.h"

class Functionality {
private:
    std::map<std::string, Bank> banks;
public:
    void addBank(const std::string& name, long moneyLimit, long suspLimit, double percentage, double commission);
    void addCustomer(const std::string& bank, Customer* customer);
    void addAccount(const std::string& bank, int customerID, const std::string& accountName);
    
    void putMoney(const std::string& bank, int customerID);
    void transferMoney(const std::string& bank, int customerID, int customerID2);
    void takeMoney(const std::string& bank, int customerID);
    
    void cancelOperation(const std::string &bank, int ID);
    
    std::map<std::string, Bank> getBanks();
    Bank& getBank(const std::string& bank);
    void printBank();
    void print();
};