#include "UIL/Controllers/WorkerController.h"
#include "BLL/src/DTOEntities/DTWorker.h"
#include "BLL/src/Services/TaskService.h"

WorkerController::WorkerController() = default;

WorkerController::~WorkerController() = default;

void WorkerController::addWorker(WorkerViewModel* currWorker) {
    DTEntitiesAbstraction* currDTOWorker = new DTWorker(currWorker->getName(), currWorker->getLeaderID(), currWorker->getHierarchy(), currWorker->getTasksList());
    m_Repo.create(currDTOWorker);
    
}