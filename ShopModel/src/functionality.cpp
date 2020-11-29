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


const void functionality::addProducts (const std::size_t shopId, const std::pair<std::size_t, std::string> prodIdName,  const std::pair<std::size_t, std::size_t> prodCntCost) const {
    shopBase_[shopId]->addProducts(prodIdName, prodCntCost);
}

const void functionality::setNewProductCost(const std::size_t shopId, const std::size_t productId, const std::size_t newCost) const {
    shopBase_[shopId]->setNewProductCost(productId, newCost);
}

const void functionality::setNewProductCount(const std::size_t shopId, const std::size_t productId, const std::size_t newCnt) const {
    shopBase_[shopId]->setNewProductCount(productId, newCnt);
}
const void functionality::showProductList(const size_t shopId) const {
    shopBase_[shopId]->showProductList();
}


const void functionality::showByingForFixSum (const std::size_t shopId, const std::size_t fixSum) const {
    shopBase_[shopId]->showByingForFixSum(fixSum);
}

const void functionality::showByingBatchVeg (const std::size_t shopId, const std::vector <std::pair <std::size_t, std::size_t>>& batch) const {
    std::cout << shopBase_[shopId]->getBatchCost(batch);

}
const void functionality::showMinBatchCost (const std::vector <std::pair<std::size_t, std::size_t>>& batch) const{ 

    std::size_t ansShopId = 0;
    std::size_t minCost = std::numeric_limits<std::size_t>::max();

    for (std::size_t i = 0; i < shopBase_.size(); i++) {
        if (shopBase_[i]->getBatchCost(batch) < minCost) {
            minCost = shopBase_[i]->getBatchCost(batch);
            ansShopId = i;
        }
    }

    std::cout << minCost << ' ' << ansShopId << '\n';
    
}

const void functionality::showMinCostProductShop (const std::size_t productId) {
    std::size_t minCost = std::numeric_limits<std::size_t>::max();
    std::size_t ansShopId = std::numeric_limits<std::size_t>::max();
   
    for (std::size_t i = 0; i < shopBase_.size(); i++) {
        if (shopBase_[i]->getProdCost(productId) < minCost) {
            minCost = shopBase_[i]->getProdCost(productId);
            ansShopId = i;
        }
    }
    std::cout << minCost << ' ' << ansShopId << '\n';
}