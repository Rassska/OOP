#include "BLL/src/DTOEntities/DTWorker.h"

DTWorker::DTWorker(std::string_view name, std::size_t leaderID, std::vector <std::size_t> hierarchy, std::vector <std::size_t> tasks) {
    m_Hierarchy = hierarchy;
    m_Name = name;
    m_LeaderID = leaderID;
    m_TasksList = tasks;
    m_CreatedTime = std::time(nullptr);
    
}

DTWorker::~DTWorker();