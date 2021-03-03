#include "UIL/ViewModels/ReportViewModel.h"



ReportViewModel::ReportViewModel(std::size_t authorID, std::string_view comment, std::vector<std::size_t> finishedTasks) {
    m_AuthorID = authorID;
    m_Comment = comment;
    m_FinishedTasksID = finishedTasks;
}
    
ReportViewModel::~ReportViewModel() = default;

std::vector<std::size_t> ReportViewModel::getFinishedTasksID() const {return m_FinishedTasksID;}
std::size_t ReportViewModel::getAuthorID() const {return m_AuthorID;}
std::string_view ReportViewModel::getComment() const {return m_Comment;}