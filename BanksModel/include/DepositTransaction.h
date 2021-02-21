#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Transaction.h"


class DepositTransaction : public Transaction
{
private:
    double m_amountOfDepositMoney;
    time_t m_transactionCreatedTime;
public:
    DepositTransaction(double amountOfDepositMoney, time_t transactionCreatedTime);
    void doo(Account* account) override;
    void undo(Account* account) override;
    ~DepositTransaction();
};