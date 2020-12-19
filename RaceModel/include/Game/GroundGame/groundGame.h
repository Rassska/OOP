#pragma once
#include <iostream>
#include <string>
#include "Game/gameEngine.h"
#include <typeinfo>

class groundGame : public gameEngine
{
private:
    
    
public:
    explicit groundGame();
    explicit groundGame(std::string_view name, std::size_t duration);
    void runGame() override;
    void addRacers(ground* racer) override;
    
    ~groundGame();
    
};