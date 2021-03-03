#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "BLL/Abstractions/DTRepositoriesAbstraction.h"
#include "DAL/Abstractions/DEntitiesAbstraction.h"
#include "DAL/src/Entities/DReport.h"

class DTReportRepository : public DTRepositoriesAbstraction
{
private:
    std::vector <DReport*> m_currDALReports;
public:
    DTReportRepository();
    void create(DTEntitiesAbstraction* currReport) override;
    void deletee(std::size_t currReportID) override;
    void update(DTEntitiesAbstraction* newReport, std::size_t currReportID) override;

    std::vector <DTEntitiesAbstraction*> getAll() override;
    DTEntitiesAbstraction* getEntity(std::size_t entityID) override;
    
    void showEntitiesList() override;
    ~DTReportRepository();

};