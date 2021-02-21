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
void BankSystem::createAccount(Bank* bank, Client* client, Account* account, double baseAmountOfMoney) {
    bank->createAccount(client, account, baseAmountOfMoney);
}
void BankSystem::createTransaction(Bank* bank, Client* client, Account* account, Transaction* transaction) {
    bank->createTransaction(client, account, transaction);
}
BankSystem::~BankSystem() = default;
