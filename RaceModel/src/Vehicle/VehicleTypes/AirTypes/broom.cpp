#include <iostream>
#include "Vehicle/VehicleTypes/AirTypes/broom.h"
#include "Vehicle/VehicleTypes/air.h"

broom::broom (std::string_view name, std::size_t speed) :
    air(name, speed) {}

broom::broom() = default;

std::size_t broom::getNewDistance(std::size_t prevDistance) {
    return prevDistance - (prevDistance / 100);
}