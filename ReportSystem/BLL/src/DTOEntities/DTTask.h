#pragma once
#include <iostream>
#include <string>
#include <vector>

class DTTask 
{
private:
    std::size_t m_TaskID;
    time_t m_CreatedTime;

    std::size_t m_AuthorID;
    std::string_view m_Description;
    std::string_view m_Name;
    std::string_view m_TaskState; 

public:
    DTTask(std::size_t authorID, std::string_view description, std::string_view name, std::string_view taskState);
    ~DTTask();
};