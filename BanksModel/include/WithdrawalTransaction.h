#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Transaction.h"

class WithdrawalTransaction : public Transaction
{
private:
    double m_amountOfWithdrawalMoney;
    time_t m_transactionCreatedTime;
public:
    WithdrawalTransaction(double amountOfWithdrawalMoney, time_t transactionCreatedTime);
    void doo(Account* account) override;
    void undo(Account* account) override;
    ~WithdrawalTransaction();
};