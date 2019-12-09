#include "Edge.h"

Edge::Edge()
{

}
Edge::Edge(int v1, int v2)
{
  m_v1 = v1;
  m_v2 = v2;
}
void Edge::setWeight(int weight)
{
  m_weight = weight;
}

int Edge::getWeight()
{
  return m_weight;
}

string Edge::getEdge()
{
  string edge = "(" + to_string(m_v1) + "," + to_string(m_v2) + ")";
  return edge;
}

int Edge::getFirstVertice()
{
  return m_v1;
}
int Edge::getSecondVertice()
{
  return m_v2;
}
bool Edge::operator==(Edge& rhs)
{
  return getEdge() == rhs.getEdge();
}
bool Edge::operator!=(Edge& rhs)
{
  return getEdge() != rhs.getEdge();
}
