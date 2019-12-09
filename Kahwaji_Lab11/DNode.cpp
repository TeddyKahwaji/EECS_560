#include "DNode.h"

DNode::DNode(int value)
{
  m_key = value; 
  m_parent = this;
  m_rank = 0;
}
void DNode::setRank(int aRank)
{
  m_rank = aRank;
}
int DNode::getRank()
{
  return m_rank;
}

void DNode::setParent(DNode* aParent)
{
  m_parent = aParent;
}

DNode* DNode::getParent()
{
  return m_parent;
}

void DNode::setKey(int aKey)
{
  m_key = aKey;
}

int DNode::getKey()
{
  return m_key;
}
