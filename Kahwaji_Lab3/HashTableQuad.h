#ifndef HASH_TABLE_QUAD
#define HASH_TABLE_QUAD
#include <iostream>
#include <cstring>
#include "Yelp.h"

class HashTableQuad
{
public:
  HashTableQuad();
  ~HashTableQuad();
  HashTableQuad(int bucketSize);
  void insert(Yelp restaraunt);
  void Delete(string restaraunt);
  void FindByRating(int rating);
  void FindByName(string name);
  void SearchByPrice(string price);
  void Print();
  Yelp* getArray();
protected:
  int hashFunction(string name);
  int computeStringLength(string word);
private:
Yelp* m_array;
int m_numOfKeys =0;
int m_bucketSize;
};
#endif
