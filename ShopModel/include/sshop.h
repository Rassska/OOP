#pragma once
#include <bits/stdc++.h>
#include <product.h>


class shop {
private:
    size_t shopId_;
    std::string shopName_;
    std::string shopAddress_;
    std::map <std::pair<size_t, std::string>, std::pair <size_t, size_t>> products;

    
public:
    
    explicit shop();
    explicit shop(const std::string& shopName, const std::string& shopAddress);
    const size_t getShopId() const;

    static size_t cntOfShops;
    friend class functionality;
    ~shop();
};