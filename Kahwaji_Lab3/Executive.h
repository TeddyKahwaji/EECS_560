#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <fstream>
#include <iostream>
#include "HashTableQuad.h"
#include "DoubleHashTable.h"
using namespace std;

class Executive
{
public:
Executive(string FileName);
void PrintMenu();
~Executive();
protected:
int getLength(string word);
void Insert();
void Delete();
void FindByName();
void FindByRating();
void SearchByPrice();
void Print();
string cleanString(string word);
private:
HashTableQuad m_QuadhashTable;
DoubleHashTable m_DoubleHash;
fstream inFile;

};
#endif
