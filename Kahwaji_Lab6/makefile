Lab06: main.o MaxHeap.o MinHeap.o Executive.o
	g++ -std=c++11 -g -Wall main.o MaxHeap.o MinHeap.o Executive.o -o Lab06

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

MaxHeap.o: MaxHeap.h
		g++ -std=c++11 -g -Wall -c MaxHeap.cpp

MinHeap.o: MinHeap.h
		g++ -std=c++11 -g -Wall -c MinHeap.cpp

Executive.o: Executive.h
	  g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o Lab06
