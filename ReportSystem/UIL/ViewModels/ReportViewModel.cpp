#include "UIL/ViewModels/ReportViewModel.h"



ReportViewModel::ReportViewModel(std::size_t authorID, std::string_view comment, std::vector<std::size_t> finishedTasks) {
    m_AuthorID = authorID;
    m_Comment = comment;
    m_FinishedTasksID = finishedTasks;
}
    
ReportViewModel::~ReportViewModel();