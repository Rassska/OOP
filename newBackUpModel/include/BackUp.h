#pragma once
#include "RestorePoint.h"
#include <iostream>
#include <ctime>

class BackUp
{
private:
    static std::size_t m_BackUpId;
    std::vector <std::pair<std::string_view, bool>> m_FileStorage;
    std::vector <RestorePoint*> m_RestorePointStorage;
    std::vector <time_t> m_RestorePointCreatedTime;
    std::size_t m_BackUpSize;
    time_t m_BackUpCreationTime;
public:
    explicit BackUp();
    void addFilesToBackUp(std::pair <std::string_view, bool> currPair);
    void createRestPoint(bool isIncrement);
    void saveBackUpAs(bool asArchive);
    void removeUnSuitablePoints(std::size_t amountOfRemovePoints);
    
    std::size_t getBackUpSize() const;
    std::size_t getRestPointCnt() const;
    const std::vector<time_t>& getRestPointCreatedTime() const;
    const std::vector <RestorePoint*>& getRestorePointStorage() const;
    


    ~BackUp();
};
