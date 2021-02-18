#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include "BackUp.h"

class IRemoveManager
{
private:
    
public:
    IRemoveManager(){};
    virtual std::size_t getDiff(const BackUp& currBackUp){};
    ~IRemoveManager(){};
};

