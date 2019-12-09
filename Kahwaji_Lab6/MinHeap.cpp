#include "MinHeap.h"


bool MinHeap::DoesntHaveChildren(int lastVal)
{
  int leftChild = (3* lastVal +1);
  int middleChild = (3* lastVal +2);
  int rightChild = (3* lastVal +3);

  return !(leftChild < capacity) && !(middleChild < capacity) && !(rightChild < capacity);
}

int MinHeap::PQ_Lowest()
{
  int maxVal = m_array[capacity-1];
  int lastValue = capacity-1;

  while(DoesntHaveChildren(lastValue))
  {
    if(m_array[lastValue] > maxVal)
    {
      maxVal = m_array[lastValue];
    }
    lastValue--;
  }
  return maxVal;
}

int MinHeap::PQ_Highest()
{
  return m_array[0];
}

void MinHeap::printArray()
{
  int count =1;
  cout << m_array[0] << endl;
  for(int i =1; i<capacity;i++)
  {
    if(count ==4)
    {
      cout << endl;
      count =1;
    }
    cout << m_array[i] << " ";
    count++;
  }
}

void MinHeap::LevelOrder()
{
  printArray();
}
void MinHeap::swap(int val1, int val2)
{
  int temp = m_array[val1];
  m_array[val1] = m_array[val2];
  m_array[val2] = temp;
}

void MinHeap::heapify(int position)
{
  if(position == 0)
    return;

  int parentPosition = ((position-1)/3);
  if(m_array[position] < m_array[parentPosition])
  {
    swap(position,parentPosition);
    heapify(parentPosition);
  }
}

void MinHeap::insert(int value)
{
  m_array[capacity] = value;
  heapify(capacity);
  capacity++;
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
  if(leftChild < capacity &&m_array[position] > m_array[leftChild])
  {
    swap(position,leftChild);
    DownHeap(leftChild);
  }
  if(middleChild < capacity && m_array[position] > m_array[middleChild])
  {
    swap(position,middleChild);
    DownHeap(middleChild);
  }
  if(rightChild< capacity && m_array[position] > m_array[rightChild])
  {
    swap(position,rightChild);
    DownHeap(rightChild);
  }
}
