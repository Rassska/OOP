#pragma once
#include <iostream>
#include <string>
#include <vector>

class TaskViewModel 
{
private:
    //! std::size_t m_TaskID;
    //! time_t m_CreatedTime;

    std::size_t m_AuthorID;
    std::string_view m_Description;
    std::string_view m_Name;
    std::string_view m_TaskState; 

public:
    TaskViewModel(std::size_t authorID, std::string_view description, std::string_view name, std::string_view taskState);

    std::size_t getAuthorID() const;
    std::string_view getTaskDescription() const;
    std::string_view getTaskName() const;
    std::string_view getTaskState() const;

    ~TaskViewModel();
};