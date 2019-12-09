Lab10: main.o BNode.o BinomialQueue.o Executive.o
	g++ -std=c++11 -g -Wall main.o BNode.o BinomialQueue.o Executive.o -o Lab10

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

BNode.o: BNode.h
	g++ -std=c++11 -g -Wall -c BNode.cpp

BinomialQueue.o: BinomialQueue.h
	g++ -std=c++11 -g -Wall -c BinomialQueue.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o Lab10
