#include <iostream>
#include <string>
#include <vector>
#include "RemoveDateAlg.h"



RemoveDateAlg::RemoveDateAlg(time_t limitTime) {
    m_DateLimit = limitTime;
} 

std::size_t RemoveDateAlg::getDiff(const BackUp& currBackUp) {
    std::size_t diff = 0;
    for (auto i = 0; i < currBackUp.getRestPointCreatedTime().size(); i++) {
        if (currBackUp.getRestPointCreatedTime()[i] < m_DateLimit) {
            diff++;
        }
    }
    return diff;
   
}
RemoveDateAlg::~RemoveDateAlg() = default;
