#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "BLL/Abstractions/DTRepositoriesAbstraction.h"
#include "DAL/Abstractions/DEntitiesAbstraction.h"
#include "DAL/src/Entities/DWorker.h"
#include "DAL/src/Repositories/DWorkerRepository.h"

class DTWorkerRepository : public DTRepositoriesAbstraction
{
private:
    DWorkerRepository currDALWorkerRepo;
public:
    DTWorkerRepository();
    void create(DTEntitiesAbstraction* currWorker) override;
    void deletee(std::size_t currWorkerID) override;
    void update(DTEntitiesAbstraction* newWorker, std::size_t currWorkerID) override;

    std::vector <DTEntitiesAbstraction*> getAll() override;
    DTEntitiesAbstraction* getEntity(std::size_t entityID) override;
    
    void showEntitiesList() override;
    ~DTWorkerRepository();

};