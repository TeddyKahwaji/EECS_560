#include "BinaryNode.h"


BinaryNode::BinaryNode()
{
  m_leftChildPtr = nullptr;
  m_rightChildPtr = nullptr;
}
BinaryNode::BinaryNode(char value)
{
  m_leftChildPtr = nullptr;
  m_rightChildPtr = nullptr;
  m_value = value;
}


void BinaryNode::setLeftChild(BinaryNode* left)
{
  m_leftChildPtr = left;
}
void BinaryNode::setRightChild(BinaryNode* right)
{
  m_rightChildPtr = right;
}

void BinaryNode::setValue(char value)
{
  m_value = value;
}

char BinaryNode::getValue()
{
  return m_value;
}

BinaryNode* BinaryNode::getLeftChild()
{
  return m_leftChildPtr;
}

BinaryNode* BinaryNode::getRightChild()
{
  return m_rightChildPtr;
}
