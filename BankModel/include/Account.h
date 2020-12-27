#pragma once 
#include <string>

class Account{
protected:
    std::string nameAccount;
    int thisAccountID;
    double commission;
    double interestRate;
    long money_;
    bool suspicious;
public:
    Account();
    
    int getAccountID() const;
    double getCommission() const;
    double getInterestRate() const;
    std::string getNameAccount() const;
    std::string getNameAccountString() const;
    long getMoneyAccount() const;
    bool isSuspicious() const;
    
    void setSuspicious(bool var);
    virtual void setInterestRate(double IR) = 0;
    virtual void setCommission(double comm) = 0;
    virtual void addIRDay() = 0;
    virtual void addIRMonth() = 0;
    
    virtual void takeMoney(long money);
    virtual void putMoney(long money);
    virtual void transferMoney(Account* ac, long money);
};