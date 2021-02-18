#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "BackUp.h"
#include "ISave.h"

struct SaveManager
{
    SaveManager();
    void saveAs(const BackUp* currBackUp, ISave* currSaveAlg);
    ~SaveManager();
};