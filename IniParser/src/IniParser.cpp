#include "IniParser.h"
#include <bits/stdc++.h>


inputFile::inputFile() = default;
inputFile::inputFile(const std::string& fileName, const std::string& filePath) : 
    fileName_(fileName), filePath_(filePath) {}
inputFile::~inputFile(){}

void inputFile::parseIniFile() {

    std::ifstream myIniFile;
    bool isIniFile = (filePath_.substr(filePath_.size() - 4, filePath_.size() - 1) == ".ini");
    
    if (!isIniFile) 
        throw std::runtime_error("Fail, invalid file format! Only allowed format like: \".ini\"\n");   
    
    myIniFile.open(filePath_);
    if (!myIniFile.is_open()) {
        throw std::runtime_error("Fail, file isn't existing\n"); 
    }

    std::string currLine = "*";

    std::string currSection = "*";
    std::string currArg = "*";
    std::string currArgValue = "*";

    std::regex sectionPattern("(\\[)" "([\\w]+)" "(\\])");
    std::regex argPattern("([\\w]+)" "([ ])");
    std::regex argValuePattern("([\\= ])" "([\\w\\.]+)");
    
    while(getline(myIniFile, currLine)) {
        bool isSection = std::regex_search(currLine.c_str(), sectionPattern);
        bool isArg = std::regex_search(currLine.c_str(), argPattern);

        if (isSection) {
            currSection = currLine.substr(1, currLine.size() - 2);

        } else if (isArg) {
            currLine.erase(std::min(currLine.find_first_of(';'), currLine.size()));
            currArg = currLine.substr(0, currLine.find_first_of('=') - 1);
            currArgValue = currLine.substr(currLine.find_first_of('=') + 2, currLine.size() - 1);
            currArgValue.erase(std::min(currArgValue.size(), currArgValue.find_last_of(' ')));
        
            storage_[currSection].emplace(currArg, currArgValue);
        }
    }
}
const std::string inputFile::getValue(const std::string& sectionName, const std::string& argName) {

    bool attemptToGetValue = false;
    std::string valueForGiving = "*";
    std::map<std::string, std::map<std::string, std::string>>::iterator it_ = storage_.begin();
    std::map<std::string, std::string>::iterator itInner_;
    
    while (it_ != storage_.end()) {
        if (it_->first ==  sectionName) {
            itInner_ = storage_[it_->first].begin();
            while(itInner_ != storage_[it_->first].end()) {
                if (itInner_->first == argName){
                    attemptToGetValue = true;
                    valueForGiving = itInner_->second;
                    break;
                }
                itInner_++;
            }
            if (attemptToGetValue)
                break;
        }
        it_++;
    }

    if (!attemptToGetValue){
        throw std::runtime_error("Fail!\n No matching section or argument found, please make sure that file getting path is right\n");
    } else {
        return valueForGiving;
    }
}
    
