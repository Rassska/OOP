#pragma once
#include <vector>
#include <string>

class file{
    std::string m_filePath;
    std::string m_fileName;
    std::size_t m_fileSize;
    time_t m_fileTime;
public:
    file(std::string name);
    file();
    ~file();
    
    std::string getFileName() const;
    std::string getFilePath()const;
    std::size_t getFileSize()const;
    std::size_t getSizeFile()const;
    std::string getFileTimeAsCtime()const ;
    time_t getFileTime()const;
    
    void setFileSize(std::size_t newFileSize);
    void setFileTime(time_t newFileTime);
    void setFileName(std::string newFileName);
    void setFilePath(std::string newFilePath);
};