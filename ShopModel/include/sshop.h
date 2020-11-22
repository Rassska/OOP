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
    std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>>::iterator getProductsItBegin () ;
    std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>>::iterator getProductsItEnd () ;
    std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>>* getProducts();
    static std::size_t cntOfShops;

    ~shop();
};