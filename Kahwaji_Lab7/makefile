Lab07: main.o MinMaxHeap.o Executive.o
	g++ -std=c++11 -g -Wall main.o MinMaxHeap.o Executive.o -o Lab07

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

MinMaxHeap.o: MinMaxHeap.h
	g++ -std=c++11 -g -Wall -c MinMaxHeap.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o Lab07
