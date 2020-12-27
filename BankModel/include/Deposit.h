#pragma once 
#include "Date.h"
#include "Account.h"

class Deposit : public Account {
protected:
    Date time_;
    
    double pocket;
public:
    Deposit(double ir, long money, int count, Date date);
    
    void setInterestRate(double IR) override;
    void setCommission(double comm) override;
    void addIRDay() override;
    void addIRMonth() override;
    
    void takeMoney(long money) override;
    void putMoney(long money) override;
    void transferMoney(Account* ac, long money) override;
};