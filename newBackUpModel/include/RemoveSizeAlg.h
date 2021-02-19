#pragma once
#include "IRemove.h"
#include "BackUp.h"
#include <iostream>
#include <vector>
#include <string>


class RemoveSizeAlg : public IRemove {
    std::size_t m_SizeLimit;

public:
    RemoveSizeAlg(std::size_t sizeLimit);
    std::size_t getDiff(const BackUp& currBackUp) override;
    ~RemoveSizeAlg();
};