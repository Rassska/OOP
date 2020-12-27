#pragma once
#include "IDelAlgCreat.h"
#include "restorePoint.h"

class LengthAlg : public IDelAlgCreat{
private:
    std::size_t m_lengthLim;
public:
    explicit LengthAlg(const size_t lengthLim) : m_lengthLim(lengthLim) {}
    static std::size_t length_limiter(const size_t lim, const std::vector<restorePoint*>& restorePoints);
    std::size_t limit(const std::vector<restorePoint*>& rps) const override;
};