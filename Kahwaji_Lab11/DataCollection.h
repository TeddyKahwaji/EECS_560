#ifndef DATA_COLLECTION_H
#define DATA_COLLECTION_H

#include <fstream>
#include <iomanip>
#include <time.h>
#include "DisjointSet.h"


class DataCollection
{
public:
void runDataSuite();
void IntializeSet();
void UnionData();
void FindDataWithoutCompression();
void FindDataWithCompression();
private:
  clock_t t;
  int m_dataSize = 1000;
  DisjointSet ds;
  fstream inFile;
  ofstream outFile;

};
#endif
