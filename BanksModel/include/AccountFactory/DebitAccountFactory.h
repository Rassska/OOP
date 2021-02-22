#pragma once
#include "Account.h"
#include "AccountFactory.h"
#include <iostream>

class DebitAccountFactory : public AccountFactory
{
private:
    
public:
    DebitAccountFactory();
    Account* createAccount() override;
    ~DebitAccountFactory();
};