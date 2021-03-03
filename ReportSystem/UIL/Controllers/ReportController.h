#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "BLL/src/Services/ReportService.h"
#include "UIL/ViewModels/TaskViewModel.h"
#include "UIL/ViewModels/ReportViewModel.h"
class ReportController
{
private:
    DTReportRepository m_Repo;
public:

    ReportController();
    void addReport(ReportViewModel* currReportViewModel);
    void showAllActiveReports();
    ~ReportController();
};


