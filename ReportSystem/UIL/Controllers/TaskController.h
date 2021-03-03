#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "DAL/src/Repositories/DTaskRepository.h"
#include "UIL/ViewModels/TaskViewModel.h"
#include "BLL/src/Services/TaskService.h"

class TaskController
{
private:
    DTTaskRepository m_TaskRepository;
public:
    TaskController();
    void addTask(TaskViewModel* currTaskViewModel);
    void update(TaskViewModel* currTaskViewModel, std::size_t changeTaskID);
    void showTasksList();
    ~TaskController();
};
