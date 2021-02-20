#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

class CreditAccount : public Account
{
private:
    double m_currentAmount;
    double m_commision;
    double m_interestPercent;
public:
    CreditAccount();
    void setCommisionPercent(double currCommision) override;
    void setInterestPercent(double currPercent) override;
    void setBaseAmountOfMoney(double currAmountOfMoney) override;

    void transferTransaction() override;
    void WithdrawalTransaction() override;
    void DepositTransaction() override;

    ~CreditAccount();
};