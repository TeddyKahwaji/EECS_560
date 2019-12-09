#include "HashTableQuad.h"

HashTableQuad::HashTableQuad()
{

}
HashTableQuad::~HashTableQuad()
{
  // delete[] m_array;
}
HashTableQuad::HashTableQuad(int bucketSize)
{
  m_bucketSize = bucketSize;
  m_array = new Yelp[bucketSize];
}
Yelp* HashTableQuad::getArray()
{
  return m_array;
}
int HashTableQuad::computeStringLength(string word)
{
  int length =0;
  for(int i =0; i<50;i++)
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

int HashTableQuad::hashFunction(string name)
{
  int length = computeStringLength(name);
  int value =0;
  for(int i =0; i<length; i++)
  {
    value= value + int(name[i]);
  }
  int index = value % m_bucketSize;
  return index;
}

void HashTableQuad::insert(Yelp restaraunt)
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
    int count =0;
    int newIndex = index;
    while((count < m_bucketSize) && !m_array[newIndex].isEmpty())
    {
      newIndex = (index + ((count)*(count))) % m_bucketSize;
      if(!m_array[newIndex].isEmpty() && m_array[newIndex].getName() == restaraunt.getName())
      {
        cout << restaraunt.getName() << " is duplicated, can't be added to the hashtable. " << endl;
        return;
      }
      count++;
    }
    if(count >m_bucketSize)
    {
      cout << restaraunt.getName() << " is duplicated, can't be added to the hashtable. " << endl;
      return;
    }
    else
    {
      m_array[newIndex] = restaraunt;
      m_numOfKeys++;
      m_array[newIndex].setStatus(false);
      cout << restaraunt.getName() << " is inserted into the hashtable" << endl;
    }

  }

}

void HashTableQuad::Delete(string restaraunt)
{
  int index = hashFunction(restaraunt);
  if(!m_array[index].isEmpty() && m_array[index].getName() == restaraunt)
  {
    m_array[index].setName("");
    m_array[index].setRating(0);
    m_array[index].setPriceRange("");
    m_array[index].setStatus(true);
    m_numOfKeys--;
    cout << restaraunt << " is deleted from the hashtable" << endl;
  }
  else
  {
    int count =0;
    int newIndex;
    while((count < m_bucketSize) &&m_array[index].getName() !=restaraunt)
    {
      newIndex = (index + ((count)*(count))) % m_bucketSize;
      count++;
    }
    if(m_array[newIndex].getName() != restaraunt|| count > m_bucketSize)
    {
      cout << restaraunt << " is not found in the hashtable and therefore cannot be deleted" << endl;
      return;
    }
    else
    {
      m_array[newIndex].setName("");
      m_array[newIndex].setRating(0);
      m_array[newIndex].setPriceRange("");
      m_array[newIndex].setStatus(true);
      m_numOfKeys--;
      cout << restaraunt << " is deleted from the hashtable" << endl;
    }

  }
}

void HashTableQuad::FindByRating(int rating)
{
bool isFound = false;
  for (int i =0; i<m_bucketSize;i++)
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
void HashTableQuad::FindByName(string name)
{
bool isFound = false;
  for (int i =0; i<m_bucketSize;i++)
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

void HashTableQuad::SearchByPrice(string price)
{
bool isFound = false;
  for (int i =0; i<m_bucketSize;i++)
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


void HashTableQuad::Print()
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
