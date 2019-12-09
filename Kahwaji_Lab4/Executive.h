#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <fstream>
#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Executive
{
public:
Executive(string FileName);
void PrintMenu();

protected:
  void PrintLeafs();
  void isFull();
  void AddItem();
  void Delete();
  void Leaf();
  void Height();
  void PreOrder();
  void PostOrder();
  void InOrder();
  void LevelOrder();
private:
BinaryTree m_tree;
fstream inFile;

};
#endif
