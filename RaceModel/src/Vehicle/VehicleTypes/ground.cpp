#include <iostream>
#include "Vehicle/vehicle.h"
#include "Vehicle/VehicleTypes/ground.h"

ground::ground(std::string_view name, std::size_t speed ,std::size_t restInterval, std::size_t restDuration) :
    vehicle(name, speed), restInterval_(restInterval), restDuration_(restDuration) {}

ground::ground() = default;

std::size_t ground::getRestInterval() {
    return restInterval_;
}
std::size_t ground::getRestDuration(){
    return restDuration_;
}

void ground::changeRestDuration(std::size_t restCnt) {}

std::size_t ground::calc(std::size_t distance) {

    std::size_t ansTime = 0;
    std::size_t passedDistance = 0;
    std::size_t restCnt = 0;

    while (passedDistance < distance) {
        if (!(ansTime % this->getRestInterval())) {
            ansTime += this->getRestDuration();
            restCnt++;
            continue;
        }
        passedDistance += this->getSpeed();
        
        ansTime++;
    }
    return ansTime;
        
}