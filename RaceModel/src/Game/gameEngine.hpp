#include <iostream>
#include <string>
#include <vector>
#include "Vehicle/vehicle.h"
#include "Vehicle/VehicleTypes/ground.h"
#include "Vehicle/VehicleTypes/air.h"

template <typename T>
class gameEngine {
public:
    explicit gameEngine() = default;
    explicit gameEngine(std::string_view name, std::size_t duration) {
        this->name_ = name;
        this->duration_ = duration;
    }

    void addRacers(T* racer) {
        this->racers_.push_back(racer);
    }
    T* runGame() {
        std::size_t minTime = std::numeric_limits<std::size_t>::max();

        T* ansObj = nullptr;
        for (std::size_t i = 0; i < racers_.size(); i++) {
            if (racers_[i]->calc(duration_) < minTime) {
                minTime = racers_[i]->calc(duration_);
                ansObj = racers_[i];
            }

        }
        return ansObj;
    }
    virtual ~gameEngine() {}

    

protected:

    std::string_view name_;
    std::size_t duration_;
    std::vector <T*> racers_;
};

