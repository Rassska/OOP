#pragma once
#include <iostream>
#include <string>
#include <vector>

class RestorePoint
{
private:
   bool m_IsIncrement;
   std::vector<std::string_view> m_CurrPointFiles;
public:
    RestorePoint(std::vector <std::pair<std::string_view, bool>>& givenFiles, bool isIncrement);
    std::size_t getRestPointSize() const;
    const std::vector<std::string_view>& getCurrPointFiles()const;
    bool isIncrement () const;
    ~RestorePoint();
};

