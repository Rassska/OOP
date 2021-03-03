#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "DAL/src/Repositories/DTaskRepository.h"
#include "UIL/ViewModels/TaskViewModel.h"
class TaskController
{
private:
    DTaskRepository m_TaskRepository;
public:
    TaskController();
    void addTask(TaskViewModel* currTaskViewModel);
    ~TaskController();
};
