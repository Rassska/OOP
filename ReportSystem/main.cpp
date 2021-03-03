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


int main() {
    
    DEntitiesAbstraction* currEntity = new DReport();
    DEntitiesAbstraction* currEntity2 = new DReport();
    DRepositoriesAbstraction* currRepo = new DReportRepository();
    
    currRepo->create(currEntity);
    currRepo->create(currEntity2);
    
    currRepo->showEntitiesList();
    
}