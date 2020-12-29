#include <iostream>
#include "Builder.h"


Builder::~Builder() = default;
void Builder::setCustomer(const std::string& name, const std::string& surname){}
void Builder::setPassport(const std::string& pass) {}
void Builder::setAddress(const std::string& add) {}
Customer* Builder::getCustomer() {return nullptr;}
void Builder::reset() {}