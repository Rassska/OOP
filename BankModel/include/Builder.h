#pragma once
#include <string>
#include "Customer.h"

class Builder{
public:
    virtual ~Builder();
    virtual void setCustomer(const std::string& name, const std::string& surname);
    virtual void setPassport(const std::string& pass);
    virtual void setAddress(const std::string& add);
    virtual Customer* getCustomer();
    virtual void reset();
};