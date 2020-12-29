#include <iostream>
#include "CustomerBuilder.h"


CustomerBuilder::~CustomerBuilder(){
    delete client_;
}

void CustomerBuilder::setCustomer(const std::string& name, const std::string& surname) {
    Customer* cli = new Customer(name, surname);
    client_ = cli;
}

void CustomerBuilder::setPassport(const std::string& pass) {
    this->client_->setPassportCustomer(pass);
}

void CustomerBuilder::setAddress(const std::string& pass) {
    this->client_->setAddressCustomer(pass);
}

Customer* CustomerBuilder::getCustomer() {
    if(client_ == nullptr) throw std::runtime_error("Error! Customer does not exist within the function CustomerBuilder::getCustomer().\n");
    return client_;
}

void CustomerBuilder::reset(){
    this->client_ = nullptr;
}