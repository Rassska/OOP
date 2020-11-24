#include <iostream>
#include "Vehicle/vehicle.h"
#include "Vehicle/VehicleTypes/air.h"

air::air (std::string_view name, std::size_t speed, std::size_t distanceReducer) :
    vehicle(name, speed), distanceReducer_(distanceReducer) {}