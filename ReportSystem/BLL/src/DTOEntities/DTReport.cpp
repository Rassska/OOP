#include "BLL/src/DTOEntities/DTReport.h"



DTReport::DTReport(std::size_t authorID, std::string_view comment, std::vector<std::size_t> finishedTasks) {
    m_AuthorID = authorID;
    m_Comment = comment;
    m_FinishedTasksID = finishedTasks;
    m_CreatedTime = std::time(nullptr);
}
    
DTReport::~DTReport();