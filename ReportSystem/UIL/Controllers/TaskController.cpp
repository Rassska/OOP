#include "UIL/Controllers/TaskController.h"
#include "BLL/src/DTOEntities/DTTask.h"
#include "UIL/ViewModels/TaskViewModel.h"


TaskController::TaskController() = default;

TaskController::~TaskController() = default;

void TaskController::addTask(TaskViewModel* currTaskViewModel) {
    DTTask* currDTOTask = new DTTask(currTaskViewModel->getAuthorID(), currTaskViewModel->getTaskDescription(), currTaskViewModel->getTaskName(), currTaskViewModel->getTaskName());
    m_TaskRepository.create(currDTOTask);
}

void TaskController::update(TaskViewModel* currTaskViewModel, std::size_t changeTaskID) {
    DTTask* currDTOTask = new DTTask(currTaskViewModel->getAuthorID(), currTaskViewModel->getTaskDescription(), currTaskViewModel->getTaskName(), currTaskViewModel->getTaskName());
    m_TaskRepository.update(currDTOTask, changeTaskID);
}

void TaskController::showTasksList() {
    m_TaskRepository.showEntitiesList();
}