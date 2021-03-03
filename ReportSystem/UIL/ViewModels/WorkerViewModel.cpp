#include "UIL/ViewModels/WorkerViewModel.h"

WorkerViewModel::WorkerViewModel(std::string_view name, std::size_t leaderID, std::vector <std::size_t> hierarchy, std::vector <std::size_t> tasks) {
    m_Hierarchy = hierarchy;
    m_Name = name;
    m_LeaderID = leaderID;
    m_TasksList = tasks;
    
}

WorkerViewModel::~WorkerViewModel() = default;