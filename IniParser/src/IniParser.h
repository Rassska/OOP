
#pragma once

#include <bits/stdc++.h>
class inputFile // file.ini
{
private:
    // first - name of Section
    // second.first - name of Args
    // second.second - value of Args
    std::map<std::string, std::map<std::string, std::string>> storage_;
    const std::string filePath_;
    const std::string fileName_;
 
    
    

public:
    inputFile();
    inputFile(const std::string& fileName, const std::string& filePath);
    ~inputFile();
    void parseIniFile();
    void getValue(std::string type, std::string sectionName, std::string sectionArgName);
    void checkType(std::string type, std::string value);
    long long getInteger (std::string typeOfInteger, std::string value);
    double getReal (std::string typeOfReal, std::string value);
    std::string getString(std::string type, std::string value);

};
