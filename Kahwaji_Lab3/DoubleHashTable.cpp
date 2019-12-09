#include "DoubleHashTable.h"

DoubleHashTable::DoubleHashTable(){}
DoubleHashTable::DoubleHashTable(int bucketSize)
{
  m_bucketSize = bucketSize;
  rValue = 29;
  m_array = new Yelp[m_bucketSize];
}

DoubleHashTable::~DoubleHashTable()
{
  //delete[] m_array;
}

int DoubleHashTable::computeStringLength(string word)
{
  int length =0;
  for(int i =0; i<30;i++)
  {
    if(word[i] == '\0')
    {
      return length;
      break;
    }
    else
    {
      length++;
    }
  }
  return length;
}
Yelp* DoubleHashTable::getArray()
{
  return m_array;
}
int DoubleHashTable::hashFunction(string name)
{
  int length = computeStringLength(name);
  int asciSum =0;
  for(int i =0; i<length; i++)
  {
    asciSum += (int)name[i];
  }
  int index = asciSum % m_bucketSize;
  return index;
}

int DoubleHashTable::DoubleHashFunction(string word)
{
  int value =0;
  int length =0;
  for(int i =0; i<length; i++)
  {
    value+= (int)word[i];
  }
  int index = rValue - (value % rValue);
  return index;
}

void DoubleHashTable::insert(Yelp restaraunt)
{
  int index = hashFunction(restaraunt.getName());
  if(m_array[index].isEmpty())
  {
    m_array[index] = restaraunt;
    m_array[index].setStatus(false);
    cout << restaraunt.getName() << " is inserted into the hashtable" << endl;
    m_numOfKeys++;
    return;
  }
  else
  {
    int newIndex =index;
    int HPlus = DoubleHashFunction(restaraunt.getName());
    int count =0;

    while(count <= m_bucketSize-1 && !m_array[newIndex].isEmpty())
    {
      newIndex = (index + (count * HPlus)) % m_bucketSize;
      if(m_array[newIndex].getName() == restaraunt.getName())
      {
        cout << restaraunt.getName() << " is duplicated, can't be added to the hashtable" << endl;
        return;
      }
      count ++;
    }
    if(count > m_bucketSize)
    {
      cout << restaraunt.getName() << " is duplicated, can't be added to hashtable" << endl;
      return;
    }
    else
    {
      restaraunt.setStatus(false);
      m_array[newIndex] = restaraunt;
      m_numOfKeys++;
      cout << restaraunt.getName() << " is inserted into the hashtable" << endl;
    }

  }
}

void DoubleHashTable::Delete(string restaraunt)
{
  int index = hashFunction(restaraunt);

  if(!m_array[index].isEmpty() && m_array[index].getName() == restaraunt)
  {
    m_array[index].setName("");
    m_array[index].setRating(0);
    m_array[index].setPriceRange("");
    m_array[index].setStatus(true);
    m_numOfKeys--;
    cout << restaraunt << " is deleted from the hash table." << endl;
  }
  else
  {
    int newIndex =index;
    int HPlus = DoubleHashFunction(restaraunt);
    int count =0;
    while(count < m_bucketSize)
    {
      newIndex = (index + (count * HPlus)) % m_bucketSize;
      if(m_array[newIndex].getName() ==restaraunt )
      {
        m_array[newIndex].setName("");
        m_array[newIndex].setRating(0);
        m_array[newIndex].setPriceRange("");
        m_array[newIndex].setStatus(true);
        m_numOfKeys--;
        cout << restaraunt << " is deleted from the hashtable." << endl;
        return;
      }
      count ++;
    }
    if(m_array[newIndex].getName() ==restaraunt )
    {
      m_array[newIndex].setName("");
      m_array[newIndex].setRating(0);
      m_array[newIndex].setPriceRange("");
      m_array[newIndex].setStatus(true);
      m_numOfKeys--;
      cout << restaraunt << " is deleted from the hashtable." << endl;
      return;
    }
    else
    {

      cout << restaraunt << " is not found in the hashtable and therefore cannot be deleted" << endl;
      return;
    }

  }
}

void DoubleHashTable::FindByRating(int rating)
{
  bool isFound = false;
  for(int i =0; i<m_bucketSize; i++)
  {
    if(!m_array[i].isEmpty() && m_array[i].getRating() == rating)
    {
      cout << m_array[i].getName() << " ";
      isFound = true;
    }
  }
  if(!isFound)
  {
    cout << rating << " star rated restaraunts are not found in the hashtable." << endl;
  }
}

void DoubleHashTable::FindByName(string name)
{
  bool isFound = false;
  for(int i =0; i<m_bucketSize; i++)
  {
    if(!m_array[i].isEmpty() && m_array[i].getName() == name)
    {
      cout << m_array[i].getName() << " " << m_array[i].getRating() << " " << m_array[i].getPriceRange();
      isFound = true;
    }
  }
  if(!isFound)
  {
    cout << "No restaraunts are found with the given name " << endl;
  }
}

void DoubleHashTable::SearchByPrice(string price)
{
  bool isFound = false;
  for(int i =0; i<m_bucketSize; i++)
  {
    if(!m_array[i].isEmpty() && m_array[i].getPriceRange() == price)
    {
      cout << m_array[i].getName() << " ";
      isFound = true;
    }
  }
  if(!isFound)
  {
    cout << "No restaraunts are found with the given price range" <<endl;
  }
}

void DoubleHashTable::Print()
{
  for (int i =0; i<m_bucketSize;i++)
  {
    if(!m_array[i].isEmpty())
    {
      cout << i << ": " << m_array[i].getName() << " " << m_array[i].getRating() <<  " " << m_array[i].getPriceRange() << endl;
    }
    else
    {
      cout << i << ": " <<endl;
    }
  }
}
