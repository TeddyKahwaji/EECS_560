#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>
#include <cstring>
using namespace std;
#include "LinkedList.h"


class HashTable
{
public:
  HashTable();
  ~HashTable();
  HashTable(int bucketSize);
  void insert(string aValue);
  void Find(string value);
  void Print();
  void Delete(string value);
protected:
  int getLength(string word);
  int HashFunction(string word, int bucketSize);
  void Rehash();
  int smallestPrime(int num);
  bool isPrime(int num);
private:

  double numberOfKeys =0;
  LinkedList<string>* m_array;
  int m_bucketSize;

};
#endif
