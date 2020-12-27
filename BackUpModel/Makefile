prog: backUp.o backUpApp.o delDateAlg.o delLengthAlg.o delSizeAlg.o file.o IDelAlg.o incremental.o ISaveAlgCreat.o newFF.o restorePoint.o saveComm.o saveSepAlg.o main.o
	g++ backUp.o backUpApp.o delDateAlg.o delLengthAlg.o delSizeAlg.o file.o IDelAlg.o incremental.o ISaveAlgCreat.o main.o newFF.o restorePoint.o saveComm.o saveSepAlg.o -o prog

backUp.o: src/backUp.cpp
	g++ -c -std=c++2a -Iinclude src/backUp.cpp

backUpApp.o: src/backUpApp.cpp
	g++ -c -std=c++2a -Iinclude src/backUpApp.cpp

delDateAlg.o: src/delDateAlg.cpp
	g++ -c -std=c++2a -Iinclude src/delDateAlg.cpp

delLengthAlg.o: src/delLengthAlg.cpp
	g++ -c -std=c++2a -Iinclude src/delLengthAlg.cpp

delSizeAlg.o: src/delSizeAlg.cpp
	g++ -c -std=c++2a -Iinclude src/delSizeAlg.cpp

file.o: src/file.cpp
	g++ -c -std=c++2a -Iinclude src/file.cpp

IDelAlg.o: src/IDelAlg.cpp
	g++ -c -std=c++2a -Iinclude src/IDelAlg.cpp

incremental.o: src/incremental.cpp
	g++ -c -std=c++2a -Iinclude src/incremental.cpp

ISaveAlgCreat.o: src/ISaveAlgCreat.cpp
	g++ -c -std=c++2a -Iinclude src/ISaveAlgCreat.cpp

main.o: src/main.cpp
	g++ -c -std=c++2a -Iinclude src/main.cpp

newFF.o: src/newFF.cpp
	g++ -c -std=c++2a -Iinclude src/newFF.cpp

restorePoint.o: src/restorePoint.cpp
	g++ -c -std=c++2a -Iinclude src/restorePoint.cpp

saveComm.o: src/saveComm.cpp
	g++ -c -std=c++2a -Iinclude src/saveComm.cpp

saveSepAlg.o: src/saveSepAlg.cpp
	g++ -c -std=c++2a -Iinclude src/saveSepAlg.cpp

clean:
	rm -rf *.o prog