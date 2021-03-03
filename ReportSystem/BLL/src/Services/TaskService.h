#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "BLL/Abstractions/DTRepositoriesAbstraction.h"
#include "DAL/Abstractions/DEntitiesAbstraction.h"
#include "DAL/src/Entities/DTask.h"
#include "DAL/src/Repositories/DTaskRepository.h"
class DTTaskRepository : public DTRepositoriesAbstraction
{
private:
    DTaskRepository currDALTaskRepo;
public:
    DTTaskRepository();
    void create(DTEntitiesAbstraction* currTask) override;
    void deletee(std::size_t currTaskID) override;
    void update(DTEntitiesAbstraction* newTask, std::size_t currTaskID) override;

    std::vector <DTEntitiesAbstraction*> getAll() override;
    DTEntitiesAbstraction* getEntity(std::size_t entityID) override;
    
    void showEntitiesList() override;
    ~DTTaskRepository();

};