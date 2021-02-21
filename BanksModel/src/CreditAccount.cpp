#include <iostream>
#include <vector>
#include <string>
#include "CreditAccount.h"


CreditAccount::CreditAccount() {
    m_currentAmount = 5000;
}

void CreditAccount::setCommisionPercent(double currCommision) {
    m_commision = currCommision;
}

void CreditAccount::setInterestPercent(double currPercent) {
    m_interestPercent = 0;
}

void CreditAccount::transferTransaction(time_t currTime, Account* ToTrasferAccount, double amountOfMoneyToTransfer){
    if (m_currentAmount > amountOfMoneyToTransfer) {
        ToTrasferAccount->DepositTransaction(amountOfMoneyToTransfer);
        m_currentAmount -= amountOfMoneyToTransfer;
    } else {
        throw std::runtime_error("Credit limit exceeded to transfer!");
    }
    
}
void CreditAccount::DepositTransaction(time_t currTime, double amountOfMoneyToDeposit){
    m_currentAmount += amountOfMoneyToDeposit;
}
void CreditAccount::WithdrawalTransaction(time_t currTime, double amountOfMoneyToWithdrawal){
    if (m_currentAmount > amountOfMoneyToWithdrawal) {
        m_currentAmount -= amountOfMoneyToWithdrawal;
    } else {
        throw std::runtime_error("Credit limit exceeded to Withdrawal!");
    }
}



CreditAccount::~CreditAccount() = default;

