#include "UIL/ViewModels/TeamReportViewModel.h"



TeamReportViewModel::TeamReportViewModel(std::string_view name, std::string_view description, std::vector <DReport> reports){
    m_Name = name;
    m_Description = description;
    m_ReportsList = reports;
}
    
TeamReportViewModel::~TeamReportViewModel();