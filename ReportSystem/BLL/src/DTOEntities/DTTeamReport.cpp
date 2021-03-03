#include "BLL/src/DTOEntities/DTTeamReport.h"
#include <ctime>


DTTeamReport::DTTeamReport(std::string_view name, std::string_view description, std::vector <DTReport*> reports){
    m_Name = name;
    m_Description = description;
    m_ReportsList = reports;
    m_CreatedTime = std::time(nullptr);
}
    
DTTeamReport::~DTTeamReport() = default;