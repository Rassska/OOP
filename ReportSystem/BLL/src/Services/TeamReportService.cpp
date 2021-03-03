#include "BLL/src/Services/TeamReportService.h"
#include "BLL/src/DTOEntities/DTTeamReport.h"
#include "DAL/src/Entities/DTeamReport.h"
DTTeamReportRepository::DTTeamReportRepository() = default;
DTTeamReportRepository::~DTTeamReportRepository() = default;

void DTTeamReportRepository::create(DTEntitiesAbstraction* currTeamReport) {
    // DTTeamReport* currDTOTeamReport = dynamic_cast<DTTeamReport*>(currTeamReport);
    // DTeamReport* currDALTeamReport = new DTeamReport(currDTOTeamReport->getName(), currDTOTeamReport->getDescription(), currDTOTeamReport->getReportList());
    // currDALTeamReportRepo.create(currDALTeamReport);
} 
void DTTeamReportRepository::deletee(std::size_t currTeamReportID) {

} 
void DTTeamReportRepository::update(DTEntitiesAbstraction* newTeamReport, std::size_t currTeamReportID) {

} 

std::vector <DTEntitiesAbstraction*> DTTeamReportRepository::getAll() {

} 
DTEntitiesAbstraction* DTTeamReportRepository::getEntity(std::size_t entityID) {

} 

void DTTeamReportRepository::showEntitiesList() {
    currDALTeamReportRepo.showEntitiesList();
} 