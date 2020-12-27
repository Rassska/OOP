#pragma once
#include <vector>
#include <string>
#include "restorePoint.h"
#include "file.h"
#include "IDelAlgCreat.h"

class BackUp{
private:
    time_t m_createTime;
    std::size_t m_sizeOfBackUp;
    std::vector<restorePoint*> m_restorePointList;
    std::vector<file> m_backUpOfFiles;
public:
    explicit BackUp();
    void addToBackUp(std::string_view inputFile) ;
    void deleteFileFromBackUp(std::string_view inputFile);
    const std::vector<restorePoint*> getAlllRestorePointsPointer() const;
    void printAll();
    void createRestPoint(std::string_view typeRP);
    std::size_t getRestorePointsSize() const;
};