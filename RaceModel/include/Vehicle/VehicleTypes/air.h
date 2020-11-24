#pragma once
#include <iostream>
#include "Vehicle/vehicle.h"

class air : protected vehicle
{
private:
    const std::size_t distanceReducer_;
public:
    explicit air();
    explicit air(std::string_view name, std::size_t speed ,std::size_t distanceReducer);
    ~air();
};

