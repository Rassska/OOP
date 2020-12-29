#include <iostream>
#include "Debit.h"


void Debit::setCommission(double comm){
    if(comm != 1) throw std::runtime_error("Error! Debit account cannot have commision within function Debit::setCommission().\n");
    this->commission = comm; // no commission
}

void Debit::setInterestRate(double IR){
    this->interestRate = IR / 365; // fixed
}

Debit::Debit(double ir, int count){
    this->thisAccountID = count;
    this->nameAccount = "debit";
    this->setCommission(1);
    this->money_ = 0;
    this->setInterestRate(ir);
}

void Debit::takeMoney(long money) {
    Account::takeMoney(money);
}

void Debit::putMoney(long money){
    Account::putMoney(money);
}

void Debit::transferMoney(Account* ac, long money){
    Account::transferMoney(ac, money);
}

void Debit::addIRDay(){
    this->pocket += money_ * interestRate;
}

void Debit::addIRMonth(){
    this->money_ += this->pocket;
}
