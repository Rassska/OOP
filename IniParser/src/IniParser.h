
#pragma once

#include <bits/stdc++.h>
class inputFile // file.ini
{
private:
    const int alpha = 1e4;
    // first - name of Section
    // second.first - name of Args
    // second.second - value of Args
    std::map<std::string, std::map<std::string, std::string>> storage_;
    std::string filePath_;
    std::string fileName_;
    bool isFileExist_;
    
    

public:
   
    class expWrongFileDirectory {
    private:
        std::string bugInfo_;
        int bugCode_;
    public:
        expWrongFileDirectory();
        expWrongFileDirectory(std::string bugInfo, int bugCode);
        ~expWrongFileDirectory();
        void showBugInfo();
    };
    class expWrongFileFormat {
    private:
        std::string bugInfo_;
        int bugCode_;
    public:
        expWrongFileFormat();
        expWrongFileFormat(std::string bugInfo, int bugCode);
        ~expWrongFileFormat();
        void showBugInfo();
    };
    class expValueIsNotAvailable {
    private:
        std::string bugInfo_;
        int bugCode_;
    public:
        expValueIsNotAvailable();
        expValueIsNotAvailable(std::string bugInfo, int bugCode);
        ~expValueIsNotAvailable();
        void showBugInfo();
    };
    class expTypeIsNotAvailable {
    private:
        std::string bugInfo_;
        int bugCode_;
    public:
        expTypeIsNotAvailable();
        expTypeIsNotAvailable(std::string bugInfo, int bugCode);
        ~expTypeIsNotAvailable();
        void showBugInfo();
    };
    class expWrongNamed {
    private:
        std::string bugInfo_;
        int bugCode_;
    public:
        expWrongNamed();
        expWrongNamed(std::string bugInfo, int bugCode);
        ~expWrongNamed();
        void showBugInfo();
    };

    inputFile();
    inputFile(std::string fileName, std::string filePath);
    ~inputFile();
    void openIniFile();
    void parseIniFile();
    void getValue(std::string type, std::string sectionName, std::string sectionArgName);
    void checkType(std::string type, std::string value);
    long long getInteger (std::string typeOfInteger, std::string value);
    double getReal (std::string typeOfReal, std::string value);
    std::string getString(std::string type, std::string value);

};
