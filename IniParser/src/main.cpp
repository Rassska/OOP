/**
 *    author:  Rasul Yunusov
 *    created: 19.09.2020 04:28:26
**/



#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "IniParser.h"



int main () {

    std::string iniFilePath = "/home/rasul/dev/OOP/IniParser/src/inputFile.ini";
    std::string iniFileName = "myIniFile";
 
    inputFile myIniFile(iniFileName, iniFilePath);
    myIniFile.parseIniFile();
    
    // myIniFile.getValue(std::string("int"), std::string("COMMON"), std::string("OpenMPThreadsCount")); // There is not reason for refusing
    // std::cout << '\n';
    // myIniFile.getValue(std::string("int"), std::string("COMMON"), std::string("StatisterTimeMs")); // Threre is a problem, StatisterTimeMs > INT.MAX
    // std::cout << '\n';
    // myIniFile.getValue(std::string("long long"), std::string("COMMON"), std::string("StatisterTimeMs")); // Threre is no problem, StatisterTimeMs < LLONG.MAX
    // myIniFile.getValue(std::string("double"), std::string("ADC_DEV"), std::string("SampleRate")); // There is no problem, SampleRate < DBL.MAX
    // myIniFile.getValue(std::string("std::string"), std::string("ADC_DEV"), std::string("DiskCachePath"));


    
    
    
}