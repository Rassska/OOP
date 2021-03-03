#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "BLL/Abstractions/DTRepositoriesAbstraction.h"
#include "DAL/Abstractions/DEntitiesAbstraction.h"
#include "DAL/src/Entities/DTeamReport.h"
#include "DAL/src/Repositories/DTeamReportRepository.h"
class DTTeamReportRepository : public DTRepositoriesAbstraction
{
private:
    DTeamReportRepository currDALTeamReportRepo;
public:
    DTTeamReportRepository();
    void create(DTEntitiesAbstraction* currTeamReport) override;
    void deletee(std::size_t currTeamReportID) override;
    void update(DTEntitiesAbstraction* newTeamReport, std::size_t currTeamReportID) override;

    std::vector <DTEntitiesAbstraction*> getAll() override;
    DTEntitiesAbstraction* getEntity(std::size_t entityID) override;
    
    void showEntitiesList() override;
    ~DTTeamReportRepository();

};