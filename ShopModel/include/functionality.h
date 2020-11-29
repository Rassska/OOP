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

    void makeProduct (const std::string& productName);
    void makeShop (const std::string& shopName, const std::string& shopAddress);
    void addProducts (const std::size_t shopId, const std::pair<std::size_t, std::string> prodIdName, const std::pair<std::size_t, std::size_t> prodCntCost) const ;
    void setNewProductCost (const std::size_t shopId, const std::size_t productId, const std::size_t newCost) const;
    void setNewProductCount (const std::size_t shopId, const std::size_t productId, const std::size_t newCnt) const;
    void showProductList (const std::size_t shopId) const;
    void showByingForFixSum (const std::size_t shopId, const std::size_t fixSum) const;
    void showByingBatchVeg (const std::size_t shopId, const std::vector <std::pair<std::size_t, std::size_t>>& batch) const;
    void showMinBatchCost (const std::vector <std::pair<std::size_t, std::size_t>>& batch) const;
    void showMinCostProductShop (const std::size_t productId) const;
    ~functionality();
};

