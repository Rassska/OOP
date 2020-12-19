#include <iostream>
#include "Game/gameEngine.h"
#include "Game/AnyGame/anyGame.h"
#include "Vehicle/vehicle.h"
#include "Vehicle/VehicleTypes/ground.h"
#include "Vehicle/VehicleTypes/air.h"
#include <typeinfo>

anyGame::anyGame(std::string_view name, std::size_t duration) :
    gameEngine(name, duration) {};

anyGame::anyGame() = default;

anyGame::~anyGame() {}

void anyGame::addRacers(ground* racer) {
    racers_.push_back(racer);
}

void anyGame::runGame() {
    
}