#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
using namespace std;
#include "BinaryNode.h"


class BinarySearchTree
{
public:
  ~BinarySearchTree();
  void PrintPreOrder();
  void PrintInOrder();
  void PrintPostOrder();
  int getHeight();
  void Delete(char c);
  void Insert(char c);
  void PrintLevelOrder();
  bool isLeaf(char c);
  bool contains(char c);
  void PrintLeafNodes();
protected:
  void _clear(BinaryNode* root);
  void _PrintPostOrderHelper(BinaryNode* root);
  void _PrintPreOrderHelper(BinaryNode* root);
  void _PrintInOrderHelper(BinaryNode* root);
  int getHeightHelper(BinaryNode* root);
  BinaryNode* PrintLeafsHelper(BinaryNode* root);
  BinaryNode* isLeafHelper(BinaryNode* root, char c);
  void _PrintLevelOrderHelper(BinaryNode* aRoot);
  void _PrintLevel(BinaryNode* root, int level);
  BinaryNode* getMinNode(BinaryNode* root);
  BinaryNode* DeleteHelper(BinaryNode* root, char c);
  bool containsHelper(BinaryNode* root, char c);
  BinaryNode* insertHelper(BinaryNode* root, char c);
private:
  BinaryNode* m_root = nullptr;
};
#endif
