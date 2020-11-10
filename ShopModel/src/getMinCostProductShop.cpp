#include "getMinCostProductShop.h"
#include <bits/stdc++.h>
#include "sshop.h"

shop* getMinCostProductShop (const std::vector <shop*>& shopBase, const size_t productId) {
    
    size_t minCost = INT_MAX;
    shop* ans = nullptr;
    std::map <size_t, std::pair <size_t, size_t>>:: iterator it;
    for (size_t i = 0; i < shopBase.size(); i++) {
        it = shopBase[i]->products.begin();
        
        while (it != shopBase[i]->products.end()) {
            if (it->second.first < minCost && it->first == productId) {
                minCost = it->second.first;
                ans = shopBase[i];
            }
            it++;
        }
        
        
        
    }
    return ans;

}