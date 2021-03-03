#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BLL/src/DTOEntities/DTReport.h"
#include "BLL/Abstractions/DTEntitiesAbstraction.h"

class DTTeamReport : public DTEntitiesAbstraction
{
    
private:
    std::size_t m_TeamReportID;
    time_t m_CreatedTime;

    std::string_view m_Description;
    std::string_view m_Name;
    std::vector <DTReport*> m_ReportsList;
    
public:
    DTTeamReport(std::string_view name, std::string_view description, std::vector <DTReport*> reports);

    std::vector <DTReport*> getReportList() const;
    std::string_view getName() const;
    std::string_view getDescription() const;
    
    ~DTTeamReport();
};