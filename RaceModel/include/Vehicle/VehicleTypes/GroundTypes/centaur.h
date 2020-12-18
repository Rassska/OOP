#pragma once
#include <iostream>
#include "Vehicle/VehicleTypes/ground.h"

class centaur : public ground
{
private:
    
public:
    centaur();
    centaur (std::string_view name, std::size_t speed, std::size_t restInterval, std::size_t restDuration);
    ~centaur();
    void changeRestDuration(std::size_t restCnt) override;
   
};

