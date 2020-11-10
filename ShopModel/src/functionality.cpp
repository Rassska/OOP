#include <bits/stdc++.h>
#include <product.h>
#include "sshop.h"
#include "product.h"
#include "functionality.h"


functionality::functionality () = default;
functionality::~functionality () = default;
const void functionality::makeProduct (std::vector <product*>& productBase_, const std::string& productName) const {

    product* firstProductP = new product(productName);
    product* secondProductP = new product(productName);
    product* thirdProductP = new product(productName);
    product* fourthProductP = new product(productName);
    product* fifthProductP = new product(productName);
    product* sixthProductP = new product(productName);
    product* seventhProductP = new product(productName);
    product* eighthProductP = new product(productName);
    product* ninthProductP = new product(productName);
    product* tenthProductP = new product(productName);

    productBase_.push_back(firstProductP);
    productBase_.push_back(secondProductP);
    productBase_.push_back(thirdProductP);
    productBase_.push_back(fourthProductP);
    productBase_.push_back(fifthProductP);
    productBase_.push_back(sixthProductP);
    productBase_.push_back(seventhProductP);
    productBase_.push_back(eighthProductP);
    productBase_.push_back(ninthProductP);
    productBase_.push_back(tenthProductP);

}

const void functionality::makeShop (std::vector <shop*>& shopBase_, const std::string& shopName, const std::string& shopAddress) const {

    shop* firstShopP = new shop(shopName, shopAddress);
    shop* secondShopP = new shop(shopName, shopAddress);
    shop* thirdShopP = new shop(shopName, shopAddress);
    shopBase_.push_back(firstShopP);
    shopBase_.push_back(secondShopP);
    shopBase_.push_back(thirdShopP);
}

const void functionality::addProducts (std::vector <shop*>& shopBase_, const size_t shopId, const size_t productId, const std::string& productName, const size_t cnt, const size_t cost) {
    shopBase_[shopId]->products.emplace(std::make_pair(productId, productName), std::make_pair(cnt, cost));
}

const void functionality::setNewProductCost(std::vector <shop*>& shopBase_, const size_t shopId, const size_t productId, const size_t newCost) {
    auto it = shopBase_[shopId]->products.begin();
    while (it != shopBase_[shopId]->products.end()) {
        if (it->first.first == productId)
            it->second.second = newCost;
        it++;
    }
}

const void functionality::setNewProductCount(std::vector <shop*>& shopBase_, const size_t shopId, const size_t productId, size_t newCnt) {
    auto it = shopBase_[shopId]->products.begin();
    while (it != shopBase_[shopId]->products.end()) {
        if (it->first.first == productId)
            it->second.first = newCnt;
        it++;
    }
}
const void functionality::showProductList(const std::vector <shop*>& shopBase_, const size_t shopId) const {

        std::map <std::pair<size_t, std::string>, std::pair <size_t, size_t>>:: iterator it;
        std::cout << '\n' << "shopId: " << shopBase_[shopId]->shopId_ << ' ' << shopBase_[shopId]->shopName_ << ' ' << shopBase_[shopId]->shopAddress_ << '\n';
        it = shopBase_[shopId]->products.begin();
        while (it != shopBase_[shopId]->products.end()) {
            std::cout << "Id: " << it->first.first << ' ' << "Name: " << it->first.second << ' ' << "Cost: " << it->second.second << ' ' << "Count: " << it->second.first << '\n';
            it++;
        }
       
}
const void functionality::byingForFixSum (const std::vector <shop*>& shopBase_, const size_t shopId, const size_t fixSum) const {
    
    size_t fixSumD = fixSum;
    auto it = shopBase_[shopId]->products.begin();
    std::map <std::pair<size_t, std::string>, std::pair <size_t, size_t>> possibleByingList;
    while (it != shopBase_[shopId]->products.end()) {
        if (it->second.second > fixSumD) {
            it++;
            continue;;
        }
        size_t maxCurrenVegCnt = std::min((fixSumD / it->second.second), it->second.first);
        fixSumD -= maxCurrenVegCnt * it->second.second;
        possibleByingList.emplace(std::make_pair(it->first.first, it->first.second),  std::make_pair(maxCurrenVegCnt, it->second.second));
        it++;
    }

    auto it1 = possibleByingList.begin();
    size_t totalPurchasesSum = 0;
    while (it1 != possibleByingList.end()) {
        totalPurchasesSum += it1->second.first * it1->second.second;
        std::cout << '\n' << "Id: " << it1->first.first  << ' ' << "Name: " << it1->first.second << ' ' << "Count: " << it1->second.first << ' ' << "Cost: " << it1->second.second;
        it1++;
    }
    std::cout << '\n' << '\n';
    std::cout << "Total sum of current purchases: " <<totalPurchasesSum;
    std::cout << '\n';

}

const void functionality::byingBatchVeg (const std::vector <shop*>& shopBase_, const size_t shopId, const std::vector <std::pair<const size_t, const size_t>>& batch) const {
    auto it = shopBase_[shopId]->products.begin();
    auto it1 = batch.begin();
    size_t totalSum = 0;
    while (it1 != batch.end()) {
        while (it != shopBase_[shopId]->products.end()) {
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
const void functionality::getMinBatchCost (const std::vector <shop*>& shopBase_, const std::vector <std::pair<const size_t, const size_t>>& batch)const {
    size_t ansShopId = 0;
    auto it1 = batch.begin();
    size_t minAns = INT_MAX;
    
    for (size_t i = 0; i < shopBase_.size(); i++) {
        size_t total = 0;
        size_t checkCnt = batch.size();

        while (it1 != batch.end()) { 
        auto it = shopBase_[i]->products.begin();
            while (it != shopBase_[i]->products.end()) {  
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