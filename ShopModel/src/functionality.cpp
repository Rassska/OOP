#include <bits/stdc++.h>

#include "sshop.h"
#include "product.h"
#include "functionality.h"


functionality::functionality () = default;
functionality::~functionality () = default;
const void functionality::makeProduct (const std::string& productName) {
    product* newProductP = new product(productName);
    productBase_.push_back(newProductP);
}

const void functionality::makeShop (const std::string& shopName, const std::string& shopAddress) {
    shop* newShopP = new shop(shopName, shopAddress);
    shopBase_.push_back(newShopP);
}

const void functionality::addProducts (const std::size_t shopId, const std::size_t productId, const std::string& productName, const std::size_t cnt, const std::size_t cost) {
    (*shopBase_[shopId]->getProducts()).emplace(std::make_pair(productId, productName), std::make_pair(cnt, cost));
}

const void functionality::setNewProductCost(const std::size_t shopId, const std::size_t productId, const std::size_t newCost) {
    auto it = shopBase_[shopId]->getProductsItBegin();
    while (it != shopBase_[shopId]->getProductsItEnd()) {
        if (it->first.first == productId)
            it->second.second = newCost;
        it++;
    }
}

const void functionality::setNewProductCount(const std::size_t shopId, const std::size_t productId, std::size_t newCnt) {
    auto it = shopBase_[shopId]->getProductsItBegin();
    while (it != shopBase_[shopId]->getProductsItEnd()) {
        if (it->first.first == productId)
            it->second.first = newCnt;
        it++;
    }
}
const void functionality::showProductList(const size_t shopId) const {

        std::map <std::pair<size_t, std::string>, std::pair <std::size_t, std::size_t>>:: iterator it;
        std::cout << '\n' << "shopId: " << shopBase_[shopId]->getShopId() << ' ' << shopBase_[shopId]->getShopName() << ' ' << shopBase_[shopId]->getShopAddress() << '\n';
        it = shopBase_[shopId]->getProductsItBegin();
        while (it != shopBase_[shopId]->getProductsItEnd()) {
            std::cout << "Id: " << it->first.first << ' ' << "Name: " << it->first.second << ' ' << "Cost: " << it->second.second << ' ' << "Count: " << it->second.first << '\n';
            it++;
        }
       
}
const void functionality::showByingForFixSum (const std::size_t shopId, const std::size_t fixSum) const {
    
    std::size_t fixSumD = fixSum;
    auto it = shopBase_[shopId]->getProductsItBegin();
    std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>> possibleByingList;
    while (it != shopBase_[shopId]->getProductsItEnd()) {
        if (it->second.second > fixSumD) {
            it++;
            continue;;
        }
        std::size_t maxCurrenVegCnt = std::min((fixSumD / it->second.second), it->second.first);
        fixSumD -= maxCurrenVegCnt * it->second.second;
        possibleByingList.emplace(std::make_pair(it->first.first, it->first.second),  std::make_pair(maxCurrenVegCnt, it->second.second));
        it++;
    }

    auto it1 = possibleByingList.begin();
    std::size_t totalPurchasesSum = 0;
    while (it1 != possibleByingList.end()) {
        totalPurchasesSum += it1->second.first * it1->second.second;
        std::cout << '\n' << "Id: " << it1->first.first  << ' ' << "Name: " << it1->first.second << ' ' << "Count: " << it1->second.first << ' ' << "Cost: " << it1->second.second;
        it1++;
    }
    std::cout << '\n' << '\n';
    std::cout << "Total sum of current purchases: " <<totalPurchasesSum;
    std::cout << '\n';

}

const void functionality::showByingBatchVeg (const std::size_t shopId, std::vector <std::pair<const std::size_t, const std::size_t>>& batch) const {
    auto it = shopBase_[shopId]->getProductsItBegin();
    auto it1 = batch.begin();
    std::size_t totalSum = 0;
    while (it1 != batch.end()) {
        while (it != shopBase_[shopId]->getProductsItEnd()) {
            if (it->first.first == it1->first) {
                if (it1->second > it->second.first) {
                    throw std::runtime_error ("The amount of vegetables less than requested!");
                } else {
                    totalSum += it->second.second * it1->second;
                }
            }
            it++;
        }
        it1++;
    }
    std::cout << totalSum;
}
const void functionality::showMinBatchCost (const std::vector <std::pair<const std::size_t, const std::size_t>>& batch)const {
    std::size_t ansShopId = 0;
    auto it1 = batch.begin();
    std::size_t minAns = INT_MAX;
    
    for (std::size_t i = 0; i < shopBase_.size(); i++) {
        std::size_t total = 0;
        std::size_t checkCnt = batch.size();

        while (it1 != batch.end()) { 
        auto it = shopBase_[i]->getProductsItBegin();
            while (it != shopBase_[i]->getProductsItBegin()) {  
                if (it->first.first == it1->first) {
                    if (it->second.first >= it1->second) {
                        total += it1->second * it->second.second;
                        checkCnt--;
                        break;
                    } 
                }
                it++;
            }
            it1++;
        }
        if (checkCnt == 0) {
            if (minAns > total) {
                minAns = total;
                ansShopId = i;
            }
        }
    }
    std::cout << minAns << ' ' << ansShopId;
}
const void functionality::showMinCostProductShop (const std::size_t productId) {
    std::size_t minCost = INT_MAX;
    shop* ans = nullptr;
    std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>>:: iterator it;
    for (std::size_t i = 0; i < shopBase_.size(); i++) {
        it = shopBase_[i]->getProductsItBegin();
        
        while (it != shopBase_[i]->getProductsItEnd()) {
            if (it->second.second < minCost && it->first.first == productId) {
                minCost = it->second.second;
                ans = shopBase_[i];
            }
            it++;
        }
    }
    std::cout << ans->getShopId();
}