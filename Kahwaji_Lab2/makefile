Lab02: main.o HashTable.o Executive.o
	g++ -std=c++11 -g -Wall main.o HashTable.o Executive.o -o Lab02

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

HashTable.o: HashTable.h
	g++ -std=c++11 -g -Wall -c HashTable.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o Lab02
