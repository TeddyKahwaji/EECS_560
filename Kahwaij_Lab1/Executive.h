#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include "DoublyLinkedList.h"


class Executive
{
public:
Executive(string fileName);
void printMenu();
void Insert();
void Delete();
void Smallest();
void Largest();
void Average();
void Merge();
void Print();
void Reverse();
private:
  fstream inFile;
  DoublyLinkedList List;

};
#endif
