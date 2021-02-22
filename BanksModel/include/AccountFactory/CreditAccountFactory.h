#pragma once
#include "Account.h"
#include "AccountFactory.h"
#include <iostream>

class CreditAccountFactory : public AccountFactory
{
private:
    
public:
    CreditAccountFactory();
    Account* createAccount() override;
    ~CreditAccountFactory();
};