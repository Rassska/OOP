#include "product.h"
#include <bits/stdc++.h>

std::size_t product::cntOfProducts = 0;
product::product() :
    productId_(cntOfProducts) 
    {
        cntOfProducts++;
      
    }

product::product(const std::string& productName) :
    productName_(productName), productId_(cntOfProducts) 
    {
        cntOfProducts++;
       
    }

product::~product(){}

const std::size_t product::getProductId() const {return productId_;}
const std::string product::getProductName() const {return productName_;}

