#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BLL/Abstractions/DTEntitiesAbstraction.h"

class DTWorker : public DTEntitiesAbstraction
{
private:
    std::size_t m_WorkerID;
    time_t m_CreatedTime;

    std::string_view m_Name;
    std::size_t m_LeaderID;
    std::vector <std::size_t> m_Hierarchy;
    std::vector <std::size_t> m_TasksList;
    
public:

    DTWorker(std::string_view name, std::size_t leaderID, std::vector <std::size_t> hierarchy, std::vector <std::size_t> tasks);
    std::string_view getName() const;
    std::size_t getLeaderID () const;
    std::vector <std::size_t> getHierarchy() const;
    std::vector <std::size_t> getTasksList() const;
    ~DTWorker();
};