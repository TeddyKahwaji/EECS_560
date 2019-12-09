#ifndef MIN_MAX_HEAP_H
#define MIN_MAX_HEAP_H
#include <iostream>
#include <cmath>
using namespace std;


class MinMaxHeap
{
public:
  void insert(int x);
  void Delete();
  void PrintMinLevels();
  void PrintMaxLevels();
  bool isEmpty();
  void BuildHeap();
protected:
  void DownHeapMaxLevel(int position);
  void DownHeapMinLevel(int position);
  int getLevel(int position);
  void swap(int position1, int position2);
  void upheapMinLevel(int position);
  void upheapMaxLevel(int position);
private:
  int m_capacity =0;
  int m_array[15000];
};
#endif
