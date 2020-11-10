#pragma once
#include <bits/stdc++.h>
#include <product.h>


class shop {
private:
    size_t shopId_;
    std::string shopName_;
    std::string shopAddress_;
    std::map <size_t, std::pair <size_t, size_t>> products;

    
public:
    
    explicit shop();
    explicit shop(const std::string& shopName, const std::string& shopAddress);
    const size_t getShopId() const;
    const void addProducts(const size_t productId, size_t cnt, size_t cost);
    void setNewProductCost(const size_t productId, size_t newCost);
    void setNewProductCount(const size_t productId, size_t newCnt);
    const void printProductList();

    static size_t cntOfShops;
    friend shop* getMinCostProductShop (const std::vector <shop*>& shopBase, const size_t productId);
    ~shop();
};