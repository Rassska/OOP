#include <iostream>
#include "Game/gameEngine.h"
#include "Game/AirGame/airGame.h"
#include "Game/GroundGame/groundGame.h"
#include "Vehicle/VehicleTypes/GroundTypes/centaur.h"
#include "Vehicle/VehicleTypes/GroundTypes/boots.h"
#include "Vehicle/VehicleTypes/GroundTypes/swiftCamel.h"
#include "Vehicle/VehicleTypes/AirTypes/carpet.h"
#include "Vehicle/VehicleTypes/AirTypes/besom.h"
#include "Vehicle/VehicleTypes/AirTypes/broom.h"


int main () {


    std::cout << "First ground race:\n"; 
    gameEngine* gameP = new groundGame("first", 1000);

    ground* centaurP = new centaur(std::string_view("centaur-Vlad"), 15, 8, 2);
    ground* bootsP = new boots(std::string_view("boots"), 6, 60, 10);
    ground* swiftCamelP = new swiftCamel(std::string_view("Camel-Ruslan"), 40, 10, 5);

    // air* carpetP = new carpet(std::string_view("carp"), 1/*  */0, 3);

    try {
        gameP->addRacers(centaurP); // ground* centaurP = new centaur(std::string_view("Boyka"), 15, 8, 2);
        gameP->addRacers(bootsP);  //  ground* bootsP = new boots(std::string_view("Nike"), 6, 60, 10);
        gameP->addRacers(swiftCamelP);  //  ground* swiftCamelP = new swiftCamel(std::string_view("kek"), 40, 10, 5);

        // gameP->addRacers(carpetP); // air* carpetP = new carpet(std::string_view("carp"), 10, 3);
    }
    catch(const std::runtime_error& exp) {
        std::cout << exp.what() << '\n';
    }
    gameP->runGame();
    gameP->showGameResult();








    /* std::cout << "\nSecond air race:\n";
    gameEngine* gameP2 = new airGame("first", 1000);


    air* besomP = new besom(std::string_view("Stupa-pupa"), 8); // stupa
    air* broomP = new broom(std::string_view("metla"), 20); // metla
    air* carpetP = new carpet(std::string_view("carpet"), 10);

    // air* carpetP = new carpet(std::string_view("carp"), 10, 3);

    try {
        gameP2->addRacers(besomP); // ground* centaurP = new centaur(std::string_view("Boyka"), 15, 8, 2);
        gameP2->addRacers(broomP);  //  ground* bootsP = new boots(std::string_view("Nike"), 6, 60, 10);
        gameP2->addRacers(carpetP);  //  ground* swiftCamelP = new swiftCamel(std::string_view("kek"), 40, 10, 5);

        // gameP->addRacers(carpetP); // air* carpetP = new carpet(std::string_view("carp"), 10, 3);
    }
    catch(const std::runtime_error& exp) {
        std::cout << exp.what() << '\n';
    }
    gameP2->runGame();
    gameP2->showGameResult();
    std::cout << '\n'; */

    

}