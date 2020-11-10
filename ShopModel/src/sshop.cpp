#include "sshop.h"
#include <bits/stdc++.h>

size_t shop::cntOfShops = 0;

shop::shop () :
    shopId_(cntOfShops) 
    {
        cntOfShops++;
       
    }
shop::shop(const std::string& shopName, const std::string& shopAddress) :
    shopName_(shopName), shopAddress_(shopAddress), shopId_(cntOfShops) 
    {
        cntOfShops++;
     
    }

shop::~shop(){}

const size_t shop::getShopId() const {return shopId_;}

const void shop::addProducts (const size_t productId, size_t cnt, size_t cost) {
    this->products.emplace(productId, std::make_pair(cnt, cost));
}

const void shop::printProductList() {
    auto it = products.begin();
    while (it != products.end()) {
        std::cout << it->first << ' ' << it->second.first << ' ' << it->second.second << std::endl;
        it++;
    }
}

void shop::setNewProductCost(const size_t productId, size_t newCost) {
    auto it = products.begin();
    while (it != products.end()) {
        if (it->first == productId)
            it->second.second = newCost;
        it++;
    }
}

void shop::setNewProductCount(const size_t productId, size_t newCnt) {
    auto it = products.begin();
    while (it != products.end()) {
        if (it->first == productId)
            it->second.first = newCnt;
        it++;
    }
}