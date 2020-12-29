#include <iostream>
#include "Customer.h"
#include "CustomerBuilder.h"
#include "Builder.h"


int Customer::CustomerID = 0;

Customer::~Customer() = default;
Customer::Customer(const std::string& name, const std::string& surname) : nameCustomer(name), surnameCustomer(surname){
    this->thisCustomerID = ++CustomerID;
}

int Customer::getIDCustomer() const {
    return thisCustomerID;
}

std::string Customer::getNameCustomer() const {
    return this->nameCustomer;
}

std::string Customer::getSurnameCustomer() const {
    return this->surnameCustomer;
}

std::string Customer::getAddressCustomer() const {
    return this->addressCustomer;
}

std::string Customer::getPassportCustomer() const {
    return this->passportCustomer;
}

void Customer::setAddressCustomer(const std::string& pass){
    addressCustomer = pass;
}

void Customer::setPassportCustomer(const std::string& pass){
    passportCustomer = pass;
}