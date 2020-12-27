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

#include "IDelAlgCreat.h"
#include "restorePoint.h"


IDelAlgCreat IDelAlgCreat::combine(const IDelAlgCreat& delAlg) {
    auto new_limiter = [&](const std::vector<restorePoint*>& restorePoints) -> int {return std::max(limit(restorePoints), delAlg.limit(restorePoints));};
    return IDelAlgCreat(new_limiter);
}

IDelAlgCreat IDelAlgCreat::mult(const IDelAlgCreat& delAlg) {
    auto new_limiter = [&](const std::vector<restorePoint*>& restorePoints) -> int {return std::min(limit(restorePoints), delAlg.limit(restorePoints));};
    return IDelAlgCreat(new_limiter);
}

std::size_t IDelAlgCreat::limit(const std::vector<restorePoint*>& restorePoints) const {
    return limit(restorePoints);
}