#include <iostream>
#include "Vehicle/VehicleTypes/AirTypes/besom.h"
#include "Vehicle/VehicleTypes/air.h"

besom::besom (std::string_view name, std::size_t speed, std::size_t distanceReducer) :
    air(name, speed, distanceReducer) {}