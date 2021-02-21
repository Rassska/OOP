#include <iostream>
#include <vector>
#include <string>
#include "Account.h"



std::size_t Account::m_accountId = 0;
Account::Account() {
    m_accountId++;
}

void Account::transferTransaction(time_t currTime, Account* ToTrasferAccount, double amountOfMoneyToTransfer){};
void Account::WithdrawalTransaction(time_t currTime, double amountOfMoneyToWithdrawal){};
void Account::DepositTransaction(time_t currTime, double amountOfMoneyToDeposit){};

void Account::setCommisionPercent(double currCommision){};
void Account::setInterestPercent(double currPercent){};

Account::~Account() = default;