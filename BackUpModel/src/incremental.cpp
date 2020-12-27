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

#include "incremental.h"
#include "file.h"
#include "IDelAlgCreat.h"


incremental::incremental(restorePoint* restorePointParent){
    this->m_restorePointName = "dd";
    this->m_restorePointParent = restorePointParent;
    this->m_currentId = ++m_restorePointId;
    this->m_restorePointTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now() + std::chrono::minutes(m_currentId));
}

void incremental::addFileToRestorePoint(file currFile) {
    if(currFile.getFileName().find_first_of('_') == std::string::npos){
        std::string newName = currFile.getFileName().substr(0, currFile.getFileName().find_last_of('.')) + "_" + std::to_string(m_currentId);
        std::string extension = currFile.getFileName().substr(currFile.getFileName().find_last_of('.'));
        currFile.setFileName(newName + extension);
    } else{
        std::string newName = currFile.getFileName().substr(0, currFile.getFileName().find_first_of('_') + 1) +  std::to_string(m_currentId);
        std::string extension = currFile.getFileName().substr(currFile.getFileName().find_last_of('.'));
        currFile.setFileName(newName + extension);
    }
    std::string newName = currFile.getFileName().substr(0, currFile.getFileName().find_last_of('_'));
    std::size_t size = setRestorePointSize(m_restorePointParent, newName);
    currFile.setFileSize(abs(currFile.getSizeFile() - size)); // this is so-called delta
    if(currFile.getFileSize() != 0) m_filesRestorePoints.push_back(currFile);
}

std::size_t incremental::setRestorePointSize(const restorePoint* restorePoint, std::string_view restorePointName){

    if(restorePoint->findFile(restorePointName) == false) {
        return setRestorePointSize(restorePoint->getRestorePointParent(), restorePointName);
    }
    if(restorePoint->getRestorePointName() == "newFF") { 
        return restorePoint->getFile(restorePointName).getFileSize();
    } else { 
        return restorePoint->getFile(restorePointName).getSizeFile() + setRestorePointSize(restorePoint->getRestorePointParent(), restorePointName);
    }
}