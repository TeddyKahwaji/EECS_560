#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "LeftistMinHeap.h"
class Executive
{
public:
  Executive(string fileName);
  void printMenu();
protected:
  void Insert();
  void Merge();
  void Deletemin();
  void FindMin();
  void Preorder();
  void Inorder();
  void Postorder();
  void Levelorder();
private:
fstream inFile;
LeftistMinHeap lmh;


};
#endif
