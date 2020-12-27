#pragma once
#include "Command.h"
#include "Account.h"

class Take : public Command{
private:
    Account* acc_;
    long money_;
public:
    Take(int id, Account* a, long money);
    void run() const override;
    void undo() const override;
};