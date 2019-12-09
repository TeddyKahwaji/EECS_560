#ifndef BINOMIAL_QUEUE_H
#define BINOMIAL_QUEUE_H
#include <iostream>
using namespace std;
#include "BNode.h"
#include "Queue.h"

class BinomialQueue
{
public:
  ~BinomialQueue();
  BinomialQueue();
  bool isEmpty();
  void insert(int x);
  void levelOrder();
  void DeleteMin();
  void Reset();
protected:
void clearTrees(BNode* root);
void Union(BNode* root);
BNode* BHeapMerge(BNode* h1, BNode* h2);
void printElements(BNode* aRoot);
private:
BNode* m_array[10000];
BNode* m_root = nullptr;
};
#endif
