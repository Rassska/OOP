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

#include "newFF.h"
#include "file.h"


newFF::newFF(restorePoint* restorePointParent){
    this->m_restorePointParent = restorePointParent;
    this->m_restorePointName = "newFF";
    this->m_currentId = ++m_restorePointId;
    this->m_restorePointTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now() + std::chrono::minutes(m_currentId));
}

void newFF::addFileToRestorePoint(file giveFile){
    if(giveFile.getFileName().find_first_of('_') == std::string::npos){
        std::string newName = giveFile.getFileName().substr(0, giveFile.getFileName().find_last_of('.')) + "_" + std::to_string(m_currentId);
        std::string fileFormat = giveFile.getFileName().substr(giveFile.getFileName().find_last_of('.'));
        giveFile.setFileName(newName + fileFormat);
    } else{
        std::string newName = giveFile.getFileName().substr(0, giveFile.getFileName().find_first_of('_') + 1) + std::to_string(m_currentId);
        std::string fileFormat = giveFile.getFileName().substr(giveFile.getFileName().find_last_of('.'));
        giveFile.setFileName(newName + fileFormat);
    }
    m_filesRestorePoints.push_back(giveFile);
}

std::size_t newFF::setRestorePointSize(const restorePoint* restorePoint, std::string_view restorePointName){
    for(std::size_t i = 0; i < m_filesRestorePoints.size(); i++) {  
        if(m_filesRestorePoints[i].getFileName().substr(0, m_filesRestorePoints[i].getFileName().find_first_of('_')) == restorePointName) {
            return m_filesRestorePoints[i].getFileSize();
        }
    }
    return 0;
}


