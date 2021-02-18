#include <iostream>
#include <string>
#include <vector>
#include "BackUp.h"
#include "RestorePoint.h"
#include "IRemoveManager.h"
#include <chrono>

std::size_t BackUp::m_BackUpId = 0;

BackUp::BackUp() {
    m_BackUpId++;
    m_RestorePointStorage = {};
    m_BackUpSize = 0;
    m_BackUpCreationTime = std::time(nullptr);
    m_FileStorage = {};
    
}

void BackUp::addFilesToBackUp(std::pair <std::string_view, bool> currPair) {
    m_FileStorage.emplace_back(currPair);
    m_BackUpSize += currPair.first.size();
}


void BackUp::createRestPoint(bool isIncrement) {
    
    RestorePoint* tempP = new RestorePoint(m_FileStorage, isIncrement);
    m_RestorePointStorage.push_back(tempP);
    m_RestorePointCreatedTime.push_back(std::time(nullptr) + m_RestorePointStorage.size() * m_RestorePointStorage.size());
}
void BackUp::saveBackUpAs(bool asArchive) {

}

std::size_t BackUp::getBackUpSize() const {
    std::size_t ans = 0;
    for (std::size_t i = 0; i < m_RestorePointStorage.size(); i++) {
        ans += m_RestorePointStorage[i]->getRestPointSize();
    }
    return ans;
}

std::size_t BackUp::getRestPointCnt() const {
    return m_RestorePointStorage.size();
}

void BackUp::removeUnSuitablePoints(std::size_t amountOfRemovePoints) {
    std::size_t sizeOfRemovedPoints = 0;
    
    for (std::size_t i = 1; i < amountOfRemovePoints + 1; i++) {
        if (m_RestorePointStorage[i]->isIncrement()) {
            throw std::runtime_error("Can not remove base of Increment!");
        }
        sizeOfRemovedPoints += m_RestorePointStorage[i]->getRestPointSize();
    }
    
    m_RestorePointStorage.erase(m_RestorePointStorage.begin(), m_RestorePointStorage.begin() + amountOfRemovePoints);
    m_BackUpSize -= sizeOfRemovedPoints;
    
}

const std::vector<time_t>& BackUp::getRestPointCreatedTime() const{
    return m_RestorePointCreatedTime;
}
const std::vector <RestorePoint*>& BackUp::getRestorePointStorage() const{
    return m_RestorePointStorage;
}

BackUp::~BackUp() = default;