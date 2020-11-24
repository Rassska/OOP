#pragma once
#include <iostream>
#include "Vehicle/vehicle.h"

class ground : protected vehicle
{
private:
    std::size_t restInterval_;
    std::size_t restDuration_;
public:
    explicit ground();
    explicit ground(std::string_view name, std::size_t speed ,std::size_t restInterval, std::size_t restDuration);
    ~ground();
};

