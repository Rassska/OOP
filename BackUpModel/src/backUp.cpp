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
#include "backUp.h"
#include "incremental.h"
#include "restorePoint.h"
#include "IDelAlgCreat.h"

void BackUp::addToBackUp(std::string_view inputFile){
    std::string temp = {inputFile.begin(), inputFile.end()};
    std::ifstream myFile(temp);
    if(!myFile.is_open())
        throw std::runtime_error("Fail! File does not exist!\n");

    file currFile(temp);
    this->m_backUpOfFiles.push_back(currFile);
}

BackUp::BackUp(){
    this->m_createTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

void BackUp::createRestPoint(std::string_view restorePointType){
    restorePoint* currPoint;
    if(this->m_restorePointList.size() != 0) {
        currPoint = m_restorePointList.back();
    }
    else {
        currPoint = nullptr;
    } 

    if(restorePointType == "newFF"){ // newFF - totally changing
        restorePoint* restPoint = new newFF(currPoint);
        for(std::size_t i = 0; i < m_backUpOfFiles.size(); i++){
            restPoint->addFileToRestorePoint(m_backUpOfFiles[i]);
        }
        this->m_restorePointList.push_back(restPoint);

    } else if(restorePointType == "dd"){  // dd - changing for delta
        restorePoint* restPoint = new incremental(currPoint);
        for(std::size_t i = 0; i < m_backUpOfFiles.size(); i++){
            restPoint->addFileToRestorePoint(m_backUpOfFiles[i]);
        }
        this->m_restorePointList.push_back(restPoint);

    } else {
        throw std::runtime_error("Fail! Type of rest Point is undefined!\n");
    }
}



void BackUp::deleteFileFromBackUp(std::string_view inputFile){
    bool check = false;
    for(std::size_t i = 0; i < m_backUpOfFiles.size(); i++){
        std::string_view newName = (m_backUpOfFiles[i].getFileName()).substr(0, m_backUpOfFiles[i].getFileName().find('.'));
        if(newName == inputFile) {
            check = true; 
            m_backUpOfFiles.erase(m_backUpOfFiles.begin() + i);
            break;
        } 
    }
    if(!check) { 
        throw std::runtime_error("Fail! Cannot find the file with this name to delete!\n");
    } else {
        for(std::size_t i = 0; i < m_restorePointList.size(); i++) {
            m_restorePointList[i]->deleteFile(inputFile);
        }
    }
}

std::size_t BackUp::getRestorePointsSize() const{
    std::size_t ans = 0;
    for(std::size_t i = 0; i < m_restorePointList.size(); i++) {
        ans += m_restorePointList[i]->getRestorePointSize();
    }
    return ans;
}

const std::vector<restorePoint*> BackUp::getAlllRestorePointsPointer() const{
    return this->m_restorePointList;
}