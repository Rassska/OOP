#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "DAL/Abstractions/DRepositoriesAbstraction.h"
#include "DAL/src/Entities/DReport.h"

class DReportRepository : public DRepositoriesAbstraction
{
private:
    std::vector <DReport*> m_CurrReports;
public:
    DReportRepository();
    void create(DEntitiesAbstraction* currReport) override;
    void deletee(std::size_t currReportID) override;
    void update(DEntitiesAbstraction* newReport, std::size_t currReportID) override;
    std::vector <DEntitiesAbstraction*> getAll() override;
    DEntitiesAbstraction* getEntity(std::size_t entityID) override;
    void showEntitiesList() override;
    ~DReportRepository();
};