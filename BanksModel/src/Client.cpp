#include "Client.h"
#include <iostream>
#include <vector>
#include <string>


std::size_t Client::m_clientId = 0;

Client::Client() {
    m_firstName = "";
    m_lastName = "";
    m_accounts = {};
    m_passport = "";
    m_address = "";
    m_isDoubt = true;
    m_clientId++;
}

Client::Client(std::string firstName, std::string lastName, std::string_view address, std::string_view passport) :
    m_firstName(firstName), m_lastName(lastName), m_address(address), m_passport(passport)
{
    m_accounts = {};
    m_isDoubt = false;
    m_clientId++;
}

void Client::setAddress(std::string_view address) {
    m_address = address;
    m_isDoubt = false;
}
void Client::setPassport(std::string_view passport) {
    m_passport = passport;
    m_isDoubt = false;
}
void Client::setFirstName(std::string_view firstName) {m_firstName = firstName;}
void Client::setLastName(std::string_view lastName) {m_lastName = lastName;}

void Client::createAccount(Account* account) {
    m_accounts.push_back(account);
}

void Client::createTransaction(Account* account, Transaction* transaction) {
    transaction->do(account);
}

Client::~Client() = default;