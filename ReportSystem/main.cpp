#include <iostream>

#include "DAL/Abstractions/DEntitiesAbstraction.h"
#include "DAL/Abstractions/DRepositoriesAbstraction.h"

#include "DAL/src/Entities/DReport.h"
#include "DAL/src/Entities/DTask.h"
#include "DAL/src/Entities/DTeamReport.h"
#include "DAL/src/Entities/DWorker.h"

#include "DAL/src/Repositories/DWorkerRepository.h"
#include "DAL/src/Repositories/DReportRepository.h"
#include "DAL/src/Repositories/DTaskRepository.h"
#include "DAL/src/Repositories/DTeamReportRepository.h"
#include "UIL/Controllers/ReportController.h"
#include "UIL/Controllers/TeamReportController.h"
#include "UIL/Controllers/WorkerController.h"
#include "UIL/Controllers/TaskController.h"

#include "UIL/ViewModels/WorkerViewModel.h"

int main() {



    WorkerViewModel* worker1 = new WorkerViewModel("Andrey", -1);

    TaskViewModel* task1 = new TaskViewModel(1, "checking opening files", "check Files", "open");



    ReportController* reportController = new ReportController();
    TeamReportController* teamReportController = new TeamReportController();
    WorkerController* workerController = new WorkerController();
    TaskController* taskController = new TaskController();


    

    
}