#pragma once
#include <bits/stdc++.h>


class product {
private:
    size_t productId_;
    std::string productName_;
    
public:

    explicit product();
    explicit product(const std::string& productName);
    
    const size_t getProductId() const;
    const std::string getProductName() const;

    friend class shop;

    ~product();
    static size_t cntOfProducts;

};