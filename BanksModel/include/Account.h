#pragma once
#include <iostream>
#include <vector>
#include <string>


class Account
{
private:
    static std::size_t m_accountId;

public:
    Account();
    virtual void transferTransaction();
    virtual void WithdrawalTransaction();
    virtual void DepositTransaction();
    
    virtual void setCommisionPercent(double currCommision);
    virtual void setInterestPercent(double currPercent);
    virtual void setBaseAmountOfMoney(double currAmountOfMoney);
    ~Account();
};

