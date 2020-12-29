#include <iostream>
#include "Transfer.h"

Transfer::Transfer(int id, Account* a, Account* a2, long money){
    commandID = id;
    acc_ = a;
    money_ = money;
    acc2_ = a2;
}

void Transfer::run() const{
    acc_->transferMoney(acc2_, money_);
}

void Transfer::undo() const{
    acc2_->transferMoney(acc_, money_);
}