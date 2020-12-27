#pragma once
#include "Account.h"

class Debit : public Account {
protected:
    double pocket;
public:
    Debit(double ir, int count);
    
    void setInterestRate(double IR) override;
    void setCommission(double comm) override;
    void addIRDay() override;
    void addIRMonth() override;

    void takeMoney(long money) override;
    void putMoney(long money) override;
    void transferMoney(Account* ac, long money) override;
};