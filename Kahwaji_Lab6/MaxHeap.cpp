#include "MaxHeap.h"


bool MaxHeap::DoesntHaveChildren(int lastVal)
{
  int leftChild = (3* lastVal +1);
  int middleChild = (3* lastVal +2);
  int rightChild = (3* lastVal +3);

  return !(leftChild < capacity) && !(middleChild < capacity) && !(rightChild < capacity);
}

int MaxHeap::PQ_Lowest()
{
  int minVal = m_array[capacity-1];
  int lastValue = capacity-1;

  while(DoesntHaveChildren(lastValue))
  {
    if(m_array[lastValue] < minVal)
    {
      minVal = m_array[lastValue];
    }
    lastValue--;
  }
  return minVal;
}

void MaxHeap::printArray()
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

void MaxHeap::swap(int val1, int val2)
{
  int temp = m_array[val1];
  m_array[val1] = m_array[val2];
  m_array[val2] = temp;
}

void MaxHeap::heapify(int index)
{
  if(index ==0)
    return;

  int parentIndex = ((index-1)/3);
  if(m_array[index] > m_array[parentIndex])
  {
    swap(index, parentIndex);
    heapify(parentIndex);
  }

}

void MaxHeap::LevelOrder()
{
  printArray();
}


void MaxHeap::insert(int value)
{
  m_array[capacity] = value;
  heapify(capacity);
  capacity++;

}

int MaxHeap::PQ_Highest()
{
  if(capacity !=0)
    return m_array[0];

}

void MaxHeap::Delete()
{

  capacity--;
  swap(capacity, 0);
  DownHeap(0);
}

void MaxHeap::DownHeap(int position)
{

  int leftChild = (3* position) +1;
  int middleChild = (3* position) + 2;
  int rightChild = (3* position) +3;
  if(leftChild < capacity &&m_array[position] < m_array[leftChild])
  {
    swap(position,leftChild);
    DownHeap(leftChild);
  }
  if(middleChild < capacity && m_array[position] < m_array[middleChild])
  {
    swap(position,middleChild);
    DownHeap(middleChild);
  }
  if(rightChild< capacity && m_array[position] < m_array[rightChild])
  {
    swap(position,rightChild);
    DownHeap(rightChild);
  }
}
