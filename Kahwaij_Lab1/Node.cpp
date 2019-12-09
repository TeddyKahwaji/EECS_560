
#include "Node.h"




Node::Node(int entry)
{
  m_entry = entry;
  m_next = nullptr;
  m_prev = nullptr;
}


Node::Node()
{
  m_next = nullptr;
  m_prev = nullptr;
}


void Node::setNext(Node* next)
{
  m_next = next;
}


void Node::setPrev(Node* prev)
{
  m_prev = prev;
}



Node* Node::getNext()
{
  return m_next;
}


Node* Node ::getPrev()
{
  return m_prev;
}


int Node ::getEntry()
{
  return m_entry;
}



void Node ::setEntry(int entry)
{
  m_entry = entry;
}
