#include "DAL/src/Entities/DReport.h"
#include <vector>
#include <iostream>
#include <string>


DReport::DReport () = default;


void DReport::setReportID(std::size_t currReportID) { m_ReportID = currReportID;}
void DReport::setCreatedTime(time_t currTime) {m_CreatedTime = currTime;}
void DReport::setFinishedTasksID(std::vector<std::size_t> currFinishedTasksID) {m_FinishedTasksID = currFinishedTasksID;}
void DReport::setAuthorId(std::size_t currAuthorID) {m_AuthorID = currAuthorID;}
void DReport::setComment(std::string_view currComment) {m_Comment = currComment;}

time_t DReport::getCreatedTime() const {return m_CreatedTime;}
std::vector<std::size_t> DReport::getFinishedTasksID() const {return m_FinishedTasksID;}
std::size_t DReport::getAuthorID() const {return m_AuthorID;}
std::string_view DReport::getComment() const {return m_Comment;}
std::size_t DReport::getReportID() const {return m_ReportID;}

DReport* DReport::operator=(const DReport* other) {
    m_AuthorID = other->m_AuthorID;
    m_Comment = other->m_Comment;
    m_CreatedTime = other->m_CreatedTime;
    m_ReportID = other->m_ReportID;
    m_FinishedTasksID = other->m_FinishedTasksID;
}

DReport::~DReport() = default;