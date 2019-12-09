#include "MinMaxHeap.h"

void MinMaxHeap::swap(int position1, int position2)
{
  int temp = m_array[position1];
  m_array[position1] = m_array[position2];
  m_array[position2] = temp;
}
void MinMaxHeap::PrintMaxLevels()
{
  for(int i =0;i<m_capacity;i++)
  {
    if(getLevel(i) %2 !=0)
    {
      cout << m_array[i] << " ";
    }
  }
  cout <<endl;
}
void MinMaxHeap::PrintMinLevels()
{
  for(int i =0;i<m_capacity;i++)
  {
    if(getLevel(i) %2 ==0)
    {
      cout << m_array[i] << " ";
    }
  }
  cout <<endl;
}
bool MinMaxHeap::isEmpty()
{
  return m_capacity ==0;
}

void MinMaxHeap::upheapMinLevel(int position)
{
  if(position == 0)
  {
    return;
  }
  int parent = (position -1) /2;
  int grandparent = (parent-1) /2;
  if(m_array[position] > m_array[parent])
  {
    swap(position, parent);
    upheapMaxLevel(parent);
  }
  else if(grandparent != parent && m_array[position] < m_array[grandparent])
  {
    swap(position,grandparent);
    upheapMinLevel(grandparent);
  }

}
int MinMaxHeap::getLevel(int position)
{
  int result = (log2(position+1));
  result = result % 2;
  return result;
}
void MinMaxHeap::upheapMaxLevel(int position)
{
  if(position ==0)
  {
    return;
  }
  int parent = (position-1)/2;
  int grandparent = (parent-1) /2;
  if(m_array[position] < m_array[parent])
  {
    swap(position,parent);
    upheapMinLevel(parent);
  }
  else if(grandparent != parent && m_array[position] > m_array[grandparent])
  {
    swap(position, grandparent);
    upheapMaxLevel(grandparent);
  }
}

void MinMaxHeap::insert(int x)
{
  if(isEmpty())
  {
    m_array[m_capacity] = x;
    m_capacity++;
  }
  else if(getLevel(m_capacity) % 2 == 0)
  {
    m_array[m_capacity] =x;
    upheapMinLevel(m_capacity);
    m_capacity++;
  }
  else
  {
    m_array[m_capacity] =x;
    upheapMaxLevel(m_capacity);
    m_capacity++;
  }
}
void MinMaxHeap::DownHeapMaxLevel(int position)
{
  int leftChild = (2* position) +1;
  int rightChild = (2* position) +2;
}
void MinMaxHeap::DownHeapMinLevel(int position)
{
  int leftChild = (2* position) +1;
  int rightChild = (2* position) +2;
  int min = m_array[0];
  int minposition =0;
  for(int i= 0; i<m_capacity; i++ )
  {
    if(m_array[i] <= min)
    {
      min = m_array[i];
      minposition = i;
    }
  }
  if(m_array[minposition] < m_array[position])
  {

    swap(minposition,position);
  }
  int newLeft = (2* position)+1;
  int newRight = (2* position) +2;
  int maxPosition = m_array[newLeft] >= m_array[newRight] ? newLeft : newRight;
  if(m_array[minposition] > m_array[maxPosition])
  {

    swap(minposition,maxPosition);
  }

}

void MinMaxHeap::Delete()
{
  if(isEmpty())
  {
    cout << "Cannot delete from an empty heap" << endl;
    return;
  }
  else if(m_capacity ==1)
  {
    m_capacity--;
    return;
  }
  else if(m_capacity ==2)
  {
    swap(0,1);
    m_capacity--;
    return;
  }
  else if(m_capacity ==3)
  {
    m_capacity--;
    swap(0,m_capacity);
    if(m_array[0] > m_array[1])
    {
      swap(0,1);
    }
  }
  else
  {
    m_capacity--;
    swap(0, m_capacity);

    DownHeapMinLevel(0);
  }
}

void MinMaxHeap::BuildHeap()
{
  int count =0;
  int multiple = 2;
  cout << m_array[0] << endl;
  for(int i =1; i<m_capacity; i++)
  {
    if(count ==multiple)
    {
      count =0;
      multiple *= 2;
      cout << endl;
    }
    count ++;
    if(i != m_capacity-1)
    {
      cout << m_array[i] << ", ";
    }
    else
    {
      cout << m_array[i];
    }


  }
  cout <<endl;
}
