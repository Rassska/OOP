#include "Transaction.h"
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

Transaction::Transaction() = default;


void Transaction::doo(Account* account){};
void Transaction::undo(Account* account) {};

Transaction::~Transaction() = default;