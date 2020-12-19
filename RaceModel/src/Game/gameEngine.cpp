#include <iostream>
#include "Game/gameEngine.h"
#include "Vehicle/VehicleTypes/ground.h"
#include "Vehicle/VehicleTypes/air.h"
#include <typeinfo>

gameEngine::gameEngine() = default;

gameEngine::gameEngine (std::string_view name, std::size_t duration) :
    name_(name), duration_(duration) {};

gameEngine::~gameEngine() {}

void gameEngine::addRacers(ground* racer) {
    throw std::runtime_error("Game only for the air racers! Get out from here!");
}
void gameEngine::addRacers(air* racer) {
    throw std::runtime_error("Game only for the ground racers! Get out from here!");
}
void gameEngine::runGame() {
    
}

void gameEngine::showSizeRacers() {
    std::cout << racers_.size();
}

void gameEngine::showGameResult() {

    for (std::size_t i = 0; i < gameResult.size(); i++) {
        std::cout << gameResult[i].first->getName() << ' ' << gameResult[i].second << '\n';
    }
}