#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctime>
#include <unordered_map>
#include <list>
#include <map>
#include <ctime>
#include <filesystem>
#include <utility>
#include <functional>

#include "restorePoint.h"
#include "file.h"

std::size_t restorePoint::m_restorePointId = 0;

restorePoint::~restorePoint() = default;

void restorePoint::deleteFile(std::string_view givenFile){
    this->m_filesRestorePoints.erase(std::remove_if(this->m_filesRestorePoints.begin(), this->m_filesRestorePoints.end(), [&givenFile](::file& currFile)->bool
    {
        return currFile.getFileName().substr(0, currFile.getFileName().find_last_of('_')) == givenFile;
    }), m_filesRestorePoints.end());
}

bool restorePoint::findFile(std::string_view fileName) const{
    for(std::size_t i = 0; i < m_filesRestorePoints.size(); i++){
        if(this->m_filesRestorePoints[i].getFileName().substr(0, this->m_filesRestorePoints[i].getFileName().find_first_of('_')) == fileName) {
            return true;
        }
    }
    return false;
}

restorePoint* restorePoint::getRestorePointParent() const{
    return this->m_restorePointParent;
}

file restorePoint::getFile(std::string_view fileName) const{
    for(std::size_t i = 0; i < m_filesRestorePoints.size(); i++){
        if(m_filesRestorePoints[i].getFileName().substr(0, m_filesRestorePoints[i].getFileName().find_first_of('_')) == fileName) {
            return m_filesRestorePoints[i];
        }
    }
    throw std::runtime_error("Error! Have no permission to get this\n");
}

std::string_view restorePoint::getRestorePointName() const{
    return this->m_restorePointName;
}

const std::vector<file>& restorePoint::getRestorePointFiles() const{
    return this->m_filesRestorePoints;
}

std::size_t restorePoint::getRestorePointId()const{
    return this->m_restorePointId;
}

std::size_t restorePoint::getRestorePointSize() const{
    std::size_t ans = 0;
    for(std::size_t i = 0; i < m_filesRestorePoints.size(); i++) {
        ans += m_filesRestorePoints[i].getFileSize();
    }
    return ans;
}

time_t restorePoint::getRestorePointTime() const{
    return this->m_restorePointTime;
}
