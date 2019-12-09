#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "HashTable.h"
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

class Executive
{
public:
Executive(string FileName);
void PrintMenu();
protected:
string cleanString(string word);
int getLength(string word);
void Insert();
void Delete();
void Find();
void Print();
private:
HashTable m_hashTable;
fstream inFile;

};
#endif
