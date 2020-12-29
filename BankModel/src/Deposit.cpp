#include <iostream>
#include "Deposit.h"


void Deposit::setCommission(double comm){
    if(comm != 1) throw std::runtime_error("Error! Deposit account cannot have commision within function Deposit::setCommission().\n");
    this->commission = comm; // no commission
}

void Deposit::setInterestRate(double IR){ // depends on money
    if(this->money_ < 500) this->interestRate = IR / 365;
    if(this->money_ >= 500 && this->money_ < 1000) this->interestRate = (IR + 0.5) / 365;
    if(this->money_ >= 1000 && this->money_ < 5000) this->interestRate = (IR + 1) / 365;
    if(this->money_ > 5000) this->interestRate = (IR + 1.5) / 365;
}

Deposit::Deposit(double ir, long money, int count, Date finalDate){
    this->thisAccountID = count;
    this->nameAccount = "deposit";
    this->setCommission(1);
    this->money_ = money;
    this->setInterestRate(ir);
    this->time_ = finalDate;
}

void Deposit::takeMoney(long money){
    Date now = Date::getNow();
    if(time_ < now) Account::takeMoney(money);
    else throw std::runtime_error("Error! Cannot take money from Deposit account before time limit within the function Deposit::takeMoney().\n");
}

void Deposit::putMoney(long money){
    Account::putMoney(money);
}

void Deposit::transferMoney(Account* ac, long money){
    Date now = Date::getNow();
    if(time_ < now) Account::transferMoney(ac, money);
    else throw std::runtime_error("Error! Cannot transfer money from Deposit account before time limit within the function Deposit::transferMoney().\n");
}

void Deposit::addIRDay(){
    this->pocket += money_ * interestRate;
}

void Deposit::addIRMonth(){
    this->money_ += this->pocket;
}