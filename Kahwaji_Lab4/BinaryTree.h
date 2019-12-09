#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
using namespace std;
#include "Queue.h"
#include "BinaryNode.h"
class BinaryTree
{
public:
  ~BinaryTree();
  void clear();
  bool isFull();
  void AddItem(int x);
  void Delete();
  bool isLeaf(int x);
  void PrintLeaf();
  void PrintPreOrder();
  void PrintPostOrder();
  void PrintInOrder();
  void PrintLevelOrder();
  int getHeight();
protected:
  void _ClearHelper(BinaryNode* root);
  void _PrintLeafHelper(BinaryNode* root);
  void DeletePath(BinaryNode* initialRoot, BinaryNode* destination);
    bool _isFullHelper(BinaryNode* temp);
  void _addItem(BinaryNode* temp,int x);
  void _PrintPreOrderHelper(BinaryNode* aRoot);
  void _PrintPostOrderHelper(BinaryNode* aRoot);
  void _PrintInOrderHelper(BinaryNode* aRoot);
  void _PrintLevelOrderHelper(BinaryNode* aRoot);
  void _PrintLevel(BinaryNode* root, int level);
  BinaryNode* _isLeafHelper(BinaryNode* temp, int x);
  bool _Found(BinaryNode* temp,int value);
  int _getHeightHelper(BinaryNode* temp);
private:
  BinaryNode* m_root = nullptr;
};
#endif
