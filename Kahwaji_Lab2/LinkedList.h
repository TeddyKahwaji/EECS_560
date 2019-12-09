#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <iostream>
using namespace std;
#include <cstring>
template <typename T>


class LinkedList
{
public:
  ~LinkedList();
  bool contains(T entry);
  void clear();
  LinkedList();
  bool isEmpty();
  void insert(T entry);
  void Print();
  void Remove(T anEntry);
  Node<T>* getFront();
  int getLength();
private:
  Node<T>* m_front = nullptr;
  int m_length =0;

};
#include "LinkedList.cpp"
#endif
