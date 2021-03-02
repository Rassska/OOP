#include "DAL/src/Repositories/DWorkerRepository.h"
#include <vector>
#include <string>
#include <iostream>


DWorkerRepository::DWorkerRepository() = default;
DWorkerRepository::~DWorkerRepository() = default;

std::vector <DEntitiesAbstraction*> DWorkerRepository::getAll()  {
    
}

void DWorkerRepository::create(DEntitiesAbstraction* currTask) { 
    
}

void DWorkerRepository::deletee(const std::size_t currTaskID) { 

}
void DWorkerRepository::update(DEntitiesAbstraction* newEntity, const std::size_t currTaskID) { 

}

void DWorkerRepository::showEntitiesList() {

    std::cout << "WorkerID" << "/" << "Name" << "/" << "CreatedTime"<< '\n';
    for (std::size_t i = 0; i < m_CurrWorkers.size(); i++) {
        std::cout << m_CurrWorkers[i]->getWorkerID() << ' ' << m_CurrWorkers[i]->getName() << ' ' << m_CurrWorkers[i]->getCreatedTime();

    }
    std::cout << "\n";
}