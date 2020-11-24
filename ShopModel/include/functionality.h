#pragma once
#include <bits/stdc++.h>
#include "sshop.h"
#include "product.h"

class functionality
{
private:
    
public:
std::vector <product*> productBase_;
    std::vector <shop*> shopBase_;
    explicit functionality();

    const void makeProduct (const std::string& productName);
    const void makeShop (const std::string& shopName, const std::string& shopAddress);
    const void addProducts (const std::size_t shopId, const std::size_t productId, const std::string& productName, const std::size_t cnt, const std::size_t cost);
    const void setNewProductCost (const std::size_t shopId, const std::size_t productId, const std::size_t newCost);
    const void setNewProductCount (const std::size_t shopId, const std::size_t productId, std::size_t newCnt);
    const void showProductList (const std::size_t shopId) const;
    const void showByingForFixSum (const std::size_t shopId, const std::size_t fixSum) const;
    const void showByingBatchVeg (std::size_t shopId, std::vector <std::pair<const std::size_t, const std::size_t>>& batch) const;
    const void showMinBatchCost (std::vector <std::pair<const std::size_t, const std::size_t>>& batch)const;
    const void showMinCostProductShop (const std::size_t productId);
    ~functionality();
};

