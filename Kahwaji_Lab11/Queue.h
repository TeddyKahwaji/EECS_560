#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
#include "Node.h"
template <typename T>


class Queue
{
public:
  void clear();
  bool contains(T value);
  void insert(T value);
  T Dequeue();
  T peek();
  bool isEmpty();
  Node<T>* getFront();
  T getMin();
  void print(void op(T obj));
  int getLength();
  ~Queue();
private:
  int m_length =0;
  Node<T>* m_front= nullptr;
  Node<T>* m_back = nullptr;
};
#include "Queue.cpp"
#endif
