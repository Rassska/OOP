#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

class Account
{
private:
    static std::size_t m_accountId;

public:
    Account();
    virtual void transferTransaction(time_t currTime, Account* ToTrasferAccount, double amountOfMoneyToTransfer);
    virtual void WithdrawalTransaction(time_t currTime, double amountOfMoneyToWithdrawal);
    virtual void DepositTransaction(time_t currTime, double amountOfMoneyToDeposit);
    
    virtual void setCommisionPercent(double currCommision);
    virtual void setInterestPercent(double currPercent);

    ~Account();
};

