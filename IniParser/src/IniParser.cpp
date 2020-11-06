#include "IniParser.h"
#include <bits/stdc++.h>


inputFile::inputFile() = default;

inputFile::inputFile(const std::string& fileName, const std::string& filePath) : 
    fileName_(fileName), filePath_(filePath) {}

inputFile::~inputFile(){}

void inputFile::parseIniFile() {

    std::ifstream myIniFile;
    std::string_view view = filePath_;
    bool isIniFile = (view.substr(filePath_.size() - 4, filePath_.size() - 1) == ".ini");

    
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

    std::map<std::string, std::map<std::string, std::string>>::iterator it_ = storage_.begin();
    std::map<std::string, std::string>::iterator itInner_;
    while (it_ != storage_.end()) {
        std::cout << it_->first << '\n';
        itInner_ = storage_[it_->first].begin();
        while(itInner_ != storage_[it_->first].end()) {
            std::cout << itInner_->first << " = " << itInner_->second << '\n';
            itInner_++;
        }
        it_++;
        std::cout << '\n';
    }
    exit(0);

    

    
    // std::string currLine;                       // Current line of our file (helps to us check file line by line)
    // std::string currSection;                    // [currSection]
    // std::string currSectionArg;                 // currsectionArg = currSectionArgValue
    // std::string currSectionArgValue;            // currsectionArg = currSectionArgValue

    // currSection.reserve(alpha); // alpha == 1e4
    // currSectionArg.reserve(alpha);
    // currSectionArgValue.reserve(alpha);
    // currLine.reserve(alpha);
    // int numberSection = 0;
    // bool check = false;
    // while(getline(myIniFile,currLine)) {
    //     if (currLine.size() == 0){
    //         continue;
    //     }
    //     int pointOfCommentStart = currLine.find(';');
    //     if (pointOfCommentStart < currLine.size()) {
    //         currLine.erase(pointOfCommentStart, currLine.size() - pointOfCommentStart);
    //     }

    //     int pointOpenSection = currLine.find('[');
    //     int pointCloseSection = currLine.find(']');
            
    //     if (pointOpenSection != -1 && pointCloseSection != -1) {
            
    //         currSection.clear();
    //         currSection.insert(0, currLine, pointOpenSection + 1, pointCloseSection - pointOpenSection - 1);
    //         int pointForSectionGaps = currSection.find(' ');
    //         int pointForSectionDodes = currSection.find('.');
                
    //         try 
    //         {
    //             if (pointForSectionGaps != -1 || pointForSectionDodes != -1) {
    //                 throw (std::runtime_error(std::string("Fail, Section name contains whitespace or dodes!\n")));
    //             }
    //         } 
    //         catch(std::runtime_error& exp) 
    //         {
    //             exp.what();
    //         }

    //     } else {

    //         int pointFirstOccurrenceOfArg = 0;
    //         int pointLastOccurrenceOfArg = 0;
    //         while (currLine[pointFirstOccurrenceOfArg] == ' ') {
    //             pointFirstOccurrenceOfArg++;
    //         }
    //         pointLastOccurrenceOfArg = currLine.find('=');

    //         bool isGapBeforeEqual = currLine[pointLastOccurrenceOfArg - 1] == ' ';
            
    //         if (pointLastOccurrenceOfArg < currLine.size() && pointFirstOccurrenceOfArg < currLine.size()) {
    //             currSectionArg.clear();
    //             currSectionArg.insert(0, currLine, pointFirstOccurrenceOfArg, ((pointLastOccurrenceOfArg - pointFirstOccurrenceOfArg + 1) - (1 + isGapBeforeEqual)));
    //         }
    //         int pointForArgGaps = currSectionArg.find(' ');
    //         int pointForArgDodes = currSectionArg.find('.');
    //         bool isGapAfterEqual = currLine[pointLastOccurrenceOfArg + 1] == ' ';
    //         int pointFirstOccurrenceOfArgValue = pointLastOccurrenceOfArg + 1 + isGapAfterEqual;
    //         int pointLastOccurrenceOfArgValue = currLine.size() - 1;
            
    //         if (pointLastOccurrenceOfArgValue < currLine.size() && pointFirstOccurrenceOfArgValue < currLine.size()) {
    //             currSectionArgValue.clear();
    //             currSectionArgValue.insert(0, currLine, pointFirstOccurrenceOfArgValue, (pointLastOccurrenceOfArgValue - pointFirstOccurrenceOfArgValue + 1));
    //         }
    //         try 
    //         {
    //             if (pointForArgGaps != -1 || pointForArgDodes != -1) {
    //                 throw (expWrongNamed(std::string("Fail, Arg name contains whitespace or dodes!\n"), -7));
    //             }
    //         } 
    //         catch(expWrongNamed exp) 
    //         {
    //             exp.showBugInfo();
    //             exit(-1);
    //             currSectionArg.clear();
    //         }
    //         storage_[currSection].emplace(currSectionArg, currSectionArgValue);
            
    //     }

    // }
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
// long long inputFile::getInteger (std::string typeOfInteger, std::string value) {
    
//     if (typeOfInteger == "long long") { //{-9223372036854775807...9223372036854775807 }
//         int pointOfDote = value.find('.');
//         if (pointOfDote != -1)
//             value.erase(pointOfDote);
//         for (int i = 0; i < value.size(); i++) {
//             if (((value[i] >= 0 && value[i] <= 47)&& value[i] != 45) || value[i] >= 58) {    // 2 147 483 647
//                 throw(expTypeIsNotAvailable("Fail, value of argument contains characters\n", -4));
//             }
//         }
//         if (value[0] != '-') {
//             if (LLONG_MAX < std::stoll(value)) { 
//                 throw (expTypeIsNotAvailable("Fail, Long long integer can be equal to {-2 147 483 647.... 2 147 483 648}\n", -6));    
//             }
//         } else {
//             if (LLONG_MIN > std::stoll(value)) { 
//                 throw (expTypeIsNotAvailable("Fail, Long long integer can be equal to {-2 147 483 647.... 2 147 483 648}\n", -6));    
//             }
//         }
//     }
//     if (typeOfInteger == "int") {
//         int pointOfDote = value.find('.');
//         if (pointOfDote != -1)
//             value.erase(pointOfDote);
        
//         for (int i = 0; i < value.size(); i++) {
//             if ((value[i] >= 0 && value[i] <= 47) || value[i] >= 58){        // 2 147 483 647
//                 throw(expTypeIsNotAvailable("Fail, value of argument contains characters\n", -4));
//             }
//         }
//         if (value[0] != '-') {
//             if (INT_MAX < stoll(value)){
//                 throw (expTypeIsNotAvailable("Fail, integer can be equal to {-2 147 483 647.... 2 147 483 648}\n", -5));    
//             }
//         } else {
//             if (INT_MIN > stoll(value)) { 
//                 throw (expTypeIsNotAvailable("Fail, integer can be equal to {-2 147 483 647.... 2 147 483 648}\n", -5));    
//             }
//         }
//     }
//     return stoll(value);
// }
// // Заменить на шаблоны
// // подключить регулярки
// double inputFile::getReal (std::string typeOfReal, std::string value) {
//     if (typeOfReal == "double") { //{1.7E-308...1.7E+308.}
//         for (int i = 0; i < value.size(); i++) {
//             if ((value[i] >= 0 && value[i] < 45) || (value[i] == 47) || value[i] >= 58) {                                                                                                    // 2 147 483 647
//                 throw(expTypeIsNotAvailable("Fail, value of argument contains characters\n", -4));
//             }
//         }
//         if (value[0] != '-') {
//             if (DBL_MAX < std::stod(value)) { 
                
//                 throw (expTypeIsNotAvailable("Fail, type Double can be equal to {1.7E-308...1.7E+308.}\n", -6));    
//             }
//         } else {
//             if (DBL_MIN > std::stod(value)) { 
                
//                 throw (expTypeIsNotAvailable("Fail, type Double can be equal to {1.7E-308...1.7E+308.}\n", -6));    
//             }
//         }
//     }
//     if (typeOfReal == "float") {
//         for (int i = 0; i < value.size(); i++) {
//             if ((value[i] >= 0 && value[i] < 45) || (value[i] == 47) || value[i] >= 58){        // {3.4E-38...3.4E+38}
//                 throw(expTypeIsNotAvailable("Fail, value of argument contains characters\n", -4));
//             }
//         }
//         if (value[0] != '-') {
//             if (FLT_MAX < stod(value)){
//                 throw (expTypeIsNotAvailable("Fail, float can be equal to {3.4E-38...3.4E+38}\n", -5));    
                
//             }
//         } else {
//             if (FLT_MIN > stod(value)) { 
//                 throw (expTypeIsNotAvailable("Fail, float can be equal to {3.4E-38...3.4E+38}\n", -5));    
//             }
//         }
//     }
    
//     return std::stod(value);
    
// }
// std::string inputFile::getString(std::string type, std::string value) {
//     return value;
// }
// void inputFile::checkType(std::string type, std::string value) {

//     if (type == "int" || type == "long long") {
//         std::cout << "Your integer is: " << getInteger(type, value) << '\n';
//     }
//     if (type == "double" || type == "float") {
//         std::cout << "Your real number is: " << getReal(type, value) << '\n';
//     }
//     if (type == "std::string" || "string") {
//         std::cout << "Your string is: " << getString(type, value) << '\n';
//     }
// }
// void inputFile::getValue(std::string type, std::string sectionName, std::string sectionArgName) {

//     bool attemptToGetValue = false;
//     std::string valueForGiving = "*";
//     std::map<std::string, std::map<std::string, std::string>>::iterator it_ = storage_.begin();
//     std::map<std::string, std::string>::iterator itInner_;
    
//     while (it_ != storage_.end()) {
//         if (it_->first ==  sectionName) {
//             itInner_ = storage_[it_->first].begin();
//             while(itInner_ != storage_[it_->first].end()) {
//                 if (itInner_->first == sectionArgName){
//                     attemptToGetValue = true;
//                     valueForGiving = itInner_->second;
//                     break;
//                 }
//                 itInner_++;
//             }
//             if (attemptToGetValue)
//                 break;
//         }
//         it_++;
//     }
//     try 
//     {
//         if (!attemptToGetValue){
//             throw expValueIsNotAvailable("Fail!\n No matching section or argument found, please make sure that file getting path is right\n", -3);
//         } else {
//             checkType(type, valueForGiving);
//         }
//     }
//     catch (expValueIsNotAvailable exp)
//     {
//         exp.showBugInfo();
//         exit(-1);
//     }
//     catch (expTypeIsNotAvailable exp) 
//     {
//         exp.showBugInfo();
//         exit(-1);
//     }
    
// }
