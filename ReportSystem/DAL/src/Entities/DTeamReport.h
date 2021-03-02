#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DAL/Abstractions/DEntitiesAbstraction.h"
#include "DAL/src/Entities/DReport.h"

class DTeamReport : public DEntitiesAbstraction
{
    
private:
    std::size_t m_TeamReportID;
    
    time_t m_CreatedTime;
    std::string_view m_Description;
    std::string_view m_Name;
    std::vector <DReport> m_ReportsList;
    
public:
    DTeamReport();

    void setTeamReportID(std::size_t teamReportID);
    void setCreatedTime(time_t currCreatedTime);
    void setDescription(std::string_view currDescription);
    void setName(std::string_view currName);
    void setReportList(std::vector<DReport> currReportList);

    std::size_t getTeamReportID() const;
    time_t getCreatedTime() const;
    std::string_view getDescription() const;
    std::string_view getName() const;
    std::vector<DReport> getReportList() const;
    

    ~DTeamReport();
};