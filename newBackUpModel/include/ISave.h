#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "BackUp.h"
class ISave
{
private:
    
public:
    ISave(){};
    virtual void save(const BackUp* currBackUp){};
    ~ISave(){};
};