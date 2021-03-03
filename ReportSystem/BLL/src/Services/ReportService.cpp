#include "BLL/src/Services/ReportService.h"
#include "BLL/Abstractions/DTEntitiesAbstraction.h"
#include <iostream>
#include <vector>
#include <string>

DTReportRepository::DTReportRepository() = default;
void DTReportRepository::create(DTEntitiesAbstraction* currReport){};
void DTReportRepository::deletee(std::size_t currReportID){};
void DTReportRepository::update(DTEntitiesAbstraction* newReport, std::size_t currReportID){};

std::vector <DTEntitiesAbstraction*> DTReportRepository::getAll(){};
DTEntitiesAbstraction* DTReportRepository::getEntity(std::size_t entityID){};

void DTReportRepository::showEntitiesList(){};
DTReportRepository::~DTReportRepository() = default;