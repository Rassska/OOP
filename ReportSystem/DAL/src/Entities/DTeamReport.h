#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DAL/Abstractions/DEntitiesAbstraction.h"
#include "DAL/src/Entities/DTeamReport.h"

class DTeamReport : public DEntitiesAbstraction
{
    
private:
    std::size_t m_TeamReportID;
    
    time_t m_CreatedTime;
    std::string_view m_Description;
    std::string_view m_Name;
    std::vector <DTeamReport> m_ReportsList;
    
public:
    DTeamReport(std::string_view name, std::string_view description, std::vector <DTeamReport> reports);

    void setTeamReportID(std::size_t teamReportID);
    void setCreatedTime(time_t currCreatedTime);
    void setDescription(std::string_view currDescription);
    void setName(std::string_view currName);
    void setReportList(std::vector<DTeamReport> currReportList);

    
    DTeamReport* operator=(const DTeamReport* other);
    std::size_t getTeamReportID() const;
    time_t getCreatedTime() const;
    std::string_view getDescription() const;
    std::string_view getName() const;
    std::vector<DTeamReport> getReportList() const;
    

    ~DTeamReport();
};