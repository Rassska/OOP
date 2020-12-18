#pragma once
#include <iostream>
#include "Vehicle/vehicle.h"

class air : public vehicle
{
private:
    std::size_t distanceReducer_;
public:

    explicit air();
    explicit air(std::string_view name, std::size_t speed);
    virtual std::size_t getNewDistance(std::size_t prevDistance);
    ~air();
};

