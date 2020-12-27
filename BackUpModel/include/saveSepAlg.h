#pragma once

#include "ISaveAlgCreat.h"
#include "backUp.h"


class SeparateAlgorithm : public ISaveAlgCreat{
public:
    void saveFiles(BackUp b) override;
};