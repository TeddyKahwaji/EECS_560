#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "MinSkewHeap.h"
class Executive
{
public:
  Executive(string fileName);
  void printMenu();
protected:
  void Insert();
  void Merge();
  void Delete();
  void Find();
  void Preorder();
  void Inorder();
  void Postorder();
  void Levelorder();
private:
fstream inFile;
MinSkewHeap msh;


};
#endif
