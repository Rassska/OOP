#pragma once
#include <string>
#include "Customer.h"

class Builder{
public:
    virtual ~Builder() = default;
    virtual void setClient(const std::string& name, const std::string& surname){}
    virtual void setPassport(const std::string& pass) {}
    virtual void setAddress(const std::string& add) {}
    virtual Customer* getClient() {return nullptr;}
    virtual void reset() {}
};