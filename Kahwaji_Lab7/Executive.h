#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <fstream>
#include <iostream>
#include <cstring>
#include "MinMaxHeap.h"
using namespace std;

class Executive
{
public:
Executive(string FileName);
void PrintMenu();

protected:
void BuildHeap();
void Insert();
void Delete();
void MinLevelElements();
void MaxLevelElements();
string cleanString(string dirty);
int getLength(string word);

private:
MinMaxHeap MinMax;
fstream inFile;

};
#endif
