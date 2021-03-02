#include "DAL/src/Repositories/DTeamReportRepository.h"
#include <vector>
#include <string>
#include <iostream>


DTeamReportRepository::DTeamReportRepository() = default;
DTeamReportRepository::~DTeamReportRepository() = default;


std::vector <DEntitiesAbstraction*> DTeamReportRepository::getAll()  {
    
}

void DTeamReportRepository::create(DEntitiesAbstraction* currTask) { 
    
}

void DTeamReportRepository::deletee(const std::size_t currTaskID) { 

}
void DTeamReportRepository::update(DEntitiesAbstraction* newEntity, const std::size_t currTaskID) { 

}

void DTeamReportRepository::showEntitiesList() {

    std::cout << "TeamReportID" << "/" << "Name" << "/" << "CreatedTime"<< '\n'; 
    for (std::size_t i = 0; i < m_CurrTeamReports.size(); i++) {
        std::cout << m_CurrTeamReports[i]->getTeamReportID() << ' ' << m_CurrTeamReports[i]->getName() << ' ' << m_CurrTeamReports[i]->getCreatedTime();

    }
    std::cout << "\n";
}