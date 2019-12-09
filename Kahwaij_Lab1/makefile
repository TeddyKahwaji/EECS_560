Lab01: main.o DoublyLinkedList.o Node.o Executive.o
	g++ -std=c++11 -g -Wall main.o DoublyLinkedList.o Node.o Executive.o -o Lab01

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

DoublyLinkedList.o: DoublyLinkedList.h
	g++ -std=c++11 -g -Wall -c DoublyLinkedList.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Node.o:Node.h
	g++ -std=c++11 -g -Wall -c Node.cpp
clean:
	rm *.o Lab01
