#include <iostream>
#include "Vehicle/VehicleTypes/AirTypes/besom.h"
#include "Vehicle/VehicleTypes/air.h"

besom::besom (std::string_view name, std::size_t speed) :
    air(name, speed) {}

besom::besom() = default;

std::size_t besom::getNewDistance(std::size_t prevDistance) {
    return (prevDistance - (prevDistance * 6 / 100));
}