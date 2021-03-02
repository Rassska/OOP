#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "DAL/Abstractions/DEntitiesAbstraction.h"
#include "DAL/src/Entities/DReport.h"

class DRepositoriesAbstraction
{
protected:
    
public:
    DRepositoriesAbstraction();

    virtual void create(DEntitiesAbstraction* currEntity);
    virtual void deletee(std::size_t currEntityID);
    virtual void update(DEntitiesAbstraction* newEntity, std::size_t currEntityID);
    virtual std::vector <DEntitiesAbstraction*> getAll(); 
    virtual DEntitiesAbstraction* getEntity(std::size_t entityID);
    ~DRepositoriesAbstraction();
};