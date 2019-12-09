#include "DisjointSet.h"

DisjointSet::~DisjointSet()
{
  for(int i =1; i<=m_count; i++)
  {
    delete m_array[i];
  }
}

int DisjointSet::getCardinality()
{
  return m_count;
}

void DisjointSet::MakeSet(int value)
{
  DNode* temp = new DNode(value);
  m_array[value] = temp;
  m_count++;
}

void DisjointSet::Union(int x, int y)
{
  DNode* xPtr = m_array[x];
  DNode* yPtr = m_array[y];
  if(xPtr->getRank() < yPtr->getRank())
  {
    xPtr->setParent(yPtr);
  }
  else if(xPtr->getRank() ==  yPtr->getRank())
  {
    xPtr->setRank(xPtr->getRank()+1);
    yPtr->setParent(xPtr);
  }
  else
  {
    yPtr->setParent(xPtr);
  }
}

bool DisjointSet::Contains(int element)
{
  return m_array[element] != NULL;
}
int DisjointSet::Find(int anElement)
{

  DNode* target = m_array[anElement];
  while(target->getParent() != target)
  {
    target = target->getParent();
  }

  return target->getKey();
}


void DisjointSet::PathCompression(int k )
{
  DNode* target = m_array[k];
  DNode* temp = target;
  while(temp->getParent() != temp)
  {
    temp = temp->getParent();
  }
  target->setParent(temp);
}
