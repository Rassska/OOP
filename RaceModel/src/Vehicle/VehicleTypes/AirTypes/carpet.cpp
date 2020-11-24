#include <iostream>
#include "Vehicle/VehicleTypes/AirTypes/carpet.h"
#include "Vehicle/VehicleTypes/air.h"

carpet::carpet (std::string_view name, std::size_t speed, std::size_t distanceReducer) :
    air(name, speed, distanceReducer) {}