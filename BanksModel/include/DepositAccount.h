#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"
#include <time.h>

class DepositAccount : public Account
{
private:
    
    double m_currentAmount;
    double m_currentFrozenAmount;
    double m_commision;
    double m_interestPercent;
    time_t m_depositTime;

public:
    DepositAccount();
    
    void setCommisionPercent(double currCommision) override;
    void setInterestPercent(double currPercent) override;
    

    void transferTransaction(time_t currTime, Account* ToTrasferAccount, double amountOfMoneyToTransfer) override;
    void WithdrawalTransaction(time_t currTime, double amountOfMoneyToWithdrawal) override;
    void DepositTransaction(time_t currTime, double amountOfMoneyToDeposit) override;
    void calculateInterest(time_t currTime) override;
    
    double getAmountOfMoney() const override;
    double getInterestPercent() const override;

    ~DepositAccount();
};

