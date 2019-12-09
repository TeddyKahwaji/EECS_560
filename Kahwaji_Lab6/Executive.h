#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;

class Executive
{
public:
Executive(string FileName);
void PrintMenu();

protected:
void Insert();
void Delete();
void PQ_Highest();
void PQ_Lowest();
void LevelOrder();
void Time_LowestPQ();
void Time_HighestPQ();
void Time_Delete();
private:
clock_t t;
MaxHeap max;
MinHeap min;
fstream inFile;

};
#endif
