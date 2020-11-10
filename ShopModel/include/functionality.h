#pragma once
#include <bits/stdc++.h>
#include <product.h>
#include "sshop.h"
#include "product.h"

class functionality
{
private:
    
public:
    functionality();

    void makeProduct (std::vector <product*>& productBase_, std::string productName);
    void makeShop (std::vector <shop*>& shopBase_, std::string shopName, std::string shopAddress);
    void addProducts (std::vector <shop*>& shopBase_, size_t shopId, size_t productId, std::string productName, size_t cnt, size_t cost);
    void setNewProductCost (std::vector <shop*>& shopBase_, const size_t shopId, const size_t productId, size_t newCost);
    void setNewProductCount (std::vector <shop*>& shopBase_, const size_t shopId, const size_t productId, size_t newCnt);
    void showProductList (std::vector <shop*>& shopBase_, const size_t shopId);
    void byingForFixSum (std::vector <shop*>& shopBase_, const size_t shopId, size_t fixSum);
    void byingBatchVeg (std::vector <shop*>& shopBase_, const size_t shopId, std::vector <std::pair<const size_t, size_t>>& batch);
    ~functionality();
};

