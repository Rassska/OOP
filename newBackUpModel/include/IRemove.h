#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include "BackUp.h"

class IRemove
{
private:
    
public:
    IRemove(){};
    virtual std::size_t getDiff(const BackUp& currBackUp){};
    ~IRemove(){};
};

