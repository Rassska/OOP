#include <bits/stdc++.h>

#include "sshop.h"
#include "product.h"
#include "functionality.h"


functionality::functionality () = default;
functionality::~functionality () = default;
void functionality::makeProduct (const std::string& productName) {
    product* newProductP = new product(productName);
    productBase_.push_back(newProductP);
}

void functionality::makeShop (const std::string& shopName, const std::string& shopAddress) {
    shop* newShopP = new shop(shopName, shopAddress);
    shopBase_.push_back(newShopP);
}


void functionality::addProducts (const std::size_t shopId, const std::pair<std::size_t, std::string> prodIdName,  const std::pair<std::size_t, std::size_t> prodCntCost) const {
    shopBase_[shopId]->addProducts(prodIdName, prodCntCost);
}

void functionality::setNewProductCost(const std::size_t shopId, const std::size_t productId, const std::size_t newCost) const {
    try {
        shopBase_[shopId]->setNewProductCost(productId, newCost);
    } catch (const std::runtime_error& exp) {
        std::cout << exp.what() << '\n';
    }
}

void functionality::setNewProductCount(const std::size_t shopId, const std::size_t productId, const std::size_t newCnt) const {
    try {
        shopBase_[shopId]->setNewProductCount(productId, newCnt);
    } catch (const std::runtime_error& exp) {
        std::cout << exp.what() << '\n';
    }
}
void functionality::showProductList(const size_t shopId) const {
    shopBase_[shopId]->showProductList();
}


void functionality::showByingForFixSum (const std::size_t shopId, const std::size_t fixSum) const {
    shopBase_[shopId]->showByingForFixSum(fixSum);
}

void functionality::showByingBatchVeg (const std::size_t shopId, const std::vector <std::pair <std::size_t, std::size_t>>& batch) const {
    try {
        std::cout << shopBase_[shopId]->getBatchCost(batch);
    } catch (std::runtime_error& exp) {
        std::cout << exp.what() << '\n';
    }

}
void functionality::showMinBatchCost (const std::vector <std::pair<std::size_t, std::size_t>>& batch) const{ 

    std::size_t ansShopId = std::numeric_limits<std::size_t>::max();
    std::size_t minCost = std::numeric_limits<std::size_t>::max();

    for (std::size_t i = 0; i < shopBase_.size(); i++) {
        if (shopBase_[i]->getBatchCost(batch) < minCost) {
            minCost = shopBase_[i]->getBatchCost(batch);
            ansShopId = i;
        }
    }

    if (minCost != std::numeric_limits<std::size_t>::max()) {
        std::cout << minCost << ' ' << ansShopId << '\n';
    } else {
        std::cout << "There is no matter to set up this batch!";
    }
}

void functionality::showMinCostProductShop (const std::size_t productId) const {

        std::size_t minCost = std::numeric_limits<std::size_t>::max();
        std::size_t ansShopId = std::numeric_limits<std::size_t>::max();
    
        for (std::size_t i = 0; i < shopBase_.size(); i++) {
            if (shopBase_[i]->getProdCost(productId) < minCost) {
                minCost = shopBase_[i]->getProdCost(productId);
                ansShopId = i;
            }
        }
        if (minCost != std::numeric_limits<std::size_t>::max()) {
            std::cout << minCost << ' ' << ansShopId << '\n';
        } else {
            std::cout << "Didn't found such product in shop base!" << '\n';
        }
}