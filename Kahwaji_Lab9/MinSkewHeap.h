#ifndef LEFTIST_MIN_HEAP_H
#define LEFTIST_MIN_HEAP_H
#include <iostream>
using namespace std;
#include "MSNode.h"


class MinSkewHeap
{
public:
bool isEmpty();
void insert(int x);
void MergeHeaps(MinSkewHeap& newHeap);
void DeleteValue(int x);
bool Find(int value);
void Preorder();
void Inorder();
void PostOrder();
int getHeight();
void LevelOrder();
~MinSkewHeap();
protected:
  MSNode* findParent(MSNode* root, MSNode* target);
  MSNode* FindNode(MSNode* temp, int value);
  bool FindHelper(MSNode* root, int value);
  void clear(MSNode* root);
  void setRoot(MSNode* value);
  MSNode* getRoot();
  MSNode* Merge(MSNode* H1, MSNode* H2);
  MSNode* BreakTrees(MSNode* h1, MSNode* h2);
  int getRank(MSNode* ptr);
  void swapSubTrees(MSNode* h1);
  MSNode* getFarRightNode(MSNode* root);
  int getHeight(MSNode* root);
  void _PrintLevelOrderHelper(MSNode* root);
  void _PrintLevel(MSNode* root, int level);
  void PreOrderPrint(MSNode* root);
  void InOrderPrint(MSNode* root);
  void PostOrderPrint(MSNode* root);
private:
  bool m_left = false;
  bool m_right = false;
  int m_size = 0;
  MSNode* m_root = nullptr;
};
#endif
