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



