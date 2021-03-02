#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "DAL/Abstractions/DRepositoriesAbstraction.h"
#include "DAL/src/Entities/DTask.h"


class DTaskRepository : public DRepositoriesAbstraction
{
private:
    std::vector <DTask*> m_CurrTasks;
public:
    DTaskRepository();
    void create(DEntitiesAbstraction* currTask) override;
    void deletee(const std::size_t currTaskID) override;
    void update(DEntitiesAbstraction* newEntity, const std::size_t currTaskID) override;
    std::vector <DEntitiesAbstraction*> getAll() override;
    void showEntitiesList() override;
    ~DTaskRepository();
};