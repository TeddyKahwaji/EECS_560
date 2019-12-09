#include "LNode.h"


LNode::LNode(int value)
{
 m_entry = value;
}
void LNode::setLeftChild(LNode* ptr)
{
  m_lchild = ptr;
}

void LNode::setRightChild(LNode* ptr)
{
m_rchild = ptr;
}


void LNode::setRank(int rank)
{
  m_rank  = rank;
}

void LNode::setEntry(int entry)
{
  m_entry = entry;
}



LNode* LNode::getLeftChild()
{
  return m_lchild;
}

LNode* LNode::getRightChild()
{
  return m_rchild;
}

int LNode::getRank()
{
  return m_rank;
}

int LNode::getValue()
{
  return m_entry;
}
