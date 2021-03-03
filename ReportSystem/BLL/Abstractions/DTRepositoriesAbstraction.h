#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "BLL/Abstractions/DTEntitiesAbstraction.h"
#include "BLL/src/DTOEntities/DTReport.h"

class DTRepositoriesAbstraction
{
protected:
    
public:
    DTRepositoriesAbstraction();

    virtual void create(DTEntitiesAbstraction* currEntity);
    virtual void deletee(std::size_t currEntityID);
    virtual void update(DTEntitiesAbstraction* newEntity, std::size_t currEntityID);
    virtual std::vector <DTEntitiesAbstraction*> getAll(); 
    virtual DTEntitiesAbstraction* getEntity(std::size_t entityID);
    virtual void showEntitiesList();
    ~DTRepositoriesAbstraction();
};