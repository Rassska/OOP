#pragma once
#include "IRemove.h"
#include "BackUp.h"
#include <iostream>
#include <vector>
#include <string>

class RemoveAmountAlg : public IRemove
{
private:
    std::size_t m_LimitCnt;
public:
    RemoveAmountAlg(std::size_t limit);
    std::size_t getDiff(const BackUp& currBackUp) override;
    ~RemoveAmountAlg();
};

