#pragma once
#include <string>
#include "backUp.h"


class ISaveAlgCreat{
protected:
    std::string_view m_path;
public:
    std::string_view getPath();
    void setPath(std::string_view path);
    virtual void saveFiles(BackUp b) = 0;
};