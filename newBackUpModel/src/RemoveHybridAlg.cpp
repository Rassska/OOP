#include <iostream>
#include <string>
#include <vector>
#include "RemoveHybridAlg.h"
#include "IRemove.h"


RemoveHybridAlg::RemoveHybridAlg(std::vector<IRemove*>& currHybridAlgs, bool isAllConditions) {
    m_IsAllConditions = isAllConditions;
    m_GivenHybridAlgs = currHybridAlgs;
}

RemoveHybridAlg::~RemoveHybridAlg() = default;

std::size_t RemoveHybridAlg::getDiff(const BackUp& currBackUp){
    std::size_t diffIsAll = 1e7;
    std::size_t diffIsAtLeastOne = 0;
    
    if (m_IsAllConditions) {
        for (std::size_t i = 0; i < m_GivenHybridAlgs.size(); i++) {
            diffIsAll = std::min(m_GivenHybridAlgs[i]->getDiff(currBackUp), diffIsAll);
        }
        
        
        if (diffIsAll != 1e7) return diffIsAll;

    } else {
        for (std::size_t i = 0; i < m_GivenHybridAlgs.size(); i++) {
            diffIsAtLeastOne = std::max(m_GivenHybridAlgs[i]->getDiff(currBackUp), diffIsAtLeastOne);
        }
        if (diffIsAtLeastOne != 0) return diffIsAtLeastOne;
    }
    return  0;
};