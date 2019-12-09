#include "MinHeap.h"


bool MinHeap::contains(Edge e)
{
  for (int i =0; i<capacity;i++)
  {
    if(m_array[i].getEdge() == e.getEdge())
    {
      return true;
    }
  }

  for(int i =0; i<m_hasVisitedSize;i++)
  {
    if(hasVisited[i] == e)
    {
      return true; 
    }
  }
  return false;
}

bool MinHeap::isEmpty()
{
  return capacity ==0;
}
bool MinHeap::DoesntHaveChildren(int lastVal)
{
  int leftChild = (3* lastVal +1);
  int middleChild = (3* lastVal +2);
  int rightChild = (3* lastVal +3);

  return !(leftChild < capacity) && !(middleChild < capacity) && !(rightChild < capacity);
}

Edge MinHeap::PQ_Lowest()
{
  Edge maxVal = m_array[capacity-1];
  int lastValue = capacity-1;

  while(DoesntHaveChildren(lastValue))
  {
    if(m_array[lastValue].getWeight() > maxVal.getWeight())
    {
      maxVal = m_array[lastValue];
    }
    lastValue--;
  }
  return maxVal;
}

Edge MinHeap::PQ_Highest()
{
  return m_array[0];
}

void MinHeap::printArray()
{
  int count =1;
  cout << m_array[0].getEdge() << endl;
  for(int i =1; i<capacity;i++)
  {
    if(count ==4)
    {
      cout << endl;
      count =1;
    }
    cout << m_array[i].getEdge() << " ";
    count++;
  }
}

void MinHeap::LevelOrder()
{
  printArray();
}
void MinHeap::swap(int val1, int val2)
{
  Edge temp = m_array[val1];
  m_array[val1] = m_array[val2];
  m_array[val2] = temp;
}

void MinHeap::heapify(int position)
{
  if(position == 0)
    return;

  int parentPosition = ((position-1)/3);
  if(m_array[position].getWeight() < m_array[parentPosition].getWeight())
  {
    swap(position,parentPosition);
    heapify(parentPosition);
  }
}


void MinHeap::insert(Edge value)
{
  if(!contains(value))
  {
    m_array[capacity] = value;
    hasVisited[m_hasVisitedSize] = value;
    m_hasVisitedSize++;
    heapify(capacity);
    capacity++;
  }
}

void MinHeap::Delete()
{
  capacity--;
  swap(capacity, 0);
  DownHeap(0);
}
void MinHeap::DownHeap(int position)
{

  int leftChild = (3* position) +1;
  int middleChild = (3* position) + 2;
  int rightChild = (3* position) +3;
  if(leftChild < capacity &&m_array[position].getWeight() > m_array[leftChild].getWeight())
  {
    swap(position,leftChild);
    DownHeap(leftChild);
  }
  if(middleChild < capacity && m_array[position].getWeight() > m_array[middleChild].getWeight())
  {
    swap(position,middleChild);
    DownHeap(middleChild);
  }
  if(rightChild< capacity && m_array[position].getWeight() > m_array[rightChild].getWeight())
  {
    swap(position,rightChild);
    DownHeap(rightChild);
  }
}
