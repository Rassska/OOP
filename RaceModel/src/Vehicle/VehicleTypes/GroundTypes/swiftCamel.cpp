#include <iostream>
#include "Vehicle/VehicleTypes/GroundTypes/swiftCamel.h"
#include "Vehicle/VehicleTypes/ground.h"

swiftCamel::swiftCamel(std::string_view name, std::size_t speed, std::size_t restInterval, std::size_t restDuration) :
    ground(name, speed, restInterval, restDuration) {}

swiftCamel::swiftCamel() = default;

void swiftCamel::changeRestDuration(std::size_t restCnt) {
    
}