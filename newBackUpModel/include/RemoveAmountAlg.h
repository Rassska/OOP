#pragma once
#include "IRemoveManager.h"
#include "BackUp.h"
#include <iostream>
#include <vector>
#include <string>

class RemoveAmountAlg : public IRemoveManager
{
private:
    std::size_t m_LimitCnt;
public:
    RemoveAmountAlg(std::size_t limit);
    std::size_t getDiff(const BackUp& currBackUp) override;
    ~RemoveAmountAlg();
};

