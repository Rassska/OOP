#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

std::size_t Account::m_accountGeneralId = 0;

Account::Account(){
    m_accountId = m_accountGeneralId;
    m_accountGeneralId++;
};

void Account::transferTransaction(time_t currTime, Account* ToTrasferAccount, double amountOfMoneyToTransfer){};
void Account::WithdrawalTransaction(time_t currTime, double amountOfMoneyToWithdrawal){};
void Account::DepositTransaction(time_t currTime, double amountOfMoneyToDeposit){};

void Account::setCommisionPercent(double currCommision){};
void Account::setInterestPercent(double currPercent){};

double Account::getAmountOfMoney() const{return 0;};
std::size_t Account::getAccountId() const {return m_accountId;};
double Account::getInterestPercent() const {return 0;}
void Account::calculateInterest(time_t currTime) {};
Account::~Account() = default;