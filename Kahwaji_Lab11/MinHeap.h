#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include "Edge.h"
#include <iostream>
using namespace std;


class MinHeap
{
public:
  void insert(Edge value);
  void Delete();
  Edge PQ_Highest();
  Edge PQ_Lowest();
  void LevelOrder();
  bool isEmpty();
  bool contains(Edge e);
protected:
  bool DoesntHaveChildren(int lastVal);
  void DownHeap(int position);
  void printArray();
  void heapify(int position);
  void swap(int val1, int val2);
private:
  Edge hasVisited[15000];
  int m_hasVisitedSize =0;
  int m_size = 15000;
  int capacity = 0;
  Edge m_array[15000];
};
#endif
