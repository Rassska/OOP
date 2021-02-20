#include <iostream>
#include <vector>
#include <string>
#include "CreditAccount.h"


CreditAccount::CreditAccount() = default;

void CreditAccount::setCommisionPercent(double currCommision) {
    m_commision = currCommision;
}

void CreditAccount::setInterestPercent(double currPercent) {
    m_interestPercent = 0;
}
void CreditAccount::setBaseAmountOfMoney(double currAmountOfMoney) {
    m_currentAmount = 5000 + currAmountOfMoney;
}


CreditAccount::~CreditAccount() = default;

