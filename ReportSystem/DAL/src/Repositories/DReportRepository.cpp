#include "DAL/src/Repositories/DReportRepository.h"
#include "DAL/src/Entities/DReport.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <ctime>

DReportRepository::DReportRepository() = default;
DReportRepository::~DReportRepository() = default;



std::vector <DEntitiesAbstraction*> DReportRepository::getAll() {
    std::vector<DEntitiesAbstraction*> temp;

    for (std::size_t i = 0; i < m_CurrReports.size(); i++) {
        temp.push_back(m_CurrReports[i]);
    }
    return temp;
}

void DReportRepository::create(DEntitiesAbstraction* currReport) {

    DReport* currRep = dynamic_cast<DReport*>(currReport);
    currRep->setReportID(getAll().size() + 1);
    currRep->setCreatedTime(std::time(nullptr));

    m_CurrReports.push_back(currRep);
}

void DReportRepository::deletee(std::size_t currReportID) {
    std::size_t currIndex = 0;
    bool flag = false;
    
    for (std::size_t i = 0; i < m_CurrReports.size(); i++) {
        if (m_CurrReports[i]->getReportID() == currReportID) {
            m_CurrReports.erase(m_CurrReports.begin() + i);
            currIndex = i;
            flag = true;
        }
        if (flag) {
            for (std::size_t i = currIndex; i < m_CurrReports.size(); i++) {
                m_CurrReports[i]->setReportID(m_CurrReports[i]->getReportID() - 1);
            }
            break;
        }
    }

}

void DReportRepository::update(DEntitiesAbstraction* newReport, const std::size_t currReportID) {
    DReport* currNewReport = dynamic_cast<DReport*>(newReport);

    if (currNewReport != nullptr) { 
        for (std::size_t i = 0; i < m_CurrReports.size(); i++) {
            if (m_CurrReports[i]->getReportID() == currReportID) {
                m_CurrReports[i] = currNewReport;
            }
        }
    }

}   

DEntitiesAbstraction* DReportRepository::getEntity(std::size_t entityID) { 

    DEntitiesAbstraction* temp = nullptr;
    for (std::size_t i = 0; i < m_CurrReports.size(); i++) {
        if (m_CurrReports[i]->getReportID() == entityID) {
            temp = m_CurrReports[i];
            break;
        }
    }
    return temp;
} 
void DReportRepository::showEntitiesList() {

    std::cout << "ReportID" << "/" << "AuthorID" << "/" << "CreatedTime" << '\n';
    for (std::size_t i = 0; i < m_CurrReports.size(); i++) {
        std::cout << m_CurrReports[i]->getReportID() << ' ' << m_CurrReports[i]->getAuthorID() << ' ' << m_CurrReports[i]->getCreatedTime() << '\n';
    }
}


