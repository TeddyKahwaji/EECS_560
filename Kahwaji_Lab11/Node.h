#ifndef NODE_H
#define NODE_H
template <typename T>
class Node
{
public:
  Node(T value);
  Node();
  void setNext(Node<T>* next);
  Node<T>* getNext();
  void setEntry(T anEntry);
  T getEntry();

private:
  T m_entry;
  Node<T>* m_next;
};
#include "Node.cpp"
#endif
