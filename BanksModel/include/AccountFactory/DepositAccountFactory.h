#pragma once
#include "Account.h"
#include "AccountFactory.h"
#include <iostream>

class DepositAccountFactory : public AccountFactory
{
private:
    
public:
    DepositAccountFactory();
    Account* createAccount() override;
    ~DepositAccountFactory();
};