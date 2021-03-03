#include "BLL/src/DTOEntities/DTTask.h"
#include <ctime>
DTTask::DTTask(std::size_t authorID, std::string_view description, std::string_view name, std::string_view taskState) {
    m_Name = name;
    m_AuthorID = authorID;
    m_TaskState = taskState;
    m_Description = description;
    m_CreatedTime = std::time(nullptr);
}
DTTask::~DTTask() = default;

std::size_t DTTask::getAuthorID() const {return m_AuthorID;}
std::string_view DTTask::getTaskDescription() const {return m_Description;}
std::string_view DTTask::getTaskName() const {return m_Name;}
std::string_view DTTask::getTaskState() const {return m_TaskState;}