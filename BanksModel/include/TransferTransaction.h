#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Transaction.h"
#include "Account.h"

class TransferTransaction : public Transaction
{
private:
    double m_amountOfTransferMoney;
    Account* m_account;
    time_t m_transactionCreatedTime;
public:
    TransferTransaction(double amountOfTransferMoney, Account* account, time_t transactionCreatedTime);
    void doo(Account* account) override;
    void undo(Account* account) override;
    ~TransferTransaction();
};