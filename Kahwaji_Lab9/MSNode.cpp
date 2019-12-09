#include "MSNode.h"


MSNode::MSNode()
{

}
MSNode::MSNode(int value)
{
 m_entry = value;
}
void MSNode::setLeftChild(MSNode* ptr)
{
  m_lchild = ptr;
}

void MSNode::setRightChild(MSNode* ptr)
{
m_rchild = ptr;
}




void MSNode::setEntry(int entry)
{
  m_entry = entry;
}



MSNode* MSNode::getLeftChild()
{
  return m_lchild;
}

MSNode* MSNode::getRightChild()
{
  return m_rchild;
}



int MSNode::getValue()
{
  return m_entry;
}
