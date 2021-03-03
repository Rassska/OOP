#include "DAL/src/Repositories/DTaskRepository.h"
#include "DAL/src/Entities/DTask.h"
#include <vector>
#include <string>
#include <iostream>


DTaskRepository::DTaskRepository() = default;
DTaskRepository::~DTaskRepository() = default;

std::vector <DEntitiesAbstraction*> DTaskRepository::getAll() {
    std::vector<DEntitiesAbstraction*> temp;
    for (std::size_t i = 0; i < m_CurrTasks.size(); i++) {
        temp.push_back(m_CurrTasks[i]);
    }

    return temp;
}

void DTaskRepository::create(DEntitiesAbstraction* currTask) { 
    DTask* tempTask = dynamic_cast<DTask*>(currTask);
    tempTask->setTaskID(getAll().size() + 1);
    m_CurrTasks.push_back(tempTask);
}

void DTaskRepository::deletee(const std::size_t currTaskID) { 

}
void DTaskRepository::update(DEntitiesAbstraction* newEntity, const std::size_t currTaskID) { 

}

void DTaskRepository::showEntitiesList() {

    std::cout << "TaskID" << "/" << "AuthorID" << "/" << "CreatedTime"<< '\n';
    for (std::size_t i = 0; i < m_CurrTasks.size(); i++) {
        std::cout << m_CurrTasks[i]->getTaskID() << ' ' << m_CurrTasks[i]->getAuthorID() << ' ' << m_CurrTasks[i]->getCreatedTime() << '\n';

    }
    std::cout << "\n";
}

