#include "BLL/src/DTOEntities/DTTeamReport.h"
#include <ctime>


DTTeamReport::DTTeamReport(std::string_view name, std::string_view description, std::vector <DTReport*> reports){
    m_Name = name;
    m_Description = description;
    m_ReportsList = reports;
    m_CreatedTime = std::time(nullptr);
}
    
DTTeamReport::~DTTeamReport() = default;

std::vector <DTReport*> DTTeamReport::getReportList() const {return m_ReportsList;}
std::string_view DTTeamReport::getName() const {return m_Name;}
std::string_view DTTeamReport::getDescription() const {return m_Description;}