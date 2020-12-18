#pragma once
#include <iostream>

class vehicle {

public:

    explicit vehicle();
    explicit vehicle(std::string_view name, std::size_t speed);
    ~vehicle();
    virtual std::size_t getSpeed();
    std::string_view getName();
    
protected:
    std::size_t speed_;
    std::string_view name_;
};

