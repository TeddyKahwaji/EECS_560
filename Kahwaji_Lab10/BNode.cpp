#include "BNode.h"

BNode::BNode()
{
  m_lsibling = this;
  m_child = nullptr;
  m_rsibling= nullptr;
}
BNode::BNode(int value)
{
  m_lsibling = this;
  m_child = nullptr;
  m_rsibling = nullptr;
  m_value = value;
  m_order =0;
}
void BNode::setKey(int key)
{
  m_value = key;
}
int BNode::getKey()
{
  return m_value;
}
void BNode::setOrder(int degree)
{
  m_order = degree;
}
int BNode::getOrder()
{
  return m_order;
}

void BNode::setLSibling(BNode* sibling)
{
  m_lsibling = sibling;
}

BNode* BNode::getLSibling()
{
  return m_lsibling;
}
void BNode::setRSibling(BNode* sibling)
{
  m_rsibling = sibling;
}

BNode* BNode::getRSibling()
{
  return m_rsibling;
}
void BNode::setChild(BNode* child)
{
  m_child = child;
}
BNode* BNode::getChild()
{
  return m_child;
}
void BNode::setParent(BNode* parent)
{
  m_parent = parent;
}
BNode* BNode::getParent()
{
  return m_parent;
}
