#include <iostream>
#include "Account.h"

Account::Account() = default;

int Account::getAccountID() const {
    return thisAccountID;
}

double Account::getCommission() const {
    return commission;
}

double Account::getInterestRate() const {
    return interestRate;
}

std::string Account::getNameAccount() const {
    return nameAccount;
}

bool Account::isSuspicious() const{
    return suspicious;
}

long Account::getMoneyAccount() const{
    return money_;
}

void Account::setSuspicious(bool var){
    this->suspicious = var;
}

void Account::takeMoney(long money){
    if(money_ >= money && money > 0) money_ -= money;
    else throw std::runtime_error("Error! Impossible to take such amount from the account within the function Account::takeMoney().\n");
}

void Account::putMoney(long money){
    money_ += money;
}

void Account::transferMoney(Account *ac, long money){
    this->takeMoney(money);
    ac->putMoney(money);
}