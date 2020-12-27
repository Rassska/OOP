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
#include "delLengthAlg.h"


std::size_t LengthAlg::length_limiter(const size_t limit, const std::vector<restorePoint*>& restorePoints) {
    return restorePoints.size() <= limit ? 0 : restorePoints.size() - limit;
}

std::size_t LengthAlg::limit(const std::vector<restorePoint*>& restorePoints) const {
    return length_limiter(m_lengthLim, restorePoints);
}