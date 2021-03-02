#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DAL/Abstractions/DEntitiesAbstraction.h"

class DTask : public DEntitiesAbstraction
{
private:
    std::size_t m_TaskID;
    
    time_t m_CreatedTime;
    std::size_t m_AuthorID;
    std::string_view m_Description;
    std::string_view m_Name;
    std::string_view m_TaskState; 

public:
    DTask();
    void setTaskID(std::size_t currTaskID);
    void setCreatedTime(time_t currCreatedTime);
    void setAuthorID(std::size_t currAuthorID);
    void setDescription(std::string_view currDescription);
    void setName(std::string_view currName);
    void setTaskState(std::string_view currTaskState);

    std::size_t getTaskID() const;
    time_t getCreatedTime() const;
    std::size_t getAuthorID() const;
    std::string_view getTaskDescription() const;
    std::string_view getTaskName() const;
    std::string_view getTaskState() const;
    
    ~DTask();
};