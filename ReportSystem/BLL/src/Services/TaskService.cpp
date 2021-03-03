#include "BLL/src/Services/TaskService.h"
#include "BLL/src/DTOEntities/DTTask.h"
#include "DAL/src/Entities/DTask.h"



DTTaskRepository::DTTaskRepository() = default;
DTTaskRepository::~DTTaskRepository() = default;
void DTTaskRepository::create(DTEntitiesAbstraction* currTask) {
    DTTask* currDTOTask = dynamic_cast<DTTask*>(currTask);
    DTask* currDALTask = new DTask(currDTOTask->getAuthorID(), currDTOTask->getTaskDescription(), currDTOTask->getTaskName(), currDTOTask->getTaskState());
    currDALTaskRepo.create(currDALTask);
} 
void DTTaskRepository::deletee(std::size_t currTaskID) {

} 
void DTTaskRepository::update(DTEntitiesAbstraction* newTask, std::size_t currTaskID) {
    DTTask* currDTOTask = dynamic_cast<DTTask*>(newTask);
    DTask* currDALTask = new DTask(currDTOTask->getAuthorID(), currDTOTask->getTaskDescription(), currDTOTask->getTaskName(), currDTOTask->getTaskState());
    currDALTaskRepo.update(currDALTask, currTaskID);
} 

std::vector <DTEntitiesAbstraction*> DTTaskRepository::getAll() {

} 
DTEntitiesAbstraction* DTTaskRepository::getEntity(std::size_t entityID) {

} 

void DTTaskRepository::showEntitiesList() {
    currDALTaskRepo.showEntitiesList();
} 