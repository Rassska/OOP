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
#include <time.h>
#include <ctime>
#include "AccountFactory/AccountFactory.h"
#include "AccountFactory/DepositAccountFactory.h"
#include "AccountFactory/CreditAccountFactory.h"
#include "AccountFactory/DebitAccountFactory.h"

const double baseAmountOfMoney = 5000;
time_t currTime = std::time(nullptr) + 1100;




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

        // Client 1
        AccountFactory* currAccountFactory = new CreditAccountFactory();
        currBankChain->createAccount(currBank, client1, currAccountFactory->createAccount());

        currAccountFactory = new DebitAccountFactory();
        currBankChain->createAccount(currBank, client1, currAccountFactory->createAccount());

        currAccountFactory = new DepositAccountFactory();
        currBankChain->createAccount(currBank, client1, currAccountFactory->createAccount());


        //Client 2

        currAccountFactory = new CreditAccountFactory();
        currBankChain->createAccount(currBank, client2, currAccountFactory->createAccount());

        currAccountFactory = new DebitAccountFactory();
        currBankChain->createAccount(currBank, client2, currAccountFactory->createAccount());

        currAccountFactory = new DepositAccountFactory();
        currBankChain->createAccount(currBank, client2, currAccountFactory->createAccount());


        
        //! [Tested: DebitAccount -> DepositTransaction]

        //  Transaction* currTransaction1 = new DepositTransaction(100000, currTime);
        //  currBankChain->createTransaction(currBank, client1->getAccountsList()[1], currTransaction1);
        //? std::cout << client1->getAccountsList()[1]->getAmountOfMoney();
        //? exit(0);

        //! [Tested:: DebitAccount -> TransferTransaction]
        //  Transaction* currTransaction2 = new TransferTransaction(10000, client2->getAccountsList()[1], currTime);
        //  currBankChain->createTransaction(currBank, client1->getAccountsList()[1], currTransaction2);
        //? std::cout << client1->getAccountsList()[1]->getAmountOfMoney();
        //? exit(0);


        //! [Tested:: DebitAccount -> WithdrawalTransaction]
        //  Transaction* currTransaction3 = new WithdrawalTransaction(1000000, currTime);
        //  currBankChain->createTransaction(currBank, client1->getAccountsList()[1], currTransaction3);
        //? std::cout << client1->getAccountsList()[1]->getAmountOfMoney();
        //? exit(0);

        //! [Tested:: CreditAccount -> DepositTransaction]
        //  Transaction* currTransaction4 = new DepositTransaction(10000, currTime);
        //  currBankChain->createTransaction(currBank, client1->getAccountsList()[0], currTransaction4);
        //? std::cout << client1->getAccountsList()[0]->getAmountOfMoney();
        //? exit(0);

        //! [Tested:: CreditAccount -> TransferTransaction]
        //  Transaction* currTransaction5 = new TransferTransaction(2000, client1->getAccountsList()[1], currTime);
        //  currBankChain->createTransaction(currBank, client1->getAccountsList()[0], currTransaction5);
        //? std::cout << client1->getAccountsList()[0]->getAmountOfMoney() << '\n' <<client1->getAccountsList()[1]->getAmountOfMoney();
        //? exit(0);

        //! [Tested:: CreditAccount -> DepositTransaction]
        //  Transaction* currTransaction6 = new DepositTransaction(10000, currTime);
        //  currBankChain->createTransaction(currBank, client1->getAccountsList()[0], currTransaction6);
        //? std::cout << client1->getAccountsList()[0]->getAmountOfMoney();
        //? exit(0);

        //! [Tested:: DepositAccount -> DepositTransaction]
        //  Transaction* currTransaction7 = new DepositTransaction(100000, currTime);
        //  currBankChain->createTransaction(currBank, client1->getAccountsList()[2], currTransaction7);
        //? std::cout << client1->getAccountsList()[2]->getAmountOfMoney() << '\n' << client1->getAccountsList()[2]->getInterestPercent();
        //? exit(0);

        //! [Tested:: DepositAccount -> TransferTransaction]
        //  Transaction* currTransaction8 = new TransferTransaction(10000, client1->getAccountsList()[1], currTime);
        //  currBankChain->createTransaction(currBank, client1->getAccountsList()[2], currTransaction8);
        //? std::cout << client1->getAccountsList()[2]->getAmountOfMoney() << '\n' << client1->getAccountsList()[1]->getAmountOfMoney();
        //? exit(0);

        //! [Tested:: DepositAccount -> TransferTransaction]
        //  Transaction* currTransaction9 = new WithdrawalTransaction(10000, currTime);
        //  currBankChain->createTransaction(currBank, client1->getAccountsList()[2], currTransaction9);
        //? std::cout << client1->getAccountsList()[2]->getAmountOfMoney();
        //? exit(0);


        // currBankChain->calculateInterestOrCommission(currBank, currTime);
        

    }
    catch (std::exception& exp) {
        std::cout << exp.what() << std::endl;
    }
}