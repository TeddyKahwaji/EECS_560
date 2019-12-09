Lab08: main.o LNode.o LeftistMinHeap.o Executive.o
	g++ -std=c++11 -g -Wall main.o LNode.o  LeftistMinHeap.o Executive.o -o Lab08

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

LNode.o: LNode.h
	g++ -std=c++11 -g -Wall -c LNode.cpp

LeftistMinHeap.o: LeftistMinHeap.h
	g++ -std=c++11 -g -Wall -c LeftistMinHeap.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o Lab08
