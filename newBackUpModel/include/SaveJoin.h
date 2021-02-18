#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "BackUp.h"
#include "ISave.h"

class SaveJoin : public ISave
{
private:
    
public:
    SaveJoin();
    void save(const BackUp* currBackUp) override;
    ~SaveJoin();
};