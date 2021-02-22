#include "AccountFactory/DebitAccountFactory.h"
#include "DebitAccount.h"

DebitAccountFactory::DebitAccountFactory() {};

Account* DebitAccountFactory::createAccount() {
    Account* temp = new DebitAccount();
    
    return temp;
};
DebitAccountFactory::~DebitAccountFactory() = default;