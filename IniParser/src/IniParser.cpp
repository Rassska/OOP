#include "IniParser.h"
#include <bits/stdc++.h>


inputFile::inputFile() = default;



inputFile::inputFile(std::string_view fileName, std::string_view filePath) : 
    fileName_(fileName), filePath_(filePath) {}
inputFile::~inputFile(){}

void inputFile::parseIniFile() {

    std::ifstream myIniFile;
    std::string_view filePathView = filePath_;
    bool isIniFile = (filePathView.substr(filePath_.size() - 4, filePath_.size() - 1) == ".ini");
    
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

    size_t numberOfLine = 0;

    std::regex sectionPattern("(\\[)" "([\\w]+)" "(\\])");
    std::regex argValuePattern("([\\w]+)" "([' '])" "\\=" "([' '])" "([\\w\\.\\/]+)");
    
    while(getline(myIniFile, currLine)) {

        numberOfLine++;
        if (currLine.find_first_of(';') != std::string::npos) {
            currLine.erase(currLine.find_first_of(';')); // refusing comments
        }
        
        
        bool isSection = std::regex_match(currLine.c_str(), sectionPattern);
        bool isArg = std::regex_match(currLine.c_str(), argValuePattern);
        bool isGap = (currLine.size() == 0);

        if (isSection) {
            currSection = currLine.substr(1, currLine.size() - 2);
        } else if (isArg) {
            currArg = currLine.substr(0, currLine.find_first_of('=') - 1);
            currArgValue = currLine.substr(currLine.find_first_of('=') + 2);

            storage_[currSection].emplace(currArg, currArgValue);
        }
        
        if (!isSection && !isArg && !isGap) {
            throw std::runtime_error("Fail, file was corrupted on the line: " + std::to_string(numberOfLine));
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
    
