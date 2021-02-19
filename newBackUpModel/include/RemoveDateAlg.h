#pragma once
#include "IRemove.h"
#include "BackUp.h"
#include <iostream>
#include <vector>
#include <string>

class RemoveDateAlg : public IRemove
{
private:
    time_t m_DateLimit;
public:
    RemoveDateAlg(time_t currLimit);
    std::size_t getDiff(const BackUp& currBackUp) override;
    ~RemoveDateAlg();
};