#pragma once
#include <iostream>

#include "Vehicle/VehicleTypes/air.h"

class broom : public air
{
private:
    
public:
    explicit broom();
    explicit broom(std::string_view name, std::size_t speed ,std::size_t distanceReducer);
    ~broom();
};

