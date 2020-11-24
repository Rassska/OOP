#include <iostream>
#include "Vehicle/vehicle.h"

vehicle::vehicle(std::string_view name, std::size_t speed) :
    name_(name), speed_(speed) {}