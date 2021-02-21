#include "TransferTransaction.h"
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

TransferTransaction::TransferTransaction(double amountOfTrasferMoney) : 
    m_amountOfTrasferMoney(amountOfTrasferMoney)
{}


void TransferTransaction::doo(double amountOfMoney, Account* account){

}
void TransferTransaction::undo(double amountOfMoney, Account* account) {
    
}

TransferTransaction::~TransferTransaction() = default;