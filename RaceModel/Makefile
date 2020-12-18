prog: besom.o broom.o carpet.o bactrianCamel.o boots.o centaur.o swiftCamel.o air.o ground.o vehicle.o main.o gameEngine.o airGame.o groundGame.o anyGame.o
	g++ besom.o broom.o carpet.o bactrianCamel.o boots.o centaur.o swiftCamel.o air.o ground.o vehicle.o main.o gameEngine.o airGame.o groundGame.o anyGame.o -o prog

besom.o: src/Vehicle/VehicleTypes/AirTypes/besom.cpp
	g++ -c -std=c++2a -Iinclude src/Vehicle/VehicleTypes/AirTypes/besom.cpp

broom.o: src/Vehicle/VehicleTypes/AirTypes/broom.cpp
	g++ -c -std=c++2a -Iinclude src/Vehicle/VehicleTypes/AirTypes/broom.cpp

carpet.o: src/Vehicle/VehicleTypes/AirTypes/carpet.cpp
	g++ -c -std=c++2a -Iinclude src/Vehicle/VehicleTypes/AirTypes/carpet.cpp

bactrianCamel.o: src/Vehicle/VehicleTypes/GroundTypes/bactrianCamel.cpp
	g++ -c -std=c++2a -Iinclude src/Vehicle/VehicleTypes/GroundTypes/bactrianCamel.cpp

boots.o: src/Vehicle/VehicleTypes/GroundTypes/boots.cpp
	g++ -c -std=c++2a -Iinclude src/Vehicle/VehicleTypes/GroundTypes/boots.cpp

centaur.o: src/Vehicle/VehicleTypes/GroundTypes/centaur.cpp
	g++ -c -std=c++2a -Iinclude src/Vehicle/VehicleTypes/GroundTypes/centaur.cpp

swiftCamel.o: src/Vehicle/VehicleTypes/GroundTypes/swiftCamel.cpp
	g++ -c -std=c++2a -Iinclude src/Vehicle/VehicleTypes/GroundTypes/swiftCamel.cpp

air.o: src/Vehicle/VehicleTypes/air.cpp
	g++ -c -std=c++2a -Iinclude src/Vehicle/VehicleTypes/air.cpp

ground.o: src/Vehicle/VehicleTypes/ground.cpp
	g++ -c -std=c++2a -Iinclude src/Vehicle/VehicleTypes/ground.cpp

vehicle.o: src/Vehicle/vehicle.cpp
	g++ -c -std=c++2a -Iinclude src/Vehicle/vehicle.cpp

main.o: src/main.cpp
	g++ -c -std=c++2a -Iinclude src/main.cpp

gameEngine.o: src/Game/gameEngine.cpp
	g++ -c -std=c++2a -Iinclude src/Game/gameEngine.cpp

airGame.o: src/Game/AirGame/airGame.cpp
	g++ -c -std=c++2a -Iinclude src/Game/AirGame/airGame.cpp

groundGame.o: src/Game/GroundGame/groundGame.cpp
	g++ -c -std=c++2a -Iinclude src/Game/GroundGame/groundGame.cpp

anyGame.o: src/Game/AnyGame/anyGame.cpp
	g++ -c -std=c++2a -Iinclude src/Game/AnyGame/anyGame.cpp

clean:
	rm -rf *.o prog