#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "UIL/ViewModels/ReportViewModel.h"
#include "UIL/ViewModels/TeamReportViewModel.h"
#include "BLL/src/Services/TeamReportService.h"

class TeamReportController
{
private:
    DTTeamReportRepository m_Repo;
public:
    TeamReportController();
    void addTeamReport(TeamReportViewModel* currTeamReport);
    void showTeamReports();
    ~TeamReportController();
};