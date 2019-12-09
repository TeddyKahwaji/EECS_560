Lab03: main.o Executive.o Yelp.o HashTableQuad.o DoubleHashTable.o
	g++ -std=c++11 -g -Wall main.o Executive.o Yelp.o HashTableQuad.o DoubleHashTable.o -o Lab03

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

DoubleHashTable.o: DoubleHashTable.h
	g++ -std=c++11 -g -Wall -c DoubleHashTable.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

HashTableQuad.o: HashTableQuad.h
	g++ -std=c++11 -g -Wall -c HashTableQuad.cpp

Yelp.o: Yelp.h
	g++ -std=c++11 -g -Wall -c Yelp.cpp

clean:
	rm *.o Lab03
