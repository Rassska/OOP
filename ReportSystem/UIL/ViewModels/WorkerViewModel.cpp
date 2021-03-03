#include "UIL/ViewModels/WorkerViewModel.h"

WorkerViewModel::WorkerViewModel(std::string_view name, std::size_t leaderID, std::vector <std::size_t> hierarchy, std::vector <std::size_t> tasks) {
    m_Hierarchy = hierarchy;
    m_Name = name;
    m_LeaderID = leaderID;
    m_TasksList = tasks;
    
}

std::string_view WorkerViewModel::getName() const {return m_Name;}
std::size_t WorkerViewModel::getLeaderID () const {return m_LeaderID;}
std::vector <std::size_t> WorkerViewModel::getHierarchy() const {return m_Hierarchy;}
std::vector <std::size_t> WorkerViewModel::getTasksList() const {return m_TasksList;}
WorkerViewModel::~WorkerViewModel() = default;