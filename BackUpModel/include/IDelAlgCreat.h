#pragma once

#include <vector>
#include <string>
#include <functional>
#include "restorePoint.h"

class IDelAlgCreat{
private:
    std::function<int(const std::vector<restorePoint*>&)> m_limit;
public:
    IDelAlgCreat() = default;
    explicit IDelAlgCreat(std::function<int(const std::vector<restorePoint*>&)> limit) : m_limit(std::move(limit)) {}
    IDelAlgCreat combine(const IDelAlgCreat& other);
    IDelAlgCreat mult(const IDelAlgCreat& other);
    virtual std::size_t limit(const std::vector<restorePoint*>& rps) const;
};