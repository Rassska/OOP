#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Transaction.h"

class TransferTransaction : public Transaction
{
private:
    
public:
    TransferTransaction();
    void doo(double amountOfMoney, Account* account) override;
    void undo(double amountOfMoney, Account* account) override;
    ~TransferTransaction();
};