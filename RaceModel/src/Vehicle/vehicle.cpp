#include <iostream>
#include <string>
#include "Vehicle/vehicle.h"


vehicle::vehicle() = default;

vehicle::vehicle(std::string_view name, std::size_t speed) :
    name_(name), speed_(speed) {}

std::size_t vehicle::getSpeed() {
    return speed_;
}
std::string_view vehicle::getName() {
    return name_;
}