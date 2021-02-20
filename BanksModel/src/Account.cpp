#include <iostream>
#include <vector>
#include <string>
#include "Account.h"



std::size_t Account::m_accountId = 0;
Account::Account() {
    m_accountId++;
}

void transferTransaction(){};
void WithdrawalTransaction(){};
void DepositTransaction(){};
void setCommisionPercent(double currCommision){};
void setBaseAmountOfMoney(double currAmountOfMoney){};

Account::~Account() = default;