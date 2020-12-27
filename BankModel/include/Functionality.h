#pragma once 
#include <map>
#include "Bank.h"

class Functionality {
private:
    std::map<std::string, Bank> banks;
public:
    void addBank(const std::string& name, long moneyLimit, long suspLimit, double percentage, double commission);
    void addClient(const std::string& bank, Customer* client);
    void addAccount(const std::string& bank, int clientID, const std::string& accountName);
    
    void putMoney(const std::string& bank, int clientID);
    void transferMoney(const std::string& bank, int clientID, int clientID2);
    void takeMoney(const std::string& bank, int clientID);
    
    void cancelOperation(const std::string &bank, int ID);
    
    std::map<std::string, Bank> getBanks();
    Bank& getBank(const std::string& bank);
    void printBank();
    void print();
};