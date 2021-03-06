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

void Bank::createAccount(Client* client, Account* account) {
    client->createAccount(account);
    account->setCommisionPercent(m_creditCommisionPercent);
    account->setInterestPercent(m_debitPercent);
    m_clientDataBase.push_back(client);
}

void Bank::createTransaction(Account *account, Transaction* transaction) {
    transaction->doo(account);
}

void Bank::cancelTransaction(Account* account, Transaction* transaction) {
    transaction->undo(account);
}

void Bank::calculateInterestOrCommission(time_t currTime) {
    
    for (std::size_t i = 0; i < m_clientDataBase.size(); i++) {
        for (std::size_t j = 0; j < m_clientDataBase[i]->getAccountsList().size(); j++) {
            m_clientDataBase[i]->getAccountsList()[j]->calculateInterest(currTime);
        }
    }
}
Bank::~Bank() = default;