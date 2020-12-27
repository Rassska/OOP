#pragma once
#include <string>
#include <vector>
#include "file.h"


class restorePoint{
protected:
    static std::size_t m_restorePointId;
    std::size_t m_currentId;
    std::string_view m_restorePointName;
    std::vector<file> m_filesRestorePoints;
    restorePoint* m_restorePointParent;
   ~restorePoint();
    time_t m_restorePointTime;
    virtual std::size_t setRestorePointSize(const restorePoint* restorePoint, std::string_view restorePointName) = 0;
public:
    std::string_view getRestorePointName() const;
    std::size_t getRestorePointId()const;
    time_t getRestorePointTime()const;
    restorePoint* getRestorePointParent() const;
    virtual void addFileToRestorePoint(file file) = 0;
    void deleteFile(std::string_view fileName);
    bool findFile(std::string_view fileName) const;
    file getFile(std::string_view fileName) const;
    const std::vector<file>& getRestorePointFiles() const;
    std::size_t getRestorePointSize() const;
};