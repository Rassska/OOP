#include "BLL/src/DTOEntities/DTWorker.h"
#include <ctime>
DTWorker::DTWorker(std::string_view name, std::size_t leaderID, std::vector <std::size_t> hierarchy, std::vector <std::size_t> tasks) {
    m_Hierarchy = hierarchy;
    m_Name = name;
    m_LeaderID = leaderID;
    m_TasksList = tasks;
    m_CreatedTime = std::time(nullptr);
    
}

DTWorker::~DTWorker() = default;

std::string_view DTWorker::getName() const {return m_Name;}
std::size_t DTWorker::getLeaderID () const {return m_LeaderID;}
std::vector <std::size_t> DTWorker::getHierarchy() const {return m_Hierarchy;}
std::vector <std::size_t> DTWorker::getTasksList() const {return m_TasksList;}