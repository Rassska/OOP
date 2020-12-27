#pragma once 
#include "Builder.h"
#include "Customer.h"

class ClientBuilder : public Builder {
protected:
    Customer* client_ = nullptr;
public:
    virtual ~ClientBuilder();
    void setClient(const std::string& name, const std::string& surname) override;
    void setPassport(const std::string& pass) override;
    void setAddress(const std::string& pass) override;
    Customer* getClient() override;
    void reset() override;
};