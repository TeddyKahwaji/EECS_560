Lab04: main.o BinaryNode.o BinaryTree.o Executive.o
	g++ -std=c++11 -g -Wall main.o BinaryNode.o BinaryTree.o Executive.o -o Lab04

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

BinaryNode.o: BinaryNode.h
	g++ -std=c++11 -g -Wall -c BinaryNode.cpp

BinaryTree.o: BinaryTree.h
	g++ -std=c++11 -g -Wall -c BinaryTree.cpp
clean:
	rm *.o Lab04
