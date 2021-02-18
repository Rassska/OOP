#include <iostream>
#include <string>
#include <vector>
#include "RemoveSizeAlg.h"


RemoveSizeAlg::RemoveSizeAlg(std::size_t sizeLimit) {
    m_SizeLimit = sizeLimit;
} 

RemoveSizeAlg::~RemoveSizeAlg() = default;

std::size_t RemoveSizeAlg::getDiff(const BackUp& currBackUp) {
    std::size_t diff = 0;
    std::size_t copyBackUpSize = currBackUp.getBackUpSize();
    
    for (std::size_t i = 0; i < currBackUp.getRestPointCnt(); i++) {
        if (copyBackUpSize > m_SizeLimit) {
            diff++;
            copyBackUpSize -= currBackUp.getRestorePointStorage()[i]->getRestPointSize();
        }
    }
   
    return diff;
    
}