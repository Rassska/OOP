/**
 *    author:  Rasul Yunusov
 *    created: 08.10.2020 15:23:29
**/




#include <bits/stdc++.h>
#include "product.h"
#include "sshop.h"

#include "functionality.h"

int main () {

    std::vector <product*> productBase_;
    std::vector <shop*> shopBase_;
    functionality functions;

    functions.makeShop(shopBase_, "The Veg Box", "Vyazemsky lane 5-7");
    functions.makeShop(shopBase_, "Veg and More", "Nevsky Prospect 141");
    functions.makeShop(shopBase_, "Natures Gift", "Vladimirsky prospect 45");

    functions.makeProduct(productBase_, "Potato");      // productId = 0
    functions.makeProduct(productBase_, "Tomato");      // productId = 1
    functions.makeProduct(productBase_, "Carrot");      // productId = 2
    functions.makeProduct(productBase_, "Pepper");      // productId = 3
    functions.makeProduct(productBase_, "Onion");       // productId = 4
    functions.makeProduct(productBase_, "Garlic");      // productId = 5
    functions.makeProduct(productBase_, "Radish");      // productId = 6
    functions.makeProduct(productBase_, "Corn");        // productId = 7
    functions.makeProduct(productBase_, "Beets");       // productId = 8
    functions.makeProduct(productBase_, "Green beans"); // productId = 9
    functions.makeProduct(productBase_, "Eggplant");    // productId = 10
   
    functions.addProducts(shopBase_, /*shopId*/ 0, /*productId*/ 0,  "Potato",       /*cnt*/ 10,  /*cost*/ 1000);
    functions.addProducts(shopBase_, /*shopId*/ 0, /*productId*/ 1,  "Tomato",       /*cnt*/ 100, /*cost*/ 700);
    functions.addProducts(shopBase_, /*shopId*/ 0, /*productId*/ 2,  "Carrot",       /*cnt*/ 50,  /*cost*/ 600);
    functions.addProducts(shopBase_, /*shopId*/ 0, /*productId*/ 3,  "Pepper",       /*cnt*/ 80,  /*cost*/ 800);
    functions.addProducts(shopBase_, /*shopId*/ 0, /*productId*/ 4,  "Onion",        /*cnt*/ 40,  /*cost*/ 900);
    functions.addProducts(shopBase_, /*shopId*/ 0, /*productId*/ 7,  "Corn",         /*cnt*/ 137, /*cost*/ 180);
    functions.addProducts(shopBase_, /*shopId*/ 0, /*productId*/ 6,  "Radish",       /*cnt*/ 1205, /*cost*/ 682);
    functions.addProducts(shopBase_, /*shopId*/ 0, /*productId*/ 5,  "Garlic",       /*cnt*/ 565,  /*cost*/ 147);
    
    functions.addProducts(shopBase_, /*shopId*/ 1, /*productId*/ 10, "Eggplant",     /*cnt*/ 30,  /*cost*/ 78);
    functions.addProducts(shopBase_, /*shopId*/ 1, /*productId*/ 9,  "Green beans",  /*cnt*/ 16,  /*cost*/ 150);
    functions.addProducts(shopBase_, /*shopId*/ 1, /*productId*/ 8,  "Beets",        /*cnt*/ 121, /*cost*/ 180);
    functions.addProducts(shopBase_, /*shopId*/ 1, /*productId*/ 7,  "Corn",         /*cnt*/ 133, /*cost*/ 130);
    functions.addProducts(shopBase_, /*shopId*/ 1, /*productId*/ 6,  "Radish",       /*cnt*/ 120, /*cost*/ 680);
    functions.addProducts(shopBase_, /*shopId*/ 1, /*productId*/ 5,  "Garlic",       /*cnt*/ 56,  /*cost*/ 140);
    functions.addProducts(shopBase_, /*shopId*/ 1, /*productId*/ 1,  "Tomato",       /*cnt*/ 77,  /*cost*/ 130);

    functions.addProducts(shopBase_, /*shopId*/ 2, /*productId*/ 6,  "Radish",       /*cnt*/ 300, /*cost*/ 780);
    functions.addProducts(shopBase_, /*shopId*/ 2, /*productId*/ 5,  "Garlic",       /*cnt*/ 156, /*cost*/ 154);
    functions.addProducts(shopBase_, /*shopId*/ 2, /*productId*/ 3,  "Pepper",       /*cnt*/ 11,  /*cost*/ 1220);
    functions.addProducts(shopBase_, /*shopId*/ 2, /*productId*/ 1,  "Tomato",       /*cnt*/ 13,  /*cost*/ 170);
    functions.addProducts(shopBase_, /*shopId*/ 2, /*productId*/ 10, "Eggplant",     /*cnt*/ 309, /*cost*/ 780);
    functions.addProducts(shopBase_, /*shopId*/ 2, /*productId*/ 8,  "Beets",        /*cnt*/ 18,  /*cost*/ 15440);
    functions.addProducts(shopBase_, /*shopId*/ 2, /*productId*/ 9,  "Green beans",  /*cnt*/ 45,  /*cost*/ 1220);
    functions.addProducts(shopBase_, /*shopId*/ 2, /*productId*/ 7,  "Corn",         /*cnt*/ 20,  /*cost*/ 170);

    /* 3 */
    // functions.showProductList(shopBase_, 2);
    // functions.setNewProductCost(shopBase_, 2, 1, 2000);
    // functions.showProductList(shopBase_, 2);
    
    /* 4 */
    // functions.showMinCostProductShop(shopBase_,  3);
   

    /* 5 */
    // functions.showByingForFixSum(shopBase_, 2, 15500);

    /* 6 */
    // std::vector <std::pair<const size_t, const size_t>> batch_;
    // batch_.emplace_back(6, 100);
    // batch_.emplace_back(5, 100);
    // batch_.emplace_back(1, 10);
    // batch_.emplace_back(7, 10);

    // functions.showByingBatchVeg (shopBase_, 2, batch_);
    
    /* 7 */
    // functions.showMinBatchCost (shopBase_, batch_);
    



    
    



  
    

    

}