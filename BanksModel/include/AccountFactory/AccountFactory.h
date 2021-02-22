#pragma once
#include "Account.h"

class AccountFactory
{
private:
    
public:
    AccountFactory();
    virtual Account* createAccount();
    ~AccountFactory();
};

