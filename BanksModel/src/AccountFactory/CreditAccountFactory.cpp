#include "AccountFactory/CreditAccountFactory.h"
#include "CreditAccount.h"


CreditAccountFactory::CreditAccountFactory() {};

Account* CreditAccountFactory::createAccount() {
    Account* temp = new CreditAccount();
    return temp;
};
CreditAccountFactory::~CreditAccountFactory() = default;