prog: functionality.o main.o product.o sshop.o
	g++ functionality.o main.o product.o sshop.o -o prog

functionality.o: src/functionality.cpp
	g++ -c -std=c++2a -Iinclude src/functionality.cpp

main.o: src/main.cpp
	g++ -c -std=c++2a -Iinclude src/main.cpp

product.o: src/product.cpp
	g++ -c -std=c++2a -Iinclude src/product.cpp

sshop.o: src/sshop.cpp
	g++ -c -std=c++2a -Iinclude src/sshop.cpp

clean:
	rm -rf *.o prog
