#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DAL/Abstractions/DEntitiesAbstraction.h"

class DReport : public DEntitiesAbstraction
{
protected:
    std::size_t m_ReportID;

    time_t m_CreatedTime;
    std::vector<std::size_t> m_FinishedTasksID;
    std::size_t m_AuthorID;
    std::string_view m_Comment;

public:
    DReport();
    void setReportID(std::size_t currReportID);
    void setCreatedTime(time_t currTime);
    void setFinishedTasksID(std::vector<std::size_t> currFinishedTasksID);
    void setAuthorId(std::size_t currAuthorID);
    void setComment(std::string_view currComment);

    std::size_t getReportID() const;
    time_t getCreatedTime() const;
    std::vector<std::size_t> getFinishedTasksID() const;
    std::size_t getAuthorID() const;
    std::string_view getComment() const;
    
    ~DReport();
};
