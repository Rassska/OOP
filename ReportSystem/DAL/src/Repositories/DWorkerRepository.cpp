#include "DAL/src/Repositories/DWorkerRepository.h"
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

DWorkerRepository::DWorkerRepository() = default;
DWorkerRepository::~DWorkerRepository() = default;

std::vector <DEntitiesAbstraction*> DWorkerRepository::getAll()  {
    std::vector<DEntitiesAbstraction*> temp;

    for (std::size_t i = 0; i < m_CurrWorkers.size(); i++) {
        temp.push_back(m_CurrWorkers[i]);
    }
    return temp;
}

void DWorkerRepository::create(DEntitiesAbstraction* currWorkerP) { 
    DWorker* currWorker = dynamic_cast<DWorker*>(currWorkerP);
    currWorker->setWorkerID(getAll().size() + 1);
    currWorker->setCreatedTime(std::time(nullptr));

    m_CurrWorkers.push_back(currWorker);
}

void DWorkerRepository::deletee(std::size_t currWorkerID) { 
    std::size_t currIndex = 0;
    bool flag = false;
    
    for (std::size_t i = 0; i < m_CurrWorkers.size(); i++) {
        if (m_CurrWorkers[i]->getWorkerID() == currWorkerID) {
            m_CurrWorkers.erase(m_CurrWorkers.begin() + i);
            currIndex = i;
            flag = true;
        }
        if (flag) {
            for (std::size_t i = currIndex; i < m_CurrWorkers.size(); i++) {
                m_CurrWorkers[i]->setWorkerID(m_CurrWorkers[i]->getWorkerID() - 1);
            }
            break;
        }
    }
}
void DWorkerRepository::update(DEntitiesAbstraction* newEntity, std::size_t currWorkerID) { 
    DWorker* currNewWorker = dynamic_cast<DWorker*>(newEntity);

    if (currNewWorker != nullptr) { 
        for (std::size_t i = 0; i < m_CurrWorkers.size(); i++) {
            if (m_CurrWorkers[i]->getWorkerID() == currWorkerID) {
                m_CurrWorkers[i] = currNewWorker;
            }
        }
    }
}

void DWorkerRepository::showEntitiesList() {

    std::cout << "WorkerID" << "/" << "Name" << "/" << "CreatedTime"<< '\n';
    for (std::size_t i = 0; i < m_CurrWorkers.size(); i++) {
        std::cout << m_CurrWorkers[i]->getWorkerID() << ' ' << m_CurrWorkers[i]->getName() << ' ' << m_CurrWorkers[i]->getCreatedTime();

    }
    std::cout << "\n";
}