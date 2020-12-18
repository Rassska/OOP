#include <iostream>
#include "Vehicle/VehicleTypes/GroundTypes/boots.h"
#include "Vehicle/VehicleTypes/ground.h"

boots::boots (std::string_view name, std::size_t speed, std::size_t restInterval, std::size_t restDuration) :
    ground(name, speed, restInterval, restDuration) {}

boots::boots() = default;

void boots::changeRestDuration(std::size_t restCnt) {
    if (restCnt > 1) 
        this->restDuration_ = 5;
    
}