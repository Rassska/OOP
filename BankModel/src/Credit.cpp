#include "Credit.h"
#include <iostream>

void Credit::setCommission(double comm){
    this->commission = comm;
}

void Credit::setInterestRate(double IR){
    if(IR != 1) throw std::runtime_error("Error! Credit account cannot have interest rate within function Credit::setInterestRate().\n");
    this->interestRate = IR;
}

Credit::Credit(double ir, int count, long limit){
    this->creditLimit = limit;
    this->thisAccountID = count;
    this->nameAccount = "credit";
    this->setCommission(ir); // this is commission!
    this->money_ = 0;
    this->setInterestRate(1);
}

bool Credit::isCredLim_valid(){
    return ((creditLimit >= 0)? true : false);
}

void Credit::takeMoney(long money){
    if(this->money_ >= money) Account::takeMoney(money);
    else{
        if(isCredLim_valid()){
            if(this->money_ - money < 0){
                if(creditLimit < abs(this->money_ - money)) {
                    throw std::runtime_error("Error! Credit account exceeded the limit within the function Credit::takeMoney().\n");
                }
                else {
                    long temp = money - this->money_;
                    this->money_ = 0;
                    creditLimit -= temp * commission + temp;
                    std::cout << "Warning! You are wasting credit limit! Right now it's: " << creditLimit << ".\n" ;
                }
            }
            else Account::takeMoney(money);
        } else throw std::runtime_error("Error! Credit limit exceeded, operation unable within the function Credit::takeMoney().\n");
    }
}

void Credit::putMoney(long money){
    long temp;
    if(!isCredLim_valid()){
        temp = money + creditLimit;
        creditLimit += (int)money - (int)temp;
        if(temp > 0) Account::putMoney(temp);
    } else {Account::putMoney(money);}
}

void Credit::transferMoney(Account* ac, long money){
    Account::transferMoney(ac, money);
}

void Credit::addIRDay(){}
void Credit::addIRMonth(){}