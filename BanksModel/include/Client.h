#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"
#include "Transaction.h"
class Client
{
private:
    static std::size_t m_clientId;
    std::string_view m_firstName;
    std::string_view m_lastName;
    std::string_view m_address;
    std::string_view m_passport;
    bool m_isDoubt;
    std::vector<Account*> m_accounts;
    
public:
    Client();
    Client(std::string firstName, std::string lastName, std::string_view address, std::string_view passport);
    void setFirstName(std::string_view firstName);
    void setLastName(std::string_view lastName);
    void setAddress(std::string_view address);
    void setPassport(std::string_view passport);
    void createAccount(Account* account);
    void createTransaction(Account* account, Transaction* transaction);

    ~Client();
};


