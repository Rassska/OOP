#include "IniParser.h"
#include <bits/stdc++.h>


inputFile::inputFile() = default;
inputFile::inputFile(std::string fileName, std::string filePath) : 
    fileName_(fileName), filePath_(filePath) {}
inputFile::~inputFile(){}


inputFile::expWrongFileDirectory::expWrongFileDirectory(std::string bugInfo, int bugCode) :
    bugInfo_(bugInfo), bugCode_(bugCode){}

inputFile::expWrongFileFormat::expWrongFileFormat(std::string bugInfo, int bugCode) :
    bugInfo_(bugInfo), bugCode_(bugCode){} 

inputFile::expTypeIsNotAvailable::expTypeIsNotAvailable(std::string bugInfo, int bugCode) :
    bugInfo_(bugInfo), bugCode_(bugCode){}

inputFile::expValueIsNotAvailable::expValueIsNotAvailable(std::string bugInfo, int bugCode) :
    bugInfo_(bugInfo), bugCode_(bugCode){} 

inputFile::expWrongNamed::expWrongNamed(std::string bugInfo, int bugCode) :
    bugInfo_(bugInfo), bugCode_(bugCode){} 

inputFile::expWrongFileDirectory::expWrongFileDirectory() = default;
inputFile::expWrongFileFormat::expWrongFileFormat()= default;
inputFile::expValueIsNotAvailable::expValueIsNotAvailable()= default;
inputFile::expTypeIsNotAvailable::expTypeIsNotAvailable()= default;
inputFile::expWrongNamed::expWrongNamed()= default;

inputFile::expWrongFileDirectory::~expWrongFileDirectory(){};
inputFile::expWrongFileFormat::~expWrongFileFormat(){};
inputFile::expValueIsNotAvailable::~expValueIsNotAvailable(){};
inputFile::expTypeIsNotAvailable::~expTypeIsNotAvailable(){};
inputFile::expWrongNamed::~expWrongNamed(){};

void inputFile::expWrongFileFormat::showBugInfo() {
    std::cout <<"Message: "<< bugInfo_ << "Code of Bug: " << bugCode_ << '\n';
}
void inputFile::expWrongFileDirectory::showBugInfo() {
    std::cout <<"Message: "<< bugInfo_ << "Code of Bug: " << bugCode_ << '\n';
}
void inputFile::expValueIsNotAvailable::showBugInfo() {
    std::cout <<"Message: "<< bugInfo_ << "Code of Bug: " << bugCode_ << '\n';
}
void inputFile::expTypeIsNotAvailable::showBugInfo() {
    std::cout <<"Message: "<< bugInfo_ << "Code of Bug: " << bugCode_ << '\n';
}
void inputFile::expWrongNamed::showBugInfo() {
    std::cout <<"Message: "<< bugInfo_ << "Code of Bug: " << bugCode_ << '\n';
}


