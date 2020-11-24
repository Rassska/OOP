#pragma once
#include <iostream>

#include "Vehicle/VehicleTypes/air.h"

class besom : public air
{
private:
    
public:
    explicit besom();
    explicit besom(std::string_view name, std::size_t speed ,std::size_t distanceReducer);
    ~besom();
};

