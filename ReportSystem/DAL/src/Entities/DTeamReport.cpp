#include "DAL/src/Entities/DTeamReport.h"
#include <iostream>
#include <string>
#include <vector>


DTeamReport::DTeamReport() = default;
DTeamReport::~DTeamReport() = default;


void DTeamReport::setTeamReportID(std::size_t teamReportID) {m_TeamReportID = teamReportID;}
void DTeamReport::setCreatedTime(time_t currCreatedTime) {m_CreatedTime = currCreatedTime;}
void DTeamReport::setDescription(std::string_view currDescription) {m_Description = currDescription;}
void DTeamReport::setName(std::string_view currName) {m_Name = currName;}
void DTeamReport::setReportList(std::vector<DReport> currReportList) {m_ReportsList = currReportList;}

std::size_t DTeamReport::getTeamReportID() const {return m_TeamReportID;}
time_t DTeamReport::getCreatedTime() const {return m_CreatedTime;}
std::string_view DTeamReport::getDescription() const {return m_Description;}
std::string_view DTeamReport::getName() const {return m_Name;}
std::vector<DReport> DTeamReport::getReportList() const {return m_ReportsList;}