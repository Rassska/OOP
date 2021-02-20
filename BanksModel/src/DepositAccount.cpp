#include <iostream>
#include <vector>
#include <string>
#include "DepositAccount.h"


DepositAccount::DepositAccount() = default;

void DepositAccount::setCommisionPercent(double currCommision) {
    m_commision = 0;
}

void DepositAccount::setBaseAmountOfMoney(double currAmountOfMoney) {
    m_currentAmount = currAmountOfMoney;
}

void DepositAccount::setInterestPercent(double currPercent) {
    if (m_currentAmount < 50000) {
        m_interestPercent = 0.03;
    } else if (m_currentAmount >= 50000 && m_currentAmount < 100000) {
        m_interestPercent = 0.05;
    } else if (m_currentAmount >= 100000 && m_currentAmount < 500000) {
        m_interestPercent = 0.07;
    } else {
        m_interestPercent = 0.1;
    }
}


DepositAccount::~DepositAccount() = default;