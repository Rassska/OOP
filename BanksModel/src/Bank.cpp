#include <iostream>
#include <vector>
#include <string>
#include "Bank.h"


Bank::Bank() = default;

Bank::Bank(std::string_view bankName, double debitPercent, double depositPercent, double creditCommission, double doubtLimit) :
    m_bankName(bankName), m_debitPercent(debitPercent), m_depositPercent(depositPercent), m_creditCommisionPercent(creditCommission), m_doubtLimit(doubtLimit) {}


void Bank::addClient(Client* client) {
    m_clientDataBase.push_back(client);
}

void Bank::createAccount(Client* client, Account* account, double baseAmountOfMoney) {
    client->createAccount(account);
    account->setBaseAmountOfMoney(baseAmountOfMoney);
    account->setCommisionPercent(m_creditCommisionPercent);
    account->setInterestPercent(m_debitPercent);
}
Bank::~Bank() = default;