#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include <iostream>
using namespace std;


class MinHeap
{
public:
  void insert(int value);
  void Delete();
  int PQ_Highest();
  int PQ_Lowest();
  void LevelOrder();

protected:
  bool DoesntHaveChildren(int lastVal);
  void DownHeap(int position);
  void printArray();
  void heapify(int position);
  void swap(int val1, int val2);
private:
  int m_size = 15000;
  int capacity = 0;
  int m_array[15000];
};
#endif
