#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Vehicle/vehicle.h"
#include "Vehicle/VehicleTypes/ground.h"
#include "Vehicle/VehicleTypes/air.h"

class gameEngine {
public:
    explicit gameEngine();
    explicit gameEngine(std::string_view name, std::size_t duration);

    virtual void addRacers(ground* racer);
    virtual void addRacers(air* racer);
    virtual void runGame();

    virtual ~gameEngine();
    void showSizeRacers();
    void showGameResult();

protected:

    std::string_view name_;
    std::size_t duration_;
    std::vector <vehicle*> racers_;
    std::vector<std::pair<vehicle*, std::size_t>> gameResult;
};