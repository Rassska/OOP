#include "WithdrawalTransaction.h"
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

WithdrawalTransaction::WithdrawalTransaction(double amountOfWithdrawalMoney) : 
    m_amountOfWithdrawalMoney(amountOfWithdrawalMoney)
{}


void WithdrawalTransaction::doo(double amountOfMoney, Account* account){
    
}
void WithdrawalTransaction::undo(double amountOfMoney, Account* account) {
    
}

WithdrawalTransaction::~WithdrawalTransaction() = default;