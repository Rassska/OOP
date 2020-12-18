#pragma once
#include <iostream>
#include "Vehicle/VehicleTypes/ground.h"

class swiftCamel : public ground
{
private:
    
public:
    swiftCamel();
    swiftCamel(std::string_view name, std::size_t speed, std::size_t restInterval, std::size_t restDuration);
    ~swiftCamel();
    void changeRestDuration(std::size_t restCnt) override;
};

