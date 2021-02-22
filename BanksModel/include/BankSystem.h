#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Bank.h"
#include "Client.h"
#include "Account.h"
class BankSystem
{
private:
    std::vector<Bank*> m_BanksList;
public:
    BankSystem();
    void addBank(Bank* bank);
    void addClient(Bank* bank, Client* client);
    void createAccount(Bank* bank, Client* client, Account* account);
    void createTransaction(Bank* bank, Account* account, Transaction* transaction);
    void cancelTransaction(Bank* bank, Account* account, Transaction* transaction);
    void calculateInterestOrCommission(Bank* bank, time_t currTime);
    ~BankSystem();
};
