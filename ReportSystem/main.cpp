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
#include "UIL/ViewModels/ReportViewModel.h"
#include "UIL/ViewModels/TeamReportViewModel.h"

int main() {

    
    WorkerController* workerController = new WorkerController();
    ReportController* reportController = new ReportController();
    TaskController* taskController = new TaskController();
    TeamReportController* teamReportController = new TeamReportController();

    WorkerViewModel* worker1 = new WorkerViewModel("Andrey", -1);
    WorkerViewModel* worker2 = new WorkerViewModel("Anton", 1);
    WorkerViewModel* worker3 = new WorkerViewModel("Alex", 1);


    workerController->addWorker(worker1);
    workerController->addWorker(worker2);
    workerController->addWorker(worker3);

    TaskViewModel* task1 = new TaskViewModel(2, "checking opening files", "check Files", "resolved");
    TaskViewModel* task2 = new TaskViewModel(2, "resolving problems", "troubles", "resolved");
    TaskViewModel* task3 = new TaskViewModel(2, "rechecking Task.cpp", "Task.cpp", "resolved");
    TaskViewModel* task4 = new TaskViewModel(3, "resolving path problems", "Path", "resolved");
    TaskViewModel* task5 = new TaskViewModel(3, "linking taks", "linking", "resolved");
    std::vector<std::size_t> tasks1, tasks2;
    tasks1.push_back(1);
    tasks1.push_back(2);
    tasks1.push_back(3);
    tasks2.push_back(4);
    tasks2.push_back(5);

    taskController->addTask(task1);
    taskController->addTask(task2);
    taskController->addTask(task3);
    taskController->addTask(task4);
    taskController->addTask(task5);

    //! taskController->showTasksList();
    std::vector <ReportViewModel*> currReports;

    ReportViewModel* report1 = new ReportViewModel(2, "first report", tasks1);
    ReportViewModel* report2 = new ReportViewModel(3, "second report", tasks2);
    reportController->addReport(report1);
    reportController->addReport(report2);
    currReports.push_back(report1);
    currReports.push_back(report2);

    reportController->showAllActiveReports();
    TeamReportViewModel* currTeamReportViewModel = new TeamReportViewModel("firstTeamReport", "about resolving problems", currReports);
    // teamReportController->addTeamReport(currTeamReportViewModel);

    



    


    



    

    


    

    
}