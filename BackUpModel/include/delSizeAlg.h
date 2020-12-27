#pragma once
#include "IDelAlgCreat.h"


class SizeAlg : public IDelAlgCreat{
private:
    std::size_t m_sizeLim;
public:
    explicit SizeAlg(std::size_t sizeLim) : m_sizeLim(sizeLim) {}
    static std::size_t size_limiter(const std::size_t limit, const std::vector<restorePoint*>& restorePoints);
    std::size_t limit(const std::vector<restorePoint*>& rps) const override;
};