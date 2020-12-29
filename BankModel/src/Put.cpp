#include "Put.h"
#include <iostream>

Put::Put(int id, Account* a, long money){
    commandID = id;
    acc_ = a;
    money_ = money;
}

void Put::run() const{
    acc_->putMoney(money_);
}

void Put::undo() const{
    acc_->takeMoney(money_);
}