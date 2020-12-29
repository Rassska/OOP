#include <iostream>
#include "Take.h"

Take::Take(int id, Account* a, long money){
    commandID = id;
    acc_ = a;
    money_ = money;
}

void Take::run() const{
    acc_->takeMoney(money_);
}

void Take::undo() const{
    acc_->putMoney(money_);
}