#include <iostream>
#include "Vehicle/VehicleTypes/AirTypes/broom.h"
#include "Vehicle/VehicleTypes/air.h"

broom::broom (std::string_view name, std::size_t speed, std::size_t distanceReducer) :
    air(name, speed, distanceReducer) {}