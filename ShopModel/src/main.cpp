/**
 *    author:  Rasul Yunusov
 *    created: 08.10.2020 15:23:29
**/




#include <bits/stdc++.h>
#include "product.h"
#include "sshop.h"
#include "getMinCostProductShop.h"

int main () {

    std::vector <product*> productBase_;
    std::vector <shop*> shopBase_;

    product* firstProductP = new product();
    product* secondProductP = new product();
    product* thirdProductP = new product();
    productBase_.push_back(firstProductP);
    productBase_.push_back(secondProductP);
    productBase_.push_back(thirdProductP);

    shop* firstShopP = new shop();
    shop* secondShopP = new shop();
    shop* thirdShopP = new shop();
    shopBase_.push_back(firstShopP);
    shopBase_.push_back(secondShopP);
    shopBase_.push_back(thirdShopP);

    firstShopP->addProducts(firstProductP->getProductId(), /*cost*/ 1, /*cnt*/ 10);
    firstShopP->addProducts(secondProductP->getProductId(), /*cost*/ 3, /*cnt*/ 40);
    firstShopP->addProducts(thirdProductP->getProductId(), /*cost*/ 6, /*cnt*/ 80);
    
    secondShopP->addProducts(firstProductP->getProductId(), /*cost*/ 5, /*cnt*/ 10);
    secondShopP->addProducts(secondProductP->getProductId(), /*cost*/ 2, /*cnt*/ 40);
    secondShopP->addProducts(thirdProductP->getProductId(), /*cost*/ 7, /*cnt*/ 80);

    thirdShopP->addProducts(firstProductP->getProductId(), /*cost*/ 6, /*cnt*/ 10);
    thirdShopP->addProducts(secondProductP->getProductId(), /*cost*/ 9, /*cnt*/ 40);
    thirdShopP->addProducts(thirdProductP->getProductId(), /*cost*/ 2, /*cnt*/ 80);


   
    //std::cout << getMinCostProductShop(shopBase_, firstProductP->getProductId())->getShopId();
    
    



  
    

    

}