#include <iostream>
#include <string>
#include <vector>
#include "RemoveAmountAlg.h"
#include <algorithm>

RemoveAmountAlg::RemoveAmountAlg(std::size_t limitCnt) {
    m_LimitCnt = limitCnt;
} 

RemoveAmountAlg::~RemoveAmountAlg() = default;
std::size_t RemoveAmountAlg::getDiff(const BackUp& currBackUp) {
    std::size_t diff = std::max((currBackUp.getRestPointCnt() - m_LimitCnt), std::size_t(0));
    return diff;
}