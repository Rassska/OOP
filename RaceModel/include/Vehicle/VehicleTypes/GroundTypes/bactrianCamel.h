#pragma once
#include <iostream>
#include "Vehicle/VehicleTypes/ground.h"

class bactrianCamel :  ground {

private:

public:
    bactrianCamel();
    bactrianCamel (std::string_view name, std::size_t speed, std::size_t restInterval, std::size_t restDuration);
    ~bactrianCamel();
};
