#pragma once
#include <iostream>
#include "Vehicle/VehicleTypes/ground.h"

class boots : public ground
{
private:
    
public:
    boots();
    boots (std::string_view name, std::size_t speed, std::size_t restInterval, std::size_t restDuration);
    ~boots();
};

