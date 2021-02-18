#pragma once
#include "IRemoveManager.h"
#include "BackUp.h"
#include <iostream>
#include <vector>
#include <string>

class RemoveHybridAlg : public IRemoveManager
{
private:
    bool m_IsAllConditions;
    std::vector<IRemoveManager*> m_GivenHybridAlgs;

public:
    RemoveHybridAlg(std::vector<IRemoveManager*>& currHybridAlgs, bool isAllConditions);
    std::size_t getDiff(const BackUp& currBackUp) override;
    ~RemoveHybridAlg();
};
