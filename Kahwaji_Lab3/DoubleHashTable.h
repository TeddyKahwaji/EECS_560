#ifndef DOUBLE_HASH_TABLE
#define DOUBLE_HASH_TABLE
#include <iostream>
#include <cstring>
#include "Yelp.h"


class DoubleHashTable
{
public:
  ~DoubleHashTable();
  DoubleHashTable();
  DoubleHashTable(int bucketSize);
  void insert(Yelp restaraunt);
  void Delete(string restaraunt);
  void FindByRating(int rating);
  void FindByName(string name);
  void SearchByPrice(string price);
  void Print();
  Yelp* getArray();

protected:
  int hashFunction(string name);
  int DoubleHashFunction(string word);
  int computeStringLength(string word);
private:
  Yelp* m_array;
  int m_numOfKeys =0;
  int m_bucketSize;
  int rValue;
};
#endif
