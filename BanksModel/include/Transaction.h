#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

class Transaction
{
private:
    
public:
    Transaction();
    virtual void doo(Account* account);
    virtual void undo(Account* account);
    ~Transaction();
};

