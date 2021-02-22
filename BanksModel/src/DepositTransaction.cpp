#include "DepositTransaction.h"
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

DepositTransaction::DepositTransaction(double amountOfDepositMoney, time_t transactionCreatedTime) : 
    m_amountOfDepositMoney(amountOfDepositMoney), m_transactionCreatedTime(transactionCreatedTime)
{}


void DepositTransaction::doo(Account* account){
    account->DepositTransaction(m_transactionCreatedTime, m_amountOfDepositMoney);
}
void DepositTransaction::undo(Account* account) {
    account->DepositTransaction(m_transactionCreatedTime, -m_amountOfDepositMoney);
}

DepositTransaction::~DepositTransaction() = default;