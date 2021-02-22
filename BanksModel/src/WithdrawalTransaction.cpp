#include "WithdrawalTransaction.h"
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

WithdrawalTransaction::WithdrawalTransaction(double amountOfWithdrawalMoney, time_t transactionCreatedTime) : 
    m_amountOfWithdrawalMoney(amountOfWithdrawalMoney), m_transactionCreatedTime(transactionCreatedTime)
{}


void WithdrawalTransaction::doo(Account* account){
    account->WithdrawalTransaction(m_transactionCreatedTime, m_amountOfWithdrawalMoney);
}
void WithdrawalTransaction::undo(Account* account) {
    account->WithdrawalTransaction(m_transactionCreatedTime, -m_amountOfWithdrawalMoney);
}

WithdrawalTransaction::~WithdrawalTransaction() = default;