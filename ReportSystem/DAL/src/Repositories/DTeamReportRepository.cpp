#include "DAL/src/Repositories/DTeamReportRepository.h"
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

DTeamReportRepository::DTeamReportRepository() = default;
DTeamReportRepository::~DTeamReportRepository() = default;


std::vector <DEntitiesAbstraction*> DTeamReportRepository::getAll()  {
    std::vector<DEntitiesAbstraction*> temp;
    for (std::size_t i = 0; i < m_CurrTeamReports.size(); i++) {
        temp.push_back(m_CurrTeamReports[i]);
    }

    return temp;
}

void DTeamReportRepository::create(DEntitiesAbstraction* currTeamReport) { 
    DTeamReport* tempTeamReport = dynamic_cast<DTeamReport*>(currTeamReport);
    tempTeamReport->setTeamReportID(getAll().size() + 1);
    tempTeamReport->setCreatedTime(std::time(nullptr));
    m_CurrTeamReports.push_back(tempTeamReport);
}

void DTeamReportRepository::deletee(const std::size_t currTeamReportID) { 

}
void DTeamReportRepository::update(DEntitiesAbstraction* newEntity, const std::size_t currTeamReportID) { 

}

void DTeamReportRepository::showEntitiesList() {

    std::cout << "TeamReportID" << "/" << "Name" << "/" << "CreatedTime"<< '\n'; 
    for (std::size_t i = 0; i < m_CurrTeamReports.size(); i++) {
        std::cout << m_CurrTeamReports[i]->getTeamReportID() << ' ' << m_CurrTeamReports[i]->getName() << ' ' << m_CurrTeamReports[i]->getCreatedTime() << '\n';
    }
    std::cout << "\n";
}