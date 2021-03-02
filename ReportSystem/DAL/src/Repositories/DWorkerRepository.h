#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DAL/Abstractions/DRepositoriesAbstraction.h"
#include "DAL/src/Entities/DWorker.h"

class DWorkerRepository : public DRepositoriesAbstraction
{
private:
    std::vector <DWorker*> m_CurrWorkers;
public:
    DWorkerRepository();
    void create(DEntitiesAbstraction* currWorker) override;
    void deletee(const std::size_t currWorkerID) override;
    void update(DEntitiesAbstraction* newEntity, const std::size_t currWorkerID) override;
    std::vector <DEntitiesAbstraction*> getAll() override;
    
    ~DWorkerRepository();
};