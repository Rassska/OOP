#pragma once
#include <iostream>
#include <string>
#include <vector>


class ReportViewModel
{
protected:
    //! std::size_t m_ReportID;
    //! time_t m_CreatedTime;

    std::vector<std::size_t> m_FinishedTasksID;
    std::size_t m_AuthorID;
    std::string_view m_Comment;

public:
    ReportViewModel(std::size_t authorID, std::string_view comment, std::vector<std::size_t> finishedTasks);
    
    ~ReportViewModel();
};
