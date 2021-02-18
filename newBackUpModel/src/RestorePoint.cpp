#include <iostream>
#include <string>
#include <vector>
#include "RestorePoint.h"


RestorePoint::RestorePoint(std::vector <std::pair<std::string_view, bool>>& givenFiles, bool isIncrement) {
    m_IsIncrement = isIncrement;

    if (!isIncrement) {
        for (std::size_t i = 0; i < givenFiles.size(); i++) {
            m_CurrPointFiles.push_back(givenFiles[i].first);
            givenFiles[i].second = true;
        }
        
    } else {
        for (std::size_t i = 0; i < givenFiles.size(); i++) { 
            if (givenFiles[i].second == false) {
                m_CurrPointFiles.push_back(givenFiles[i].first);
                givenFiles[i].second = true;
            }
            
        }
    }
}

std::size_t RestorePoint::getRestPointSize() const {
    std::size_t ans = 0;
    for (std::size_t i = 0; i < m_CurrPointFiles.size(); i++) {
        ans += m_CurrPointFiles[i].size();
    }
    return ans;
}

bool RestorePoint::isIncrement () const {
    return m_IsIncrement;
}

const std::vector<std::string_view>& RestorePoint::getCurrPointFiles() const  { 
    return m_CurrPointFiles;
}
RestorePoint::~RestorePoint() = default;
