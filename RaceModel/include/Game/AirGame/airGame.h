#pragma once
#include <iostream>
#include <string>
#include "Game/gameEngine.h"
#include <typeinfo>

class airGame : public gameEngine
{
private:
    
public:
    explicit airGame();
    explicit airGame(std::string_view name, std::size_t duration);
    
    void runGame() override;
    void addRacers(air* racer) override;
    ~airGame() ;
    
};