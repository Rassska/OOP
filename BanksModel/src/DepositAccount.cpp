#include <iostream>
#include <vector>
#include <string>
#include "DepositAccount.h"
#include "ctime"

DepositAccount::DepositAccount() = default;

void DepositAccount::setCommisionPercent(double currCommision) {
    m_commision = 0;
}

void DepositAccount::setInterestPercent(double currPercent) {
    m_interestPercent = 0;
}

void DepositAccount::DepositTransaction(time_t currTime, double amountOfDepositMoney) {
    m_currentAmount += amountOfDepositMoney;
    m_depositTime = std::time(nullptr) + 1000;

     if (m_currentAmount > 0 && m_currentAmount < 50000) {
        m_interestPercent = 0.03;
    } else if (m_currentAmount >= 50000 && m_currentAmount < 100000) {
        m_interestPercent = 0.05;
    } else if (m_currentAmount >= 100000 && m_currentAmount < 500000) {
        m_interestPercent = 0.07;
    } else if (m_currentAmount >= 500000) {
        m_interestPercent = 0.1;
    } else {
        std::runtime_error("Smth happened with m_interestPercent settings for DepositAccount!");
    }

}
void DepositAccount::transferTransaction(time_t currTime, Account* ToTrasferAccount, double amountOfMoneyToTransfer) {
    if (m_currentAmount >= amountOfMoneyToTransfer) {
        if (m_depositTime <= currTime) {
            ToTrasferAccount->DepositTransaction(currTime, amountOfMoneyToTransfer);
            m_currentAmount -= amountOfMoneyToTransfer;
        } else {
            throw std::runtime_error("The time of the deposit has not expired!");
        }
    } else {
        throw std::runtime_error("The requested amount is higher than the balance!");
    }
}

void DepositAccount::WithdrawalTransaction(time_t currTime, double amountOfMoneyToWithdrawal) {
    if (m_currentAmount >= amountOfMoneyToWithdrawal) {
        if (m_depositTime <= currTime) {
            m_currentAmount -= amountOfMoneyToWithdrawal;
        } else {
            throw std::runtime_error("The time of the deposit has not expired!");
        }
    } else {
        throw std::runtime_error("The requested amount is higher than the balance!");
    }
}
double DepositAccount::getAmountOfMoney() const {
    return m_currentAmount;
}

void DepositAccount::calculateInterest(time_t currTime) {
    m_currentFrozenAmount += currTime / 100 * m_interestPercent / 365;
}


double DepositAccount::getInterestPercent() const {return m_interestPercent;}
DepositAccount::~DepositAccount() = default;