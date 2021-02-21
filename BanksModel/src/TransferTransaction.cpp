#include "TransferTransaction.h"
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

TransferTransaction::TransferTransaction(double amountOfTrasferMoney, Account* account, time_t transactionCreatedTime) : 
    m_amountOfTrasferMoney(amountOfTrasferMoney), m_account(account), m_transactionCreatedTime(transactionCreatedTime)
{}


void TransferTransaction::doo(Account* account){
    account->transferTransaction();
}
void TransferTransaction::undo(Account* account) {
    
}

TransferTransaction::~TransferTransaction() = default;