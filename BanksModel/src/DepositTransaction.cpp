#include "DepositTransaction.h"
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

DepositTransaction::DepositTransaction() = default;


void DepositTransaction::doo(double amountOfMoney, Account* account){
    account->
}
void DepositTransaction::undo(double amountOfMoney, Account* account) {
    account->m_currentAmount -= amountOfMoney;
}

DepositTransaction::~DepositTransaction() = default;