#include <iostream>
#include <vector>
#include <string>
#include "BankSystem.h"
#include "Client.h"

BankSystem::BankSystem() = default;

void BankSystem::addBank(Bank* bank) {
    m_BanksList.push_back(bank);
}
void BankSystem::addClient(Bank* bank, Client* client) {
    bank->addClient(client);
}
void BankSystem::createAccount(Bank* bank, Client* client, Account* account) {
    bank->createAccount(client, account);
}
void BankSystem::createTransaction(Bank* bank, Account* account, Transaction* transaction) {
    bank->createTransaction(account, transaction);
}
void BankSystem::cancelTransaction(Bank* bank, Account* account, Transaction* transaction) {
    bank->cancelTransaction(account, transaction);
}
void BankSystem::calculateInterestOrCommission(Bank* bank, time_t currTime) {
    
}
BankSystem::~BankSystem() = default;
