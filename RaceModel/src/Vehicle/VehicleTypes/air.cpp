#include <iostream>
#include "Vehicle/vehicle.h"
#include "Vehicle/VehicleTypes/air.h"

air::air(std::string_view name, std::size_t speed) :
    vehicle(name, speed) {}

air::air() = default;

std::size_t air::getNewDistance(std::size_t prevDistance) {return 0;}