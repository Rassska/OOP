#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Transaction.h"


class DepositTransaction : public Transaction
{
private:
    double m_amountOfDepositMoney;
public:
    DepositTransaction(double amountOfDepositMoney);
    void doo(double amountOfMoney, Account* account) override;
    void undo(double amountOfMoney, Account* account) override;
    ~DepositTransaction();
};