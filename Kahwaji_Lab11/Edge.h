#ifndef EDGE_H
#define EDGE_H
#include <iostream>
using namespace std;


class Edge
{
public:
  Edge();
  Edge(int v1, int v2);
  void setWeight(int weight);
  int getWeight();
  string getEdge();
  int getFirstVertice();
  int getSecondVertice();
  bool operator==(Edge& rhs);
  bool operator!=(Edge& rhs);
private:
  int m_v1;
  int m_v2;
  int m_weight;
};
#endif
