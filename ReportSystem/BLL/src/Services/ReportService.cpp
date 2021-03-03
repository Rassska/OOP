#include "BLL/src/Services/ReportService.h"
#include "BLL/Abstractions/DTEntitiesAbstraction.h"
#include "DAL/src/Entities/DReport.h"
#include <iostream>
#include <vector>
#include <string>

DTReportRepository::DTReportRepository() = default;
void DTReportRepository::create(DTEntitiesAbstraction* currReport){
    DTReport* currDTOReport = dynamic_cast<DTReport*>(currReport);
    DReport* currDALReport = new DReport(currDTOReport->getAuthorID(), currDTOReport->getComment(), currDTOReport->getFinishedTasksID());
    currDALReportRepo.create(currDALReport);
};
void DTReportRepository::deletee(std::size_t currReportID){};
void DTReportRepository::update(DTEntitiesAbstraction* newReport, std::size_t currReportID){};

std::vector <DTEntitiesAbstraction*> DTReportRepository::getAll(){};
DTEntitiesAbstraction* DTReportRepository::getEntity(std::size_t entityID){};

void DTReportRepository::showEntitiesList(){
    currDALReportRepo.showEntitiesList();
};
DTReportRepository::~DTReportRepository() = default;