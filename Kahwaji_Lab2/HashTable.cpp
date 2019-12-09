#include "HashTable.h"

HashTable::HashTable()
{

}

HashTable::HashTable(int bucketSize)
{
  m_bucketSize = bucketSize;
  m_array = new LinkedList<string>[m_bucketSize];

}

HashTable::~HashTable()
{
  for(int i =0; i<m_bucketSize;i++)
  {
    m_array[i].clear();
  }
  delete[] m_array;
}

int HashTable::getLength(string word)
{
  int length =0;
  for(int i =0; i<50;i++)
  {
    if(word[i] == '\0')
    {
      return length;
    }
    length++;
  }


  return length;
}
int HashTable::HashFunction(string word, int bucketSize)
{
  int value = 0;
  int lengthOfString = getLength(word);
  for (int i =0; i<lengthOfString;i++)
  {
    value += (int)word[i];
  }

  int index = value % bucketSize;

  return index;
}

void HashTable::insert(string aValue)
{
  int index = HashFunction(aValue, m_bucketSize);
  bool hasRehashed = false;
  if(m_array[index].contains(aValue))
  {
    cout << aValue << " was not added successfully" << endl;
  }
  else
  {

    numberOfKeys++;
    double m = m_bucketSize;
    double lambda = numberOfKeys / m;
    if(lambda > 1.0)
    {
      hasRehashed = true;
      Rehash();
        index = HashFunction(aValue, m_bucketSize);
    }

    m_array[index].insert(aValue);
    if(hasRehashed)
    {
      cout << "The hashtable has rehashed" << endl;
    }
    else
    {
      cout << aValue << " was added successfully" << endl;
    }
  }

}
bool HashTable::isPrime(int num)
{
  for(int i =2; i<num/2;i++)
  {
    if(num % i ==0)
    {
      return false;
    }
  }
  return true;
}
int HashTable::smallestPrime(int size)
{
  while(1)
  {
    size++;
    if(isPrime(size))
    {
      return size;
      break;
    }

  }
}


void HashTable::Rehash()
{
  int newBucketSize = smallestPrime(m_bucketSize*2);

  LinkedList<string>* newTable = new LinkedList<string>[newBucketSize];
  for(int i =0; i<m_bucketSize; i++)
  {
    if(!m_array[i].isEmpty())
    {
      Node<string>* temp = m_array[i].getFront();
      while(temp != nullptr)
      {
        int index = HashFunction(temp->getEntry(),newBucketSize);
        newTable[index].insert(temp->getEntry());
        temp = temp->getNext();
      }
      m_array[i].clear();
    }

  }

  m_array = newTable;
  m_bucketSize = newBucketSize;

}
void HashTable::Print()
{
  for (int i =0; i<m_bucketSize;i++)
  {
    if(!m_array[i].isEmpty())
    {
      cout << i << ":-> ";
      m_array[i].Print();
      cout << endl;
    }
    else
    {
      cout << i << ": " << endl;
    }
  }
}

void HashTable::Delete(string value)
{
  int index = HashFunction(value,m_bucketSize);
  bool cannotDelete = m_array[index].isEmpty() || !m_array[index].contains(value);
  if(cannotDelete)
  {
    cout << value << " was not found" << endl;

  }
  else
  {
    m_array[index].Remove(value);
    numberOfKeys--;
    cout << value << " has been deleted" << endl;
  }


}

void HashTable::Find(string value)
{
  int index = HashFunction(value,m_bucketSize);
  if(!m_array[index].isEmpty() && m_array[index].contains(value))
  {
    cout << value << " is found at location " << index << endl;
  }
  else
  {
    cout << value << " is not found" << endl;
  }
}
