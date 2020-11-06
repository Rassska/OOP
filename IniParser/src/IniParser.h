
#pragma once

#include <bits/stdc++.h>

template<typename T>
auto get_as(const std::string& str){

    if constexpr (std::is_same_v<int, T>) {
        return stoi(str);
    }
    else if constexpr (std::is_same_v<long long, T>) {
        return stoll(str);
    }
    else if constexpr (std::is_same_v<long, T>) {
        return stol(str);
    }
    else if constexpr (std::is_same_v<long, T>) {
        return stol(str);
    }
    else if constexpr (std::is_same_v<float, T>) {
        return stof(str);
    }
    else if constexpr (std::is_same_v<long double, T>) {
        return stold(str);
    }
    else {
        return str;
    }
}

class inputFile
{
private:
    std::map<std::string, std::map<std::string, std::string>> storage_;
    const std::string filePath_;
    const std::string fileName_;
 
public:
    inputFile();
    inputFile(const std::string& fileName, const std::string& filePath);
    ~inputFile();
    void parseIniFile();

    std::string getValue(std::string sectionName, std::string sectionArgName);

};
