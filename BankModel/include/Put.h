#pragma once
#include "Account.h"
#include "Command.h"

class Put : public Command{
private:
    Account* acc_;
    long money_;
public:
    Put(int id, Account* a, long money);
    void run() const override;
    void undo() const override;
};