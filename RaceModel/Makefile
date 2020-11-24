prog: besom.o broom.o carpet.o bactrianCamel.o boots.o centaur.o swiftCamel.o air.o ground.o vehicle.o main.o game.o
	g++ besom.o broom.o carpet.o bactrianCamel.o boots.o centaur.o swiftCamel.o air.o ground.o vehicle.o main.o game.o -o prog

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
	g++ -c -std=c++2a src/main.cpp

game.o: src/Game/game.cpp
	g++ -c -std=c++2a -Iinclude src/Game/game.cpp

clean:
	rm -rf *.o prog