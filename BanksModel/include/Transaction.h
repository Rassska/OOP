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
    virtual void doo(double amountOfMoney, Account* account);
    virtual void undo(double amountOfMoney, Account* account);
    ~Transaction();
};

