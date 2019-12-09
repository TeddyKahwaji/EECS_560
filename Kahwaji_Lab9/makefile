Lab09: main.o MinSkewHeap.o MSNode.o Executive.o
	g++ -std=c++11 -g -Wall main.o MinSkewHeap.o MSNode.o Executive.o -o Lab09

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

MSNode.o: MSNode.h
	g++ -std=c++11 -g -Wall -c MSNode.cpp

MinSkewHeap.o: MinSkewHeap.h
	g++ -std=c++11 -g -Wall -c MinSkewHeap.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o Lab09
