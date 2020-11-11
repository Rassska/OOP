#pragma once
#include <bits/stdc++.h>
#include <product.h>
#include "sshop.h"
#include "product.h"

class functionality
{
private:
    
public:
    explicit functionality();

    const void makeProduct (std::vector <product*>& productBase_, const std::string& productName) const ;
    const void makeShop (std::vector <shop*>& shopBase_, const std::string& shopName, const std::string& shopAddress) const;
    const void addProducts (std::vector <shop*>& shopBase_, const size_t shopId, const size_t productId, const std::string& productName, const size_t cnt, const size_t cost);
    const void setNewProductCost (std::vector <shop*>& shopBase_, const size_t shopId, const size_t productId, const size_t newCost);
    const void setNewProductCount (std::vector <shop*>& shopBase_, const size_t shopId, const size_t productId, size_t newCnt);
    const void showProductList (const std::vector <shop*>& shopBase_, const size_t shopId) const;
    const void showByingForFixSum (const std::vector <shop*>& shopBase_, const size_t shopId, const size_t fixSum) const;
    const void showByingBatchVeg (const std::vector <shop*>& shopBase_, const size_t shopId, std::vector <std::pair<const size_t, const size_t>>& batch) const;
    const void showMinBatchCost (const std::vector <shop*>& shopBase_, const std::vector <std::pair<const size_t, const size_t>>& batch)const;
    const void showMinCostProductShop (const std::vector <shop*>& shopBase, const size_t productId);
    ~functionality();
};

