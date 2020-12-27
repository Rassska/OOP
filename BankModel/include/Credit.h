#pragma once

#include "Account.h"

class Credit : public Account {
protected:
    long creditLimit;
public:
    Credit(double comm, int count, long limit);
    
    void setInterestRate(double IR) override;
    void setCommission(double comm) override;
    void addIRDay() override;
    void addIRMonth() override;
    
    void takeMoney(long money) override;
    void putMoney(long money) override;
    void transferMoney(Account* ac, long money) override;
    
    bool isCredLim_valid();
};