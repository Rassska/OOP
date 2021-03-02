#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DAL/Abstractions/DRepositoriesAbstraction.h"
#include "DAL/src/Entities/DTeamReport.h"

class DTeamReportRepository : public DRepositoriesAbstraction
{
private:
    std::vector <DTeamReport*> m_CurrTeamReports;
public:
    DTeamReportRepository();
    void create(DEntitiesAbstraction* currTeamReport) override;
    void deletee(const std::size_t currTeamReportID) override;
    void update(DEntitiesAbstraction* newEntity, const std::size_t currTeamReportID) override;
    std::vector <DEntitiesAbstraction*> getAll() override;
    void showEntitiesList() override;
    ~DTeamReportRepository();
};