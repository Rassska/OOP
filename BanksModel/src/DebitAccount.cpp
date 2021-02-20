#include <iostream>
#include <vector>
#include <string>
#include "DebitAccount.h"


DebitAccount::DebitAccount() = default;

void DebitAccount::setCommisionPercent(double currCommision) {
    m_commision = 0;
}

void DebitAccount::setInterestPercent(double currInterestPercent) {
    m_interestPercent = currInterestPercent;
}

void DebitAccount::setBaseAmountOfMoney(double currAmountOfMoney) {
    m_currentAmount = currAmountOfMoney;
}



DebitAccount::~DebitAccount() = default;