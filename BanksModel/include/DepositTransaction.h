#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Transaction.h"


class DepositTransaction : public Transaction
{
private:
    
public:
    DepositTransaction();
    void doo(double amountOfMoney, Account* account) override;
    void undo(double amountOfMoney, Account* account) override;
    ~DepositTransaction();
};