#include "BinomialQueue.h"

BinomialQueue::BinomialQueue()
{
  m_root = nullptr;
  for (int i =0; i<10000;i++)
  {
    m_array[i] = nullptr;
  }
}
BinomialQueue::~BinomialQueue()
{
  for(int i =0; i<10000;i++)
  {
    if(m_array[i]!= nullptr)
    {
      clearTrees(m_array[i]);
    }
  }
}

void BinomialQueue::clearTrees(BNode* aRoot)
{
  Queue<BNode*> m_queue;
  Queue<BNode*> m_childqueue;
  m_queue.insert(aRoot);
  while(!m_queue.isEmpty())
  {
    BNode* temp = m_queue.peek();
    m_queue.Dequeue();
    if(temp != nullptr)
    {
      if(temp->getChild() != nullptr)
      {
        BNode* temp2 = temp->getChild();
        m_childqueue.insert(temp2);
        temp2 = temp2->getRSibling();
        while(temp2 != nullptr)
        {
          m_childqueue.insert(temp2);
          temp2 = temp2->getRSibling();
        }
      }
      delete temp;
    }
    if(m_queue.isEmpty())
    {
      while(!m_childqueue.isEmpty())
      {
        m_queue.insert(m_childqueue.peek());
        m_childqueue.Dequeue();
      }
    }
  }
}
bool BinomialQueue::isEmpty()
{
  return m_root == nullptr;
}
void BinomialQueue::Union(BNode* temp)
{
  int orgOrder = temp->getOrder();
  if(m_array[orgOrder] != nullptr)
  {
    Union(BHeapMerge(temp, m_array[orgOrder]));
    m_array[orgOrder] = nullptr;
  }
  else
  {
    m_array[orgOrder] = temp;
  }
}
void BinomialQueue::Reset()
{
  for (int i =0; i<10000; i++)
  {
    if(m_array[i] != nullptr)
    {
      m_root = m_array[i];
      return;
    }
  }
  m_root = nullptr;
}
void BinomialQueue::insert(int x)
{
  BNode* temp = new BNode(x);
  Union(temp);
  for (int i =0; i<10000; i++)
  {
    if(m_array[i] != nullptr)
    {
      m_root = m_array[i];
      return;
    }
  }
  m_root = nullptr;
}

BNode* BinomialQueue::BHeapMerge(BNode* h1, BNode* h2)
{
    if(h1->getKey() > h2->getKey())
    {
      BHeapMerge(h2, h1);
    }
    else
    {
      if(h1->getChild() != nullptr)
      {
        h2->setLSibling(h1->getChild()->getLSibling());
        h1->getChild()->getLSibling()->setRSibling(h2);
        h1->getChild()->setLSibling(h2);
        h1->setOrder(h1->getOrder()+1);
        return h1;

      }
      else
      {
        h1->setChild(h2);
        h1->setOrder(h1->getOrder()+1);
        return h1;
      }
    }
}
void BinomialQueue::levelOrder()
{
  for (int i =0; i<10000; i++)
  {
    if(m_array[i] != nullptr)
    {
      printElements(m_array[i]);
      cout << endl << "---" << endl;
    }
  }
}


void BinomialQueue::DeleteMin()
{
  BNode* minNode = m_root;
  for(int i =0; i<10000;i++)
  {
    if(m_array[i]!= nullptr)
    {
      if(m_array[i]->getKey() < minNode->getKey())
      {
        minNode = m_array[i];
      }
    }
  }
  int orderOfMinNode = minNode->getOrder();
  BNode** arr = new BNode*[orderOfMinNode];
  BNode* child = minNode->getChild();
  for(int i =0; child!= nullptr;i++)
  {
    arr[i] = child;
    child = child->getRSibling();
  }
  delete minNode;
  m_array[orderOfMinNode]= nullptr;

  for(int i =0; i<orderOfMinNode;i++)
  {
    BNode* temporary = arr[i];
    temporary->setLSibling(temporary);
    temporary->setRSibling(nullptr);
    Union(temporary);
  }
  delete[] arr;
  Reset();
}

void BinomialQueue::printElements(BNode* aRoot)
{
  Queue<BNode*> m_queue;
  Queue<BNode*> m_childqueue;
  int count =0;
  m_queue.insert(aRoot);
  while(!m_queue.isEmpty())
  {
    BNode* temp = m_queue.peek();
    m_queue.Dequeue();
    if(temp != nullptr)
    {
      if(temp->getChild() != nullptr)
      {
        BNode* temp2 = temp->getChild();
        m_childqueue.insert(temp2);
        temp2 = temp2->getRSibling();
        while(temp2 != nullptr)
        {
          m_childqueue.insert(temp2);
          temp2 = temp2->getRSibling();
        }
      }
      if(count ==0)
      {
        cout << temp->getKey() << endl;
        count++;
      }
      else if(count ==3)
      {
        cout << temp->getKey() << endl;
        count =1;
      }
      else
      {
          cout << temp->getKey() << " ";
          count++;
      }


    }
    if(m_queue.isEmpty())
    {
      while(!m_childqueue.isEmpty())
      {
        m_queue.insert(m_childqueue.peek());
        m_childqueue.Dequeue();
      }
    }
  }
}
