#include "UIL/ViewModels/TeamReportViewModel.h"
#include <iostream>



TeamReportViewModel::TeamReportViewModel(std::string_view name, std::string_view description, std::vector <ReportViewModel*> reports) {
    m_Name = name;
    m_Description = description;
    
    m_ReportsList = reports;
}
    
TeamReportViewModel::~TeamReportViewModel() = default;

std::vector <ReportViewModel*> TeamReportViewModel::getReportList() const {return m_ReportsList;}
std::string_view TeamReportViewModel::getName() const {return m_Name;}
std::string_view TeamReportViewModel::getDescription() const {return m_Description;}