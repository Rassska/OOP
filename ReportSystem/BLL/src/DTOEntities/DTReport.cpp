#include "BLL/src/DTOEntities/DTReport.h"
#include <ctime>


DTReport::DTReport(std::size_t authorID, std::string_view comment, std::vector<std::size_t> finishedTasks) {
    m_AuthorID = authorID;
    m_Comment = comment;
    m_FinishedTasksID = finishedTasks;
    m_CreatedTime = std::time(nullptr);
}

time_t DTReport::getCreatedTime() const {return m_CreatedTime;}
std::vector<std::size_t> DTReport::getFinishedTasksID() const {return m_FinishedTasksID;}
std::size_t DTReport::getAuthorID() const {return m_AuthorID;}
std::string_view DTReport::getComment() const {return m_Comment;}
std::size_t DTReport::getReportID() const {return m_ReportID;}
    
DTReport::~DTReport() = default;