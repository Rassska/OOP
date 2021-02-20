#include <iostream>
#include "BankSystem.h"
#include "Bank.h"
#include "Account.h"
#include "Client.h"
#include "CreditAccount.h"
#include "DepositAccount.h"
#include "DebitAccount.h"
#include "DepositTransaction.h"
#include "Transaction.h"
#include "TransferTransaction.h"
#include "WithdrawalTransaction.h"

const double baseAmountOfMoney = 5000;




int main () {

    try {
        BankSystem* currBankChain = new BankSystem();
        Bank* currBank = new Bank("Bank of America", 3.65, 0, 3.65, 500);
        
        currBankChain->addBank(currBank);
        Client* client1 = new Client("Andrey", "Fokin", "Piccadilly circus 225", "8324 709567");
        Client* client2 = new Client("Valery", "Semakin", "Hello world", "3452 789054");

        currBankChain->addClient(currBank, client1);
        currBankChain->addClient(currBank, client2);

        Account* currAccount1 = new DebitAccount();
        Account* currAccount2 = new CreditAccount();
        Account* currAccount3 = new DepositAccount();

        double baseAmountOfMoney = 5000;
        currBankChain->createAccount(currBank, client1, currAccount1, baseAmountOfMoney);
        currBankChain->createAccount(currBank, client2, currAccount2, baseAmountOfMoney);
        currBankChain->createAccount(currBank, client3, currAccount3, baseAmountOfMoney);

        
        Transaction* currTransaction = new DepositTransaction(baseAmountOfMoney);
        Transaction* currTransaction1 = new TransferTransaction(baseAmountOfMoney, );
        Transaction* currTransaction2 = new WithdrawalTransaction(baseAmountOfMoney);
        currBankChain->createTransaction(currBank, currAccount1, currTransaction);
        
        






    }
    catch (std::exception& exp) {
        std::cout << exp.what() << std::endl;
    }
}