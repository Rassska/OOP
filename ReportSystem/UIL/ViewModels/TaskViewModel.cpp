#include "UIL/ViewModels/TaskViewModel.h"

TaskViewModel::TaskViewModel(std::size_t authorID, std::string_view description, std::string_view name, std::string_view taskState) {
    m_Name = name;
    m_AuthorID = authorID;
    m_TaskState = taskState;
    m_Description = description;
}


std::size_t TaskViewModel::getAuthorID() const {return m_AuthorID;}
std::string_view TaskViewModel::getTaskDescription() const {return m_Description;}
std::string_view TaskViewModel::getTaskName() const {return m_Name;}
std::string_view TaskViewModel::getTaskState() const {return m_TaskState;}

TaskViewModel::~TaskViewModel() = default;