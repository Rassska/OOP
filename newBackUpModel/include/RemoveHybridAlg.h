#pragma once
#include "IRemove.h"
#include "BackUp.h"
#include <iostream>
#include <vector>
#include <string>

class RemoveHybridAlg : public IRemove
{
private:
    bool m_IsAllConditions;
    std::vector<IRemove*> m_GivenHybridAlgs;

public:
    RemoveHybridAlg(std::vector<IRemove*>& currHybridAlgs, bool isAllConditions);
    std::size_t getDiff(const BackUp& currBackUp) override;
    ~RemoveHybridAlg();
};
