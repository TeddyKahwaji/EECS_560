#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h>
#include "Graph.h"
#include "DataCollection.h"
#include "DisjointSet.h"
using namespace std;

class Executive
{
public:
  Executive(string fileName);
  void MainMenu();
  void printMenuDS();
  void printMenuGraph();
protected:
void IntializeGraph();
void MakeSet();
void StartUnion();
void Find_Timer();
void Path_Compression();
void BFS();
void DFS();
void Kruskal();
void Prim(); 
private:
  DataCollection data;
  clock_t t;
  string m_fileName;
  string m_fileName2;
  fstream graphFile;
  DisjointSet ds;
  Graph g;
  fstream inFile;
  bool m_hasMadeSet = false;
};
#endif
