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
        Client* client2 = new Client("Valery", "Semakin", "Mayfair, London W1J 7NB", "3452 789054");
        Client* client3 = new Client("Fedor", "Smolkin", "Royal Hospital Rd, Chelsea, London SW3 4HP", "5432 758423");

        currBankChain->addClient(currBank, client1);
        currBankChain->addClient(currBank, client2);
        currBankChain->addClient(currBank, client3);

        Account* currAccount1 = new DebitAccount();
        Account* currAccount2 = new CreditAccount();
        Account* currAccount3 = new DepositAccount();

        double baseAmountOfMoney = 5000;

        currBankChain->createAccount(currBank, client1, currAccount1);
        currBankChain->createAccount(currBank, client2, currAccount2);
        currBankChain->createAccount(currBank, client3, currAccount3);

        time_t currTime = std::time(nullptr) + 1100;
        Transaction* currTransaction1 = new DepositTransaction(100000, currTime);
        currBankChain->createTransaction(currBank, currAccount1, client1, currTransaction1);

        Transaction* currTransaction2 = new TransferTransaction(10000, currAccount2, currTime);
        currBankChain->createTransaction(currBank, currAccount1, client1, currTransaction2);

        Transaction* currTransaction3 = new WithdrawalTransaction(100, currTime);
        
        
        






    }
    catch (std::exception& exp) {
        std::cout << exp.what() << std::endl;
    }
}