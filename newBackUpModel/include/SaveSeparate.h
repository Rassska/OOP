#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "BackUp.h"
#include "ISave.h"

class SaveSeparate : public ISave
{
private:
    
public:
    SaveSeparate();
    void save(const BackUp* currBackUp) override;
    ~SaveSeparate();
};