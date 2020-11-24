#pragma once
#include <bits/stdc++.h>
#include <product.h>


class shop {
private:
    std::size_t shopId_;
    std::string shopName_;
    std::string shopAddress_;

    std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>> products;

    
public:
    
    explicit shop();
    explicit shop(const std::string& shopName, const std::string& shopAddress);
    const std::size_t getShopId() const;
    const std::string getShopName() const;
    const std::string getShopAddress() const;

    const std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>>::iterator begin();
    const std::map <std::pair<std::size_t, std::string>, std::pair <std::size_t, std::size_t>>::iterator end();


    void addProducts (std::pair<const std::size_t, const std::string> first, std::pair<const std::size_t, const std::size_t> second);

    static std::size_t cntOfShops;

    ~shop();
};