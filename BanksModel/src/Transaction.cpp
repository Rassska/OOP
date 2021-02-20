#include "Transaction.h"
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

Transaction::Transaction() = default;


void Transaction::doo(double amountOfMoney, Account* account){};
void Transaction::undo(double amountOfMoney, Account* account) {};

Transaction::~Transaction() = default;