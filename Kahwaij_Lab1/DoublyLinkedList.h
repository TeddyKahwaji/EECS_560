#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H
#include "Node.h"

class DoublyLinkedList
{

public:
~DoublyLinkedList();
bool isEmpty();
void insert(int entry);
void Delete(int entry);
void Print();
void ReverseList();
int getSmallest();
int getLargest();
int getAverage();

void Clear();
void SortMergedList();
int getLength();




private:
  int m_length = 0;
Node* m_front= nullptr;
Node* m_back= nullptr;



};
#endif
