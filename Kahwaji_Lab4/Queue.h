#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
template <typename T>


class Queue
{
public:
  void insert(T value);
  T Dequeue();
  T peek();
  bool isEmpty();
  ~Queue();
private:
  Node<T>* m_front= nullptr;
  Node<T>* m_back = nullptr;
};
#include "Queue.cpp"
#endif
