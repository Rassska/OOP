#include <iostream>
#include "Vehicle/VehicleTypes/GroundTypes/bactrianCamel.h"
#include "Vehicle/VehicleTypes/ground.h"

bactrianCamel::bactrianCamel(std::string_view name, std::size_t speed, std::size_t restInterval, std::size_t restDuration) :
    ground(name, speed, restInterval, restDuration) {}

bactrianCamel::bactrianCamel() = default;

void bactrianCamel::changeRestDuration(std::size_t restCnt) {
    if (restCnt > 1) 
        this->restDuration_ = 8;
}