#ifndef LEFTIST_MIN_HEAP_H
#define LEFTIST_MIN_HEAP_H
#include <iostream>
using namespace std;
#include "LNode.h"


class LeftistMinHeap
{
public:
bool isEmpty();
void insert(int x);
void MergeHeaps(LeftistMinHeap& newHeap);
void DeleteMin();
int FindMin();
void Preorder();
void Inorder();
void PostOrder();
int getHeight();
void LevelOrder();
~LeftistMinHeap();
protected:
  void clear(LNode* root);
  void setRoot(LNode* value);
  LNode* getRoot();
  LNode* Merge(LNode* H1, LNode* H2);
  LNode* BreakTrees(LNode* h1, LNode* h2);
  int getRank(LNode* ptr);
  void swapSubTrees(LNode* h1);
  LNode* getFarRightNode(LNode* root);
  int getHeight(LNode* root);
  void _PrintLevelOrderHelper(LNode* root);
  void _PrintLevel(LNode* root, int level);
  void PreOrderPrint(LNode* root);
  void InOrderPrint(LNode* root);
  void PostOrderPrint(LNode* root);
private:
  LNode* m_root = nullptr;
};
#endif
