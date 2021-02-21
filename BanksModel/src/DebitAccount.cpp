#include <iostream>
#include <vector>
#include <string>
#include "DebitAccount.h"
#include "Account.h"

DebitAccount::DebitAccount() = default;

void DebitAccount::setCommisionPercent(double currCommision) {
    m_commision = 0;
}

void DebitAccount::setInterestPercent(double currInterestPercent) {
    m_interestPercent = currInterestPercent;
}

void DebitAccount::DepositTransaction(time_t currTime, double amountOfDepositMoney) {
    m_currentAmount += amountOfDepositMoney;
}
void DebitAccount::transferTransaction(time_t currTime, Account* ToTrasferAccount, double amountOfMoneyToTransfer) {
    if (m_currentAmount >= amountOfMoneyToTransfer) {
        ToTrasferAccount->DepositTransaction(currTime, amountOfMoneyToTransfer);
        m_currentAmount -= amountOfMoneyToTransfer;
    } else {
        throw std::runtime_error("The requested amount is higher than the balance!");
    }
}

void DebitAccount::WithdrawalTransaction(time_t currTime, double amountOfMoneyToWithdrawal) {
    if (m_currentAmount >= amountOfMoneyToWithdrawal) {
        m_currentAmount -= amountOfMoneyToWithdrawal;
    } else {
        throw std::runtime_error("The requested amount is higher than the balance!");
    }
}


DebitAccount::~DebitAccount() = default;