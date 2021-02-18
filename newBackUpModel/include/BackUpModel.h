#pragma once
#include "BackUp.h"
#include <iostream>
#include <string>
#include <vector>

class BackUpModel
{
private:
    std::vector<BackUp*>* m_BackUpStorage;
    
public:
    explicit BackUpModel();
    ~BackUpModel();
};

