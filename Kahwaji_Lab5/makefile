Lab05: main.o BinaryNode.o BinarySearchTree.o Executive.o
	g++ -std=c++11 -g -Wall main.o BinaryNode.o BinarySearchTree.o Executive.o -o Lab05

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

BinaryNode.o: BinaryNode.h
	g++ -std=c++11 -g -Wall -c BinaryNode.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
BinarySearchTree.o: BinarySearchTree.h
		g++ -std=c++11 -g -Wall -c BinarySearchTree.cpp
clean:
	rm *.o Lab05
