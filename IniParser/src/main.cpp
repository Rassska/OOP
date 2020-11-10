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

    const std::string iniFilePath = "/home/rasul/dev/OOP/IniParser/src/inputFile.ini";
    const std::string iniFileName = "myIniFile";

    inputFile myIniFile(iniFileName, iniFilePath);

    myIniFile.parseIniFile();
    // std::cout << get_as<int>(myIniFile.getValue("COMMON", "DiskCachePath"));
    // std::cout << get_as<int>(myIniFile.getValue("NCMD", "SampleRate"));
    // std::cout << get_as<double>(myIniFile.getValue("COMMON", "DiskCachePath"));
    // std::cout << get_as<long long>(myIniFile.getValue("ADC_DEV", "BufferLenSeconds"));
    // std::cout << get_as<int>(myIniFile.getValue("COMMN", "DiskCachePath"));
    // std::cout << get_as<int>(myIniFile.getValue("COMMON", "DiskCachePath"));

    

    


    
    
    
}