#pragma once
#include <iostream>

class vehicle {

public:

    explicit vehicle();
    explicit vehicle(std::string_view name, std::size_t speed);
    ~vehicle();

private:
    std::size_t speed_;
    std::string_view name_;
};

