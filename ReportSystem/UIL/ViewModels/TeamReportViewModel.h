#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "UIL/ViewModels/ReportViewModel.h"

class TeamReportViewModel 
{
    
private:
    //! std::size_t m_TeamReportID;
    //! time_t m_CreatedTime;

    std::string_view m_Description;
    std::string_view m_Name;
    std::vector <ReportViewModel*> m_ReportsList;
    
public:
    TeamReportViewModel(std::string_view name, std::string_view description, std::vector <ReportViewModel*> reports);
    ~TeamReportViewModel();
};