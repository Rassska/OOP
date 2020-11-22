#pragma once
#include <bits/stdc++.h>


class product {
private:
    std::size_t productId_;
    std::string productName_;
    
public:

    explicit product();
    explicit product(const std::string& productName);
    
    const std::size_t getProductId() const;
    const std::string getProductName() const;

    ~product();
    static std::size_t cntOfProducts;

};