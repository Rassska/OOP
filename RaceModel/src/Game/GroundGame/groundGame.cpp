#include <iostream>
#include "Game/gameEngine.h"
#include "Game/GroundGame/groundGame.h"
#include "Vehicle/vehicle.h"
#include "Vehicle/VehicleTypes/ground.h"
#include <typeinfo>

groundGame::groundGame(std::string_view name, std::size_t duration) :
    gameEngine(name, duration) {};

groundGame::groundGame() = default;

groundGame::~groundGame() {}

void groundGame::addRacers(ground* racer) {
    racers_.push_back(racer);
}

void groundGame::runGame() {

    for (std::size_t i = 0; i < racers_.size(); i++) {
        std::size_t ansTime = 0;
        std::size_t passedDistance = 0;
        std::size_t restCnt = 0;
        ground* gv = dynamic_cast<ground*>(racers_[i]);

        if (gv != nullptr) {
            while (passedDistance < duration_) {
                if (!(ansTime % gv->getRestInterval())) {
                    ansTime += gv->getRestDuration();
                    restCnt++;
                    continue;
                }
                passedDistance += racers_[i]->getSpeed();
                
                ansTime++;
            }
            gameResult.emplace_back(racers_[i], ansTime);
        }
    }
}