void inputFile::openIniFile(){
    std::ifstream myIniFile;
    try
    {
        std::cout << "Attempt to open File\n";
        if (filePath_.find('.') < filePath_.size()) {
            if (filePath_.substr(filePath_.find('.') + 1) != "ini") {
                throw expWrongFileFormat("Fail, invalid file format! Only allowed format like: \".ini\"\n", -2); // for instanse, -2 is equal troubles with format
            } else {
                myIniFile.open(filePath_);
                if (!myIniFile.is_open()) {
                    throw expWrongFileDirectory("Fail, there is an ambiguity in the path of file, please make sure if it's okay\n", -1); // -1 is equal troubles with directory and so on
                }
                std::cout << "Success\n";
                
                isFileExist_ = true;
                std::cout << "Your file is already exist!\n";
                 
            }

        }
    }
    catch (expWrongFileFormat exp) 
    {
        exp.showBugInfo();
        isFileExist_ = false;
        
    }
    catch (expWrongFileDirectory exp) {
        exp.showBugInfo();
        isFileExist_ = false;
        
    }
}
void inputFile::parseIniFile() {
    openIniFile();
    if (isFileExist_) {
        std::ifstream myIniFile; 
        myIniFile.open(filePath_);

        std::string currLine;                       // Current line of our file (helps to us check file line by line)
        std::string currSection;                    // [currSection]
        std::string currSectionArg;                 // currsectionArg = currSectionArgValue
        std::string currSectionArgValue;            // currsectionArg = currSectionArgValue

        currSection.reserve(alpha); // alpha == 1e4
        currSectionArg.reserve(alpha);
        currSectionArgValue.reserve(alpha);
        currLine.reserve(alpha);
        int numberSection = 0;
        bool check = false;
        while(getline(myIniFile,currLine)) {
            if (currLine.size() == 0){
                continue;
            }
            int pointOfCommentStart = currLine.find(';');
            if (pointOfCommentStart < currLine.size()) {
                currLine.erase(pointOfCommentStart, currLine.size() - pointOfCommentStart);
            }

            int pointOpenSection = currLine.find('[');
            int pointCloseSection = currLine.find(']');
                
            if (pointOpenSection != -1 && pointCloseSection != -1) {
                
                currSection.clear();
                currSection.insert(0, currLine, pointOpenSection + 1, pointCloseSection - pointOpenSection - 1);
                int pointForSectionGaps = currSection.find(' ');
                int pointForSectionDodes = currSection.find('.');
                    
                try 
                {
                    if (pointForSectionGaps != -1 || pointForSectionDodes != -1) {
                        throw (expWrongNamed(std::string("Fail, Section name contains whitespace or dodes!\n"), -7));
                    }
                } 
                catch(expWrongNamed exp) 
                {
                    exp.showBugInfo();
                    exit(-1);
                    currSection.clear();
                }

            } else {

                int pointFirstOccurrenceOfArg = 0;
                int pointLastOccurrenceOfArg = 0;
                while (currLine[pointFirstOccurrenceOfArg] == ' ') {
                    pointFirstOccurrenceOfArg++;
                }
                pointLastOccurrenceOfArg = currLine.find('=');

                bool isGapBeforeEqual = currLine[pointLastOccurrenceOfArg - 1] == ' ';
                
                if (pointLastOccurrenceOfArg < currLine.size() && pointFirstOccurrenceOfArg < currLine.size()) {
                    currSectionArg.clear();
                    currSectionArg.insert(0, currLine, pointFirstOccurrenceOfArg, ((pointLastOccurrenceOfArg - pointFirstOccurrenceOfArg + 1) - (1 + isGapBeforeEqual)));
                }
                int pointForArgGaps = currSectionArg.find(' ');
                int pointForArgDodes = currSectionArg.find('.');
                bool isGapAfterEqual = currLine[pointLastOccurrenceOfArg + 1] == ' ';
                int pointFirstOccurrenceOfArgValue = pointLastOccurrenceOfArg + 1 + isGapAfterEqual;
                int pointLastOccurrenceOfArgValue = currLine.size() - 1;
                
                if (pointLastOccurrenceOfArgValue < currLine.size() && pointFirstOccurrenceOfArgValue < currLine.size()) {
                    currSectionArgValue.clear();
                    currSectionArgValue.insert(0, currLine, pointFirstOccurrenceOfArgValue, (pointLastOccurrenceOfArgValue - pointFirstOccurrenceOfArgValue + 1));
                }
                try 
                {
                    if (pointForArgGaps != -1 || pointForArgDodes != -1) {
                        throw (expWrongNamed(std::string("Fail, Arg name contains whitespace or dodes!\n"), -7));
                    }
                } 
                catch(expWrongNamed exp) 
                {
                    exp.showBugInfo();
                    exit(-1);
                    currSectionArg.clear();
                }
                storage_[currSection].emplace(currSectionArg, currSectionArgValue);
                
            }

        }
        // std::map<std::string, std::map<std::string, std::string>>::iterator it_ = storage_.begin();
        // std::map<std::string, std::string>::iterator itInner_;
        // while (it_ != storage_.end()) {
        //     std::cout << it_->first << '\n';
        //     itInner_ = storage_[it_->first].begin();
        //     while(itInner_ != storage_[it_->first].end()) {
        //         std::cout << itInner_->first << " = " << itInner_->second << '\n';
        //         itInner_++;
        //     }
        //     it_++;
        //     std::cout << '\n';
        // }
        
    }
}
long long inputFile::getInteger (std::string typeOfInteger, std::string value) {
    
    if (typeOfInteger == "long long") { //{-9223372036854775807...9223372036854775807 }
        int pointOfDote = value.find('.');
        if (pointOfDote != -1)
            value.erase(pointOfDote);
        for (int i = 0; i < value.size(); i++) {
            if (((value[i] >= 0 && value[i] <= 47)&& value[i] != 45) || value[i] >= 58) {    // 2 147 483 647
                throw(expTypeIsNotAvailable("Fail, value of argument contains characters\n", -4));
            }
        }
        if (value[0] != '-') {
            if (LLONG_MAX < std::stoll(value)) { 
                throw (expTypeIsNotAvailable("Fail, Long long integer can be equal to {-2 147 483 647.... 2 147 483 648}\n", -6));    
            }
        } else {
            if (LLONG_MIN > std::stoll(value)) { 
                throw (expTypeIsNotAvailable("Fail, Long long integer can be equal to {-2 147 483 647.... 2 147 483 648}\n", -6));    
            }
        }
    }
    if (typeOfInteger == "int") {
        int pointOfDote = value.find('.');
        if (pointOfDote != -1)
            value.erase(pointOfDote);
        
        for (int i = 0; i < value.size(); i++) {
            if ((value[i] >= 0 && value[i] <= 47) || value[i] >= 58){        // 2 147 483 647
                throw(expTypeIsNotAvailable("Fail, value of argument contains characters\n", -4));
            }
        }
        if (value[0] != '-') {
            if (INT_MAX < stoll(value)){
                throw (expTypeIsNotAvailable("Fail, integer can be equal to {-2 147 483 647.... 2 147 483 648}\n", -5));    
            }
        } else {
            if (INT_MIN > stoll(value)) { 
                throw (expTypeIsNotAvailable("Fail, integer can be equal to {-2 147 483 647.... 2 147 483 648}\n", -5));    
            }
        }
    }
    return stoll(value);
}
// Заменить на шаблоны
// подключить регулярки
double inputFile::getReal (std::string typeOfReal, std::string value) {
    if (typeOfReal == "double") { //{1.7E-308...1.7E+308.}
        for (int i = 0; i < value.size(); i++) {
            if ((value[i] >= 0 && value[i] < 45) || (value[i] == 47) || value[i] >= 58) {                                                                                                    // 2 147 483 647
                throw(expTypeIsNotAvailable("Fail, value of argument contains characters\n", -4));
            }
        }
        if (value[0] != '-') {
            if (DBL_MAX < std::stod(value)) { 
                
                throw (expTypeIsNotAvailable("Fail, type Double can be equal to {1.7E-308...1.7E+308.}\n", -6));    
            }
        } else {
            if (DBL_MIN > std::stod(value)) { 
                
                throw (expTypeIsNotAvailable("Fail, type Double can be equal to {1.7E-308...1.7E+308.}\n", -6));    
            }
        }
    }
    if (typeOfReal == "float") {
        for (int i = 0; i < value.size(); i++) {
            if ((value[i] >= 0 && value[i] < 45) || (value[i] == 47) || value[i] >= 58){        // {3.4E-38...3.4E+38}
                throw(expTypeIsNotAvailable("Fail, value of argument contains characters\n", -4));
            }
        }
        if (value[0] != '-') {
            if (FLT_MAX < stod(value)){
                throw (expTypeIsNotAvailable("Fail, float can be equal to {3.4E-38...3.4E+38}\n", -5));    
                
            }
        } else {
            if (FLT_MIN > stod(value)) { 
                throw (expTypeIsNotAvailable("Fail, float can be equal to {3.4E-38...3.4E+38}\n", -5));    
            }
        }
    }
    
    return std::stod(value);
    
}
std::string inputFile::getString(std::string type, std::string value) {
    return value;
}
void inputFile::checkType(std::string type, std::string value) {

    if (type == "int" || type == "long long") {
        std::cout << "Your integer is: " << getInteger(type, value) << '\n';
    }
    if (type == "double" || type == "float") {
        std::cout << "Your real number is: " << getReal(type, value) << '\n';
    }
    if (type == "std::string" || "string") {
        std::cout << "Your string is: " << getString(type, value) << '\n';
    }
}
void inputFile::getValue(std::string type, std::string sectionName, std::string sectionArgName) {

    bool attemptToGetValue = false;
    std::string valueForGiving = "*";
    std::map<std::string, std::map<std::string, std::string>>::iterator it_ = storage_.begin();
    std::map<std::string, std::string>::iterator itInner_;
    
    while (it_ != storage_.end()) {
        if (it_->first ==  sectionName) {
            itInner_ = storage_[it_->first].begin();
            while(itInner_ != storage_[it_->first].end()) {
                if (itInner_->first == sectionArgName){
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
    try 
    {
        if (!attemptToGetValue){
            throw expValueIsNotAvailable("Fail!\n No matching section or argument found, please make sure that file getting path is right\n", -3);
        } else {
            checkType(type, valueForGiving);
        }
    }
    catch (expValueIsNotAvailable exp)
    {
        exp.showBugInfo();
        exit(-1);
    }
    catch (expTypeIsNotAvailable exp) 
    {
        exp.showBugInfo();
        exit(-1);
    }
    
}
