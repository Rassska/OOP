#pragma once 
#include <vector>
#include <map>
#include "Account.h"
#include "Customer.h"
#include "Command.h"

class Bank{
private:
    static int bankID;
    int thisBankID;
    std::map<int, std::vector<Account*>> accounts;
    std::vector<Customer*> clients;
    std::map<int,Command*> commands;
    
    double percentage;
    double commission;
    long moneyLimit;
    long suspLimit;
    time_t timeB_;
public:
    Bank(long moneyLimit, long suspLimit, double percentage, double commission);
    
    int getBankID();
    double getPerc();
    double getComm();
    long getMoneyLim();
    std::vector<Customer*> getClients();
    std::vector<Account*> getAccounts(int cID);
    
    int setCommandID();
    
    void addClient(Customer* client);
    void addAccount(int clientID, std::size_t val);
    
    void transferMoney(int cID, int cID2);
    void putMoney(int cID, long money);
    void takeMoney(int cID, long money);
    
    void command(Command* c);
    void cancel(int ID);
    
    void CheckUpdateSusp(int clientID, Account* acc);
    void dailyIR();
    void monthlyIR();
    
    bool isClient(int clientID);
    void printClients();
    void printAccounts();
    void printAll();
};