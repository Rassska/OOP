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
void anyGame::addRacers(air* racer) {
    racers_.push_back(racer);
}

void anyGame::runGame() {
     
    for (std::size_t i = 0; i < racers_.size(); i++) {
        std::size_t ansTime = 0;
        std::size_t passedDistance = 0;
        air* av = dynamic_cast<air*>(racers_[i]);
        ground* gv = dynamic_cast<ground*>(racers_[i]);

        if (av != nullptr) {
            std::size_t cutDuration = av->getNewDistance(duration_);
            while (passedDistance < cutDuration) {
                passedDistance += racers_[i]->getSpeed();
                ansTime++;
            }
            gameResult.emplace_back(racers_[i], ansTime);
        } else if(gv != nullptr) {
            std::size_t restCnt = 0;
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