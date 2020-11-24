#include <iostream>
#include "Vehicle/VehicleTypes/GroundTypes/centaur.h"
#include "Vehicle/VehicleTypes/ground.h"

centaur::centaur (std::string_view name, std::size_t speed, std::size_t restInterval, std::size_t restDuration) :
    ground(name, speed, restInterval, restDuration) {}