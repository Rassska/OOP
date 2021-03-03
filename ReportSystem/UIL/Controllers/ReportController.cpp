#include "UIL/Controllers/ReportController.h"
#include "BLL/src/DTOEntities/DTReport.h"
#include "BLL/Abstractions/DTEntitiesAbstraction.h"

ReportController::ReportController() = default;

ReportController::~ReportController() = default;

void ReportController::addReport(ReportViewModel* currReportViewModel) {

    DTEntitiesAbstraction* currDTOReport = new DTReport(currReportViewModel->getAuthorID(), currReportViewModel->getComment(), currReportViewModel->getFinishedTasksID());
    m_Repo.create(currDTOReport);
   
}

void ReportController::showAllActiveReports() {
    m_Repo.showEntitiesList();
}