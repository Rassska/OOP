#include "UIL/ViewModels/TeamReportViewModel.h"
#include <iostream>



TeamReportViewModel::TeamReportViewModel(std::string_view name, std::string_view description, std::vector <ReportViewModel*> reports) {
    m_Name = name;
    m_Description = description;
    m_ReportsList = reports;
}
    
TeamReportViewModel::~TeamReportViewModel() = default;