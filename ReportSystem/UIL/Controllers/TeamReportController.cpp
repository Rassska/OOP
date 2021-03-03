#include "UIL/Controllers/TeamReportController.h"
#include "BLL/src/DTOEntities/DTTeamReport.h"
#include "BLL/Abstractions/DTEntitiesAbstraction.h"

TeamReportController::TeamReportController() = default;

TeamReportController::~TeamReportController() = default;

void TeamReportController::addTeamReport(TeamReportViewModel* currTeamReport){

    // DTEntitiesAbstraction* currDTOTeamReport = new DTTeamReport(currTeamReport->getName(), currTeamReport->getDescription(), currTeamReport->getReportList());
    // m_Repo.create(currDTOTeamReport);
}

void TeamReportController::showTeamReports() {
    m_Repo.showEntitiesList();
}