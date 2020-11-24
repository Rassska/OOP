#include <iostream>
#include "Vehicle/vehicle.h"
#include "Vehicle/VehicleTypes/ground.h"

ground::ground(std::string_view name, std::size_t speed ,std::size_t restInterval, std::size_t restDuration) :
    vehicle(name, speed), restInterval_(restInterval), restDuration_(restDuration) {}