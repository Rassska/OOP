#pragma once
#include <iostream>
#include <string>
#include <vector>


class DTReport
{
protected:
    std::size_t m_ReportID;
    time_t m_CreatedTime;

    std::vector<std::size_t> m_FinishedTasksID;
    std::size_t m_AuthorID;
    std::string_view m_Comment;

public:
    DTReport(std::size_t authorID, std::string_view comment, std::vector<std::size_t> finishedTasks);
    std::size_t getReportID() const;
    time_t getCreatedTime() const;
    std::vector<std::size_t> getFinishedTasksID() const;
    std::size_t getAuthorID() const;
    std::string_view getComment() const;
    ~DTReport();
};
