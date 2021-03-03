#include "UIL/Controllers/ReportController.h"
#include "BLL/src/DTOEntities/DTTask.h"
#include "BLL/src/DTOEntities/DTTask.h"
ReportController::ReportController() = default;

ReportController::~ReportController() = default;

void ReportController::addTask(TaskViewModel* currTaskViewModel) {
    DTTask* currDTOTask = new DTTask(currTaskViewModel->getAuthorID(), currTaskViewModel->getTaskDescription(), currTaskViewModel->getTaskName(), currTaskViewModel->getTaskName());
    
}