Lab11: main.o DNode.o DisjointSet.o Executive.o DataCollection.o Graph.o Edge.o MinHeap.o
	g++ -std=c++11 -g -Wall main.o DNode.o DisjointSet.o Executive.o DataCollection.o Graph.o Edge.o MinHeap.o -o Lab11

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

DNode.o: DNode.h
	g++ -std=c++11 -g -Wall -c DNode.cpp

DisjointSet.o: DisjointSet.h
	g++ -std=c++11 -g -Wall -c DisjointSet.cpp

DataCollection.o: DataCollection.h
	g++ -std=c++11 -g -Wall -c DataCollection.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Graph.o: Graph.h
	g++ -std=c++11 -g -Wall -c Graph.cpp

Edge.o: Edge.h
	g++ -std=c++11 -g -Wall -c Edge.cpp

MinHeap.o: MinHeap.h
	g++ -std=c++11 -g -Wall -c MinHeap.cpp
	
clean:
	rm *.o Lab11
