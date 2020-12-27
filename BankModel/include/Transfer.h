#pragma once 
#include "Command.h"
#include "Account.h"

class Transfer : public Command{
private:
    Account* acc_;
    Account* acc2_;
    long money_;
public:
    Transfer(int id, Account* a, Account* a2, long money);
    void run() const override;
    void undo() const override;
};