#ifndef GRAPH_H
#define GRAPH_H
using namespace std;
#include <iostream>
#include <fstream>
#include "MinHeap.h"
#include "DisjointSet.h"
#include "Edge.h"
#include "Queue.h"


class Graph
{
public:
  ~Graph();
  void BuildGraph(int** cost, int n);
  void Prims();
  void Kruskal();
  void BFS();
  void DFS();
protected:
  void _DFS(int vertices, bool* arr);
  void buildVertices();
  void buildEdgesArray();
  void intializeLookUpTable();
  void intializeLookUpEdgeTable();
private:
  int** m_costArray;
  int m_cost;
  Edge* eArray;
  Queue<Edge> currentEdges;
  Queue<int> lookUpTable[1000];
  Queue<Edge> lookUpEdgeTable[1000];
  int m_sizeEdgesArray;
  int* m_vArray;
  fstream inFile;
};
#endif
