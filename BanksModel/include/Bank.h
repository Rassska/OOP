#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Client.h"
#include "Account.h"
class Bank
{
private:
    std::string_view m_bankName;
    double m_debitPercent;
    double m_depositPercent;
    double m_creditCommisionPercent;
    double m_doubtLimit;
    std::vector<Client*> m_clientDataBase;
public:
    Bank();
    Bank(std::string_view bankName, double debitPercent, double depositPercent, double creditCommission, double doubtLimit);
    void addClient(Client* client);
    void createAccount(Client* client, Account* account, double baseAmountOfMoney);
    ~Bank();
};
