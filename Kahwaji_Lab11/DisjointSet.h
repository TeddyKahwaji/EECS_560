#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H
#define MAX_VALUE 1001
#include <iostream>
using namespace std;
#include "DNode.h"


class DisjointSet
{
public:
~DisjointSet();
int getCardinality();
void MakeSet(int value);
void Union(int x, int y);
int Find(int anElement);
bool Contains(int anElement);
void PathCompression(int k);


private:
int m_count =0;
DNode* m_array[MAX_VALUE];

};
#endif
