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

#include "backUpApp.h"
#include "ISaveAlgCreat.h"
#include "saveComm.h"
#include "saveSepAlg.h"
#include "delSizeAlg.h"
#include "delLengthAlg.h"
#include "delDateAlg.h"


backUpApp::backUpApp(const std::size_t backUpId){
    this->m_backUpId = backUpId;
}

void backUpApp::filesToBackUp(std::vector<std::string_view> givenFiles){
    for(std::size_t i = 0; i < givenFiles.size(); i++){
        this->m_currStorage.addToBackUp(givenFiles[i]);
    }
}

void backUpApp::createRestPoint(std::string_view restorePointType){
    this->m_currStorage.createRestPoint(restorePointType);
}

void backUpApp::saveRestPointAs(std::string_view givePoint){

    if(givePoint == "archive"){
        ISaveAlgCreat* saveAsArch = new CommonAlgorithm();
        saveAsArch->setPath(std::string("/home/rassska/dev/OOP/BackUpModel/"));
        saveAsArch->saveFiles(this->m_currStorage);
    } else if(givePoint == "folders"){
        ISaveAlgCreat* saveAsFolder = new SeparateAlgorithm();
        saveAsFolder->setPath(std::string("/home/rassska/dev/OOP/BackUpModel/"));
        saveAsFolder->saveFiles(this->m_currStorage);
    } else {
        throw std::runtime_error("Fail! Cannot save givenPoint!\n");
    }
}

void backUpApp::deleteFile(std::string_view fileName){
    m_currStorage.deleteFileFromBackUp(fileName);
}

void backUpApp::addFile(std::string_view fileName){
    m_currStorage.addToBackUp(fileName);
}


IDelAlgCreat* backUpApp::delAlg(std::string_view delAlgName){
    IDelAlgCreat* currDelAlg = nullptr;
    if(delAlgName == std::string("size")){
        std::size_t controlCnt;
        std::cin >> controlCnt;
        currDelAlg = new LengthAlg(controlCnt);
    } else if(delAlgName == std::string("length")){
        size_t sizeCnt;
        std::cin >> sizeCnt;
        currDelAlg = new SizeAlg(sizeCnt);
    } else if(delAlgName == "date") {
        time_t temp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now() + std::chrono::minutes(3)); 
        currDelAlg = new DateAlg(temp);
    } 

    if (currDelAlg != nullptr) {
        return currDelAlg;
    }
    else {
        throw std::runtime_error("Error! Cannot pick delAlg! \n");
    }
}

void backUpApp::controlRestorePointsAs(std::string_view controlType) {
    IDelAlgCreat* temp = nullptr;
    if(controlType != "hybrid"){
        if(delAlg(controlType) == nullptr) {
            throw std::runtime_error("Error! Algorithm does not yet exist within the function backUpApp::controlRPs().\n");
        }
    } else {
        std::size_t cntOfAlgs;
        std::cin >> cntOfAlgs;
        std::string currAlg;
        IDelAlgCreat* first, second;
        while(cntOfAlgs--){
            std::cout << "Input the name of the algorithm:\n";
            std::cin >> currAlg;
            first = delAlg(currAlg);
            second = first->mult(*first);
        }
        temp = &second;
    }

}