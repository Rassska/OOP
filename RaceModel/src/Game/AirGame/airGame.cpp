#include <iostream>
#include "Game/gameEngine.h"
#include "Game/AirGame/airGame.h"
#include "Vehicle/vehicle.h"
#include "Vehicle/VehicleTypes/air.h"



airGame::airGame(std::string_view name, std::size_t duration) :
    gameEngine(name, duration) {};

void airGame::addRacers(air* racer) {
    racers_.push_back(racer);
}

void airGame::runGame() {

     for (std::size_t i = 0; i < racers_.size(); i++) {
        std::size_t ansTime = 0;
        std::size_t passedDistance = 0;
        air* av = dynamic_cast<air*>(racers_[i]);

        if (av != nullptr) {
            std::size_t cutDuration = av->getNewDistance(duration_);
            while (passedDistance < cutDuration) {
                passedDistance += racers_[i]->getSpeed();
                ansTime++;
            }
            gameResult.emplace_back(racers_[i], ansTime);
        }
    }
}

airGame::airGame() = default;

airGame::~airGame() {}