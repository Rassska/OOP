#pragma once
#include <bits/stdc++.h>
#include <product.h>


class shop {
private:
    std::size_t shopId_;
    std::string shopName_;
    std::string shopAddress_;

    std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>> products;

    
public:
    
    explicit shop();
    explicit shop(const std::string& shopName, const std::string& shopAddress);
    const std::size_t getShopId() const;
    const std::string getShopName() const;
    const std::string getShopAddress() const;
    
    void addProducts (std::pair<std::size_t, std::string> prodIdName, std::pair<std::size_t, std::size_t> prodCntCost);
    void setNewProductCost (std::size_t productId, std::size_t newCost) ;
    void setNewProductCount (std::size_t productId, std::size_t newCnt) ;
    void showByingForFixSum (std::size_t fixSum);

    std::size_t getBatchCost (std::vector <std::pair<std::size_t, std::size_t>> batch);
    std::size_t getProdCost (const std::size_t prodId) const;
    void showProductList();
    static std::size_t cntOfShops;

    ~shop();
};