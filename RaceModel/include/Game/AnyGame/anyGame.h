#pragma once
#include <iostream>
#include <string>
#include "Game/gameEngine.h"
#include <typeinfo>

class anyGame : public gameEngine
{
private:
    
    
public:
    explicit anyGame();
    explicit anyGame(std::string_view name, std::size_t duration);
    void runGame() override;
    void addRacers(ground* racer) override;
    ~anyGame();
    
};