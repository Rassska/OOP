#include <iostream>
#include "Vehicle/VehicleTypes/AirTypes/carpet.h"
#include "Vehicle/VehicleTypes/air.h"

carpet::carpet(std::string_view name, std::size_t speed) :
    air(name, speed) {}

carpet::carpet() = default;

std::size_t carpet::getNewDistance(std::size_t prevDistance) {
    
    if (prevDistance > 1000 && prevDistance < 5000){return prevDistance - prevDistance * 3 / 100;}
    else if (prevDistance >= 5000 && prevDistance < 10000){return prevDistance - prevDistance / 10;}
    else if (prevDistance > 10000){return prevDistance - prevDistance / 20;}
    else {return prevDistance;}
}