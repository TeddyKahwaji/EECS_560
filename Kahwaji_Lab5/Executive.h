#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <fstream>
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

class Executive
{
public:
Executive(string FileName);
void PrintMenu();

protected:
  void PrintLeafs();
  void AddItem();
  void Delete();
  void Leaf();
  void Height();
  void PreOrder();
  void PostOrder();
  void SearchItem();
  void InOrder();
  void LevelOrder();
private:
BinarySearchTree m_tree;
fstream inFile;

};
#endif
