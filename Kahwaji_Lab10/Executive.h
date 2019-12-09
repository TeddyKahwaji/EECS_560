#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "BinomialQueue.h"
using namespace std;

class Executive
{
public:
  Executive(string fileName);
  void printMenu();
protected:
void _insert();
void _DeleteMin();
void _LevelOrder(); 
private:
  BinomialQueue bq;
  fstream inFile;
};
#endif
