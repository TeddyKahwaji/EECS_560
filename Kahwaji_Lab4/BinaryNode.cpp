#include "BinaryNode.h"


BinaryNode::BinaryNode()
{
  m_leftChildPtr = nullptr;
  m_rightChildPtr = nullptr;
}
BinaryNode::BinaryNode(int value)
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

void BinaryNode::setValue(int value)
{
  m_value = value;
}

int BinaryNode::getValue()
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
