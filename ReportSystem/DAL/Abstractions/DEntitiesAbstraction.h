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


class Base {
protected:
  Base& operator=(const Base& other); // not virtual
};

class Derived : public Base {
public:
  Derived& operator=(const Derived& other);
};