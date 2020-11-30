#include "sshop.h"
#include "product.h"
#include <bits/stdc++.h>

std::size_t shop::cntOfShops = 0;

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

std::size_t shop::getShopId() const {return shopId_;}
std::string shop::getShopName() const {return shopName_;}
std::string shop::getShopAddress() const {return shopAddress_;}

void shop::addProducts (std::pair<std::size_t,std::string> prodIdName, std::pair<std::size_t, std::size_t> prodCntCost) {
    products.emplace(prodIdName, prodCntCost);
}

void shop::setNewProductCost (std::size_t productId, std::size_t newCost) {
    auto it = products.begin();
    bool check = false;
    while (it != products.end()) {
        if (it->first.first == productId) {
            it->second.second = newCost;
            check = true;
        }
        it++;
    }
    if (!check)
        throw std::runtime_error("There is no such product to set new cost!");
}

void shop::setNewProductCount (std::size_t productId, std::size_t newCnt) {
    auto it = products.begin();
    bool check = false;
    while (it != products.end()) {
        if (it->first.first == productId) {
            it->second.first = newCnt;
            check = true;
        }
        it++;
    }
    if (!check)
        throw std::runtime_error("There is no such product to set new count!");
}

void shop::showProductList() {
    auto it = products.begin();
    std::cout << '\n' << "shopId: " << getShopId() << ' ' << getShopName() << ' ' << getShopAddress() << '\n';
    while (it != products.end()) {
        std::cout << "Id: " << it->first.first << ' ' << "Name: " << it->first.second << ' ' << "Cost: " << it->second.second << ' ' << "Count: " << it->second.first << '\n';
        it++;
    }

}

void shop::showByingForFixSum (std::size_t fixSum) {
    
    std::size_t fixSumD = fixSum;
    auto it = products.begin();
    std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>> possibleByingList;
    while (it != products.end()) {
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

std::size_t shop::getBatchCost (const std::vector <std::pair<std::size_t, std::size_t>>& batch) const {
    
    auto batchIt = batch.begin();
    std::size_t totalSum = 0;
    bool check = true;

    while (batchIt != batch.end()) {
        check = false;
        auto prodIt = products.begin();
        while (prodIt != products.end()) {
            if (prodIt->first.first == batchIt->first) { // if ids are the same
                if (batchIt->second > prodIt->second.first) { // if the amount which requested more than existing
                    throw std::runtime_error ("The amount of vegetables less than requested!");
                } else {
                    totalSum += prodIt->second.second * batchIt->second;
                    check = true;
                    break;
                }
            }
            prodIt++;
        }
        if (!check)
            throw std::runtime_error("There is no some batch products in this shop!");

        batchIt++;
    }
    return totalSum;
}

std::size_t shop::getProdCost (const std::size_t prodId) const {
    auto it = products.begin();
    std::size_t ans = std::numeric_limits<std::size_t>::max();
    while (it != products.end()) {
        if (it->first.first == prodId) {
            ans = it->second.second;
            break;
        }
        it++;
    }

    return ans;
}
