#include "WithdrawalTransaction.h"
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

WithdrawalTransaction::WithdrawalTransaction(double amountOfWithdrawalMoney, time_t transactionCreatedTime) : 
    m_amountOfWithdrawalMoney(amountOfWithdrawalMoney), m_transactionCreatedTime(transactionCreatedTime)
{}


void WithdrawalTransaction::doo(Account* account){
    
}
void WithdrawalTransaction::undo(Account* account) {
    
}

WithdrawalTransaction::~WithdrawalTransaction() = default;