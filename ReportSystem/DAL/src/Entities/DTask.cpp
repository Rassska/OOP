#include "DAL/src/Entities/DTask.h"
#include <iostream>
#include <string>
#include <vector>


DTask::DTask(std::size_t authorID, std::string_view description, std::string_view name, std::string_view taskState) {
    m_AuthorID = authorID;
    m_Description = description;
    m_Name = name;
    m_TaskState = taskState;
}
DTask::~DTask() = default;

void DTask::setTaskID(std::size_t currTaskID) {m_TaskID = currTaskID;}
void DTask::setCreatedTime(time_t currCreatedTime) {m_CreatedTime = currCreatedTime;}
void DTask::setAuthorID(std::size_t currAuthorID) {m_AuthorID = currAuthorID;}
void DTask::setDescription(std::string_view currDescription) { m_Description = currDescription;}
void DTask::setName(std::string_view currName) { m_Name = currName;}
void DTask::setTaskState(std::string_view currTaskState) { m_TaskState = currTaskState;}

std::size_t DTask::getTaskID() const {return m_TaskID;}
time_t DTask::getCreatedTime() const {return m_CreatedTime;}
std::size_t DTask::getAuthorID() const {return m_AuthorID;}
std::string_view DTask::getTaskDescription() const {return m_Description;}
std::string_view DTask::getTaskName() const {return m_Name;}
std::string_view DTask::getTaskState() const {return m_TaskState;}

DTask* DTask::operator=(const DTask* other) {
    m_AuthorID = other->m_AuthorID;
    m_TaskID = other->m_TaskID;
    m_CreatedTime = other->m_CreatedTime;
    m_Name = other->m_Name;
    m_Description = other->m_Description;
    m_TaskState = other->m_TaskState;
}