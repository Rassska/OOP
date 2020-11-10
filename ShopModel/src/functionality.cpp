#include <bits/stdc++.h>
#include <product.h>
#include "sshop.h"
#include "product.h"
#include "functionality.h"


functionality::functionality () = default;
functionality::~functionality () = default;
void functionality::makeProduct (std::vector <product*>& productBase_, std::string productName) {

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

void functionality::makeShop (std::vector <shop*>& shopBase_, std::string shopName, std::string shopAddress) {

    shop* firstShopP = new shop(shopName, shopAddress);
    shop* secondShopP = new shop(shopName, shopAddress);
    shop* thirdShopP = new shop(shopName, shopAddress);
    shopBase_.push_back(firstShopP);
    shopBase_.push_back(secondShopP);
    shopBase_.push_back(thirdShopP);
}

void functionality::addProducts (std::vector <shop*>& shopBase_, size_t shopId, size_t productId, std::string productName, size_t cnt, size_t cost) {
    shopBase_[shopId]->products.emplace(std::make_pair(productId, productName), std::make_pair(cnt, cost));
}

void functionality::setNewProductCost(std::vector <shop*>& shopBase_, const size_t shopId, const size_t productId, size_t newCost) {
    auto it = shopBase_[shopId]->products.begin();
    while (it != shopBase_[shopId]->products.end()) {
        if (it->first.first == productId)
            it->second.second = newCost;
        it++;
    }
}

void functionality::setNewProductCount(std::vector <shop*>& shopBase_, const size_t shopId, const size_t productId, size_t newCnt) {
    auto it = shopBase_[shopId]->products.begin();
    while (it != shopBase_[shopId]->products.end()) {
        if (it->first.first == productId)
            it->second.first = newCnt;
        it++;
    }
}
void functionality::showProductList(std::vector <shop*>& shopBase_, const size_t shopId) {

     std::map <std::pair<size_t, std::string>, std::pair <size_t, size_t>>:: iterator it;
        std::cout << '\n' << "shopId: " << shopBase_[shopId]->shopId_ << ' ' << shopBase_[shopId]->shopName_ << ' ' << shopBase_[shopId]->shopAddress_ << '\n';
        it = shopBase_[shopId]->products.begin();
        while (it != shopBase_[shopId]->products.end()) {
            std::cout << "Id: " << it->first.first << ' ' << "Name: " << it->first.second << ' ' << "Cost: " << it->second.second << ' ' << "Count: " << it->second.first << '\n';
            it++;
        }
       
}
void functionality::byingForFixSum (std::vector <shop*>& shopBase_, const size_t shopId, size_t fixSum) {
    auto it = shopBase_[shopId]->products.begin();
    std::map <std::pair<size_t, std::string>, std::pair <size_t, size_t>> possibleByingList;
    while (it != shopBase_[shopId]->products.end()) {
        if (it->second.second > fixSum) {
            it++;
            continue;;
        }
        size_t maxCurrenVegCnt = std::min((fixSum / it->second.second), it->second.first);
        fixSum -= maxCurrenVegCnt * it->second.second;
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

void functionality::byingBatchVeg (std::vector <shop*>& shopBase_, const size_t shopId, std::vector <std::pair<const size_t, size_t>>& batch) {
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