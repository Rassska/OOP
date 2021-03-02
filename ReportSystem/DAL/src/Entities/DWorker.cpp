#include "DAL/src/Entities/DWorker.h"
#include <iostream>
#include <string>
#include <vector>


DWorker::DWorker() = default;
DWorker::~DWorker() = default;


void DWorker::setWorkerID(std::size_t currWorkerID) {m_WorkerID = currWorkerID;}
void DWorker::setCreatedTime(time_t currTime) {m_CreatedTime = currTime;}
void DWorker::setName(std::string_view currName) {m_Name = currName;}
void DWorker::setLeaderID(std::size_t currLeaderID) {m_LeaderID = currLeaderID;}
void DWorker::setHierarchy(std::vector<std::size_t> currHierarchy) {m_Hierarchy = currHierarchy;}
void DWorker::setTasksList(std::vector<std::size_t> currTasksList) {m_TasksList = currTasksList;}

std::size_t DWorker::getWorkerID() const {return m_WorkerID;}
time_t DWorker::getCreatedTime() const {return m_CreatedTime;}
std::string_view DWorker::getName() const {return m_Name;}
std::size_t DWorker::getLeaderID () const {return m_LeaderID;}
std::vector <std::size_t> DWorker::getHierarchy() const {return m_Hierarchy;}
std::vector <std::size_t> DWorker::getTasksList() const {return m_TasksList;}

DWorker* DWorker::operator=(const DWorker* other) {
    m_WorkerID = other->m_WorkerID;
    m_CreatedTime = other->m_CreatedTime;
    m_Name = other->m_Name;
    m_LeaderID = other->m_LeaderID;
    m_Hierarchy = other->m_Hierarchy;
    m_TasksList = other->m_TasksList;
}