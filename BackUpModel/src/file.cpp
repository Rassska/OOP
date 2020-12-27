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

#include "file.h"

file::file(){}

file::file(std::string fileName){
    std::ifstream currFile(fileName);
    if(!currFile.is_open()) { 
        throw std::runtime_error("Error! Constructor could not find the given file!\n");
    }

    this->m_filePath = fileName.substr(0, (fileName.find_last_of('/')) + 1);
    this->m_fileName = fileName.substr(fileName.find_last_of('/') + 1);
    this->m_fileTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now() - std::chrono::minutes(1)); 
    this->m_fileSize = currFile.tellg();
}

file::~file(){}
 
std::size_t file::getSizeFile()const{
    std::string fileFormat = this->getFileName().substr(this->getFileName().find_last_of('.'));
    std::string fileName;
    if(getFileName().find('_') != std::string::npos) {
        fileName = this->getFileName().substr(0, this->getFileName().find('_'));
    }
    else  {
        fileName = this->getFileName().substr(0, this->getFileName().find_last_of('.'));
    }
    std::ifstream currFile(this->getFilePath() + fileName + fileFormat, std::ifstream::ate);
    if(!currFile.is_open()) {
        throw std::runtime_error("Error! Could not find the file!\n");
    }
    return currFile.tellg();
}

std::string file::getFileTimeAsCtime() const{ return ctime(&m_fileTime);}
std::string file::getFileName()const{ return this->m_fileName;}
std::string file::getFilePath()const{ return this->m_filePath;}
std::size_t file::getFileSize()const{ return this->m_fileSize;}
time_t file::getFileTime() const { return this->m_fileTime;}

void file::setFileSize(std::size_t givenSize){ this->m_fileSize = givenSize;}
void file::setFileName(std::string newFileName){ this->m_fileName = newFileName;}
void file::setFileTime(time_t newFileTime){ this->m_fileTime = newFileTime;}
void file::setFilePath(std::string newFilePath){ this->m_filePath = newFilePath;}
