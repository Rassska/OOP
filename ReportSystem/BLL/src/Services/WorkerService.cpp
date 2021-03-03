#include "BLL/src/Services/WorkerService.h"
#include "DAL/src/Repositories/DWorkerRepository.h"
#include "DAL/src/Entities/DWorker.h"
#include "DAL/Abstractions/DEntitiesAbstraction.h"
#include "BLL/src/DTOEntities/DTWorker.h"


DTWorkerRepository::DTWorkerRepository() = default;
void DTWorkerRepository::create(DTEntitiesAbstraction* currWorkerP) {

    
    DTWorker* currDTOWorker = dynamic_cast<DTWorker*>(currWorkerP);
    DWorker* currDALWorker = new DWorker(currDTOWorker->getName(), currDTOWorker->getLeaderID(), currDTOWorker->getHierarchy(), currDTOWorker->getTasksList());
    currDALWorkerRepo.create(currDALWorker);

} 
void DTWorkerRepository::deletee(std::size_t currWorkerID) {

} 
void DTWorkerRepository::update(DTEntitiesAbstraction* newWorker, std::size_t currWorkerID) {

} 

std::vector <DTEntitiesAbstraction*> DTWorkerRepository::getAll() {

} 
DTEntitiesAbstraction* DTWorkerRepository::getEntity(std::size_t entityID) {

} 

void DTWorkerRepository::showEntitiesList() {

} 

DTWorkerRepository::~DTWorkerRepository() = default;