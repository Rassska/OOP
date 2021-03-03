#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "UIL/ViewModels/WorkerViewModel.h"
#include "BLL/src/Services/WorkerService.h"

class WorkerController
{
private:
    DTWorkerRepository m_Repo;
public:

    WorkerController();
    void addWorker(WorkerViewModel* currWorker);
    ~WorkerController();
};