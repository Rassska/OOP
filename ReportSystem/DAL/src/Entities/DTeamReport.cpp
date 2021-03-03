#include "DAL/src/Entities/DTeamReport.h"
#include <iostream>
#include <string>
#include <vector>
#include "DAL/src/Entities/DReport.h"


DTeamReport::DTeamReport(std::string_view name, std::string_view description, std::vector <DTeamReport> reports) {
    m_Name = name;
    m_Description = description;
    m_ReportsList = reports;
}
DTeamReport::~DTeamReport() = default;


void DTeamReport::setTeamReportID(std::size_t teamReportID) {m_TeamReportID = teamReportID;}
void DTeamReport::setCreatedTime(time_t currCreatedTime) {m_CreatedTime = currCreatedTime;}
void DTeamReport::setDescription(std::string_view currDescription) {m_Description = currDescription;}
void DTeamReport::setName(std::string_view currName) {m_Name = currName;}
void DTeamReport::setReportList(std::vector<DTeamReport> currReportList) {m_ReportsList = currReportList;}

std::size_t DTeamReport::getTeamReportID() const {return m_TeamReportID;}
time_t DTeamReport::getCreatedTime() const {return m_CreatedTime;}
std::string_view DTeamReport::getDescription() const {return m_Description;}
std::string_view DTeamReport::getName() const {return m_Name;}
std::vector<DTeamReport> DTeamReport::getReportList() const {return m_ReportsList;}

DTeamReport* DTeamReport::operator=(const DTeamReport* other) {
    m_ReportsList = other->m_ReportsList;
    m_TeamReportID = other->m_TeamReportID;
    m_CreatedTime = other->m_CreatedTime;
    m_Name = other->m_Name;
    m_Description = other->m_Description;
}