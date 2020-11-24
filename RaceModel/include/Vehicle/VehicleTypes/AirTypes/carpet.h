#pragma once
#include <iostream>
#include "Vehicle/VehicleTypes/air.h"

class carpet: public air
{
private:
    
public:
    explicit carpet();
    explicit carpet(std::string_view name, std::size_t speed ,std::size_t distanceReducer);
    ~carpet();
};

