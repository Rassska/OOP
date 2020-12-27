#pragma once

#include "ISaveAlgCreat.h"
#include "backUp.h"


class CommonAlgorithm : public ISaveAlgCreat{
public:
    void saveFiles(BackUp b) override;
};