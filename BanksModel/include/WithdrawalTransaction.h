#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Transaction.h"

class WithdrawalTransaction : public Transaction
{
private:
    double m_amountOfWithdrawalMoney;
public:
    WithdrawalTransaction(double amountOfWithdrawalMoney);
    void doo(double amountOfMoney, Account* account) override;
    void undo(double amountOfMoney, Account* account) override;
    ~WithdrawalTransaction();
};