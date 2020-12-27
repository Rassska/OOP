#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctime>
#include <unordered_map>
#include <list>
#include <map>
#include <ctime>
#include <filesystem>
#include <utility>
#include <functional>

#include "restorePoint.h"
#include "file.h"
#include "delDateAlg.h"



std::size_t DateAlg::limitWithDate(const time_t limit, const std::vector<restorePoint*>& restorePoints) {
    std::size_t ans = 0;
    for( std::size_t i = 0; i < restorePoints.size(); i++) {
        if(restorePoints[i]->getRestorePointTime() < limit) {
            ans++;
        }
    }
    return ans;
}

std::size_t DateAlg::limit(const std::vector<restorePoint*>& restorePoints) const {
    return limitWithDate(m_timeLim, restorePoints);
}