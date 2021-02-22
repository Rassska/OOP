#include "AccountFactory/DepositAccountFactory.h"

#include "DepositAccount.h"

DepositAccountFactory::DepositAccountFactory() {};

Account* DepositAccountFactory::createAccount() {
    Account* temp = new DepositAccount();
    
    return temp;
};
DepositAccountFactory::~DepositAccountFactory() = default;