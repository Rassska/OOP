#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DAL/Abstractions/DEntitiesAbstraction.h"


class DWorker : public DEntitiesAbstraction
{
private:
    std::size_t m_WorkerID;
    
    time_t m_CreatedTime;
    std::string_view m_Name;
    std::size_t m_LeaderID;
    std::vector <std::size_t> m_Hierarchy;
    std::vector <std::size_t> m_TasksList;
    
public:
    DWorker();

    void setWorkerID(std::size_t currWorkerID);
    void setCreatedTime(time_t currTime);
    void setName(std::string_view currName);
    void setLeaderID(std::size_t currLeaderID);
    void setHierarchy(std::vector<std::size_t> currHierarchy);
    void setTasksList(std::vector<std::size_t> currTasksList);

    DWorker* operator=(const DWorker* other);
    std::size_t getWorkerID() const;
    time_t getCreatedTime() const;
    std::string_view getName() const;
    std::size_t getLeaderID () const;
    std::vector <std::size_t> getHierarchy() const;
    std::vector <std::size_t> getTasksList() const;
    ~DWorker();
};