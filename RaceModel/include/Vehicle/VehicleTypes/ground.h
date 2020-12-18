#pragma once
#include <iostream>
#include "Vehicle/vehicle.h"

class ground : public vehicle
{
protected:
    std::size_t restInterval_;
    std::size_t restDuration_;
public:
    explicit ground();
    explicit ground(std::string_view name, std::size_t speed ,std::size_t restInterval, std::size_t restDuration);
    virtual std::size_t getRestInterval();
    virtual std::size_t getRestDuration();
    virtual void changeRestDuration(std::size_t restCnt);
    
    ~ground();
    
    
};

