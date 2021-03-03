#include "UIL/ViewModels/TaskViewModel.h"

TaskViewModel::TaskViewModel(std::size_t authorID, std::string_view description, std::string_view name, std::string_view taskState) {
    m_Name = name;
    m_AuthorID = authorID;
    m_TaskState = taskState;
    m_Description = description;
}
TaskViewModel::~TaskViewModel();