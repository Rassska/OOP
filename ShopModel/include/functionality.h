#pragma once
#include <bits/stdc++.h>
#include "sshop.h"
#include "product.h"

class functionality
{
private:
    std::vector <product*> productBase_;
    std::vector <shop*> shopBase_;

public:

    explicit functionality();

    const void makeProduct (const std::string& productName);
    const void makeShop (const std::string& shopName, const std::string& shopAddress);
    const void addProducts (const std::size_t shopId, const std::pair<std::size_t, std::string> prodIdName, const std::pair<std::size_t, std::size_t> prodCntCost) const ;
    const void setNewProductCost (const std::size_t shopId, const std::size_t productId, const std::size_t newCost) const;
    const void setNewProductCount (const std::size_t shopId, const std::size_t productId, const std::size_t newCnt) const;
    const void showProductList (const std::size_t shopId) const;
    const void showByingForFixSum (const std::size_t shopId, const std::size_t fixSum) const;
    const void showByingBatchVeg (const std::size_t shopId, const std::vector <std::pair<std::size_t, std::size_t>>& batch) const;
    const void showMinBatchCost (const std::vector <std::pair<std::size_t, std::size_t>>& batch) const;
    const void showMinCostProductShop (const std::size_t productId);
    ~functionality();
};

