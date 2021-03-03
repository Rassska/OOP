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


int main() {
    
    ReportController* reportController = new ReportController();
    TeamReportController* teamReportController = new TeamReportController();
    WorkerController* workerController = new WorkerController();
    TaskController* taskController = new TaskController();

    while (true) {
        
    }

    
}