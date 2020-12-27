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
#include "delSizeAlg.h"

std::size_t SizeAlg::size_limiter(const std::size_t limit, const std::vector<restorePoint*>& restorePoints) {
    std::size_t max = std::numeric_limits<std::size_t>::lowest();
    std::size_t maxControlFlag = restorePoints.size();
    for(std::size_t i = restorePoints.size() - 1; i > -1; i--) {
        max += restorePoints[i]->getRestorePointSize();
        maxControlFlag = i;
        if(max > limit) 
            break;
    }
    return  maxControlFlag;
}

std::size_t SizeAlg::limit(const std::vector<restorePoint*>& restorePoints) const {
    return size_limiter(m_sizeLim, restorePoints);
}