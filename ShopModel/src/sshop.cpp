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

const std::size_t shop::getShopId() const {return shopId_;}
const std::string shop::getShopName() const {return shopName_;}
const std::string shop::getShopAddress() const {return shopAddress_;}

const std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>>::iterator shop::begin() {return products.begin();}
const std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>>::iterator shop::end() {return products.end();}

void addProducts (std::pair<const std::size_t, const std::string> first, std::pair<const std::size_t, const std::size_t> second);

void shop::addProducts (std::pair<const std::size_t, const std::string> first, std::pair<const std::size_t, const std::size_t> second) {
    products.emplace(std::make_pair(first.first, first.second), std::make_pair(second.first, second.second));
}



