#pragma once

#include <iostream>
#include <string>
#include <vector>

class DEntitiesAbstraction
{
protected:
    
public:
    DEntitiesAbstraction();
    DEntitiesAbstraction* operator=(const DEntitiesAbstraction* other);
    virtual ~DEntitiesAbstraction();
    
};
