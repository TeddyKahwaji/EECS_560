#include <iostream>
#include "DoublyLinkedList.h"


using namespace std;


DoublyLinkedList::~DoublyLinkedList()
{
  Clear();
}

bool DoublyLinkedList::isEmpty()
{
  return m_length ==0;
}



void DoublyLinkedList::insert(int entry)
{

  if(isEmpty())
  {
    m_front = new Node(entry);
  }
  else
  {
    if(m_back == nullptr)
    {

      m_back = new Node(entry);
      m_front->setNext(m_back);
      m_back->setPrev(m_front);
    }
    else
    {
      Node* temp = m_back;
      m_back->setNext(new Node(entry));
      m_back = m_back->getNext();
      m_back->setPrev(temp);
    }


  }
    m_length++;
}


int DoublyLinkedList::getSmallest()
{
  int smallest = m_front->getEntry();
  Node* temp = m_front;
  while(temp != nullptr)
  {
    if(temp->getEntry() <= smallest)
    {
      smallest = temp->getEntry();

    }
      temp =temp->getNext();
  }
  return smallest;
}

int DoublyLinkedList::getLargest()
{
  int largest = m_front->getEntry();
  Node* temp = m_front;
  while(temp != nullptr)
  {
    if(temp->getEntry() >= largest)
    {
      largest = temp->getEntry();
    }
    temp =temp->getNext();
  }
  return largest;
}


int DoublyLinkedList::getAverage()
{
  int average=0;
  Node* temp = m_front;
  while(temp != nullptr)
  {
    average = average + temp->getEntry();
        temp =temp->getNext();
  }

  return average / m_length;
}


void DoublyLinkedList::Print()
{
  Node*temp = m_front;

  while(temp != nullptr)
  {
    cout <<temp->getEntry() <<" ";
    temp = temp->getNext();
  }
  cout << endl;
}



void DoublyLinkedList::ReverseList()
{
  Node*temp = m_back;
  cout << "List: ";
  while(temp != nullptr)
  {
    cout << temp->getEntry() << " ";
    temp = temp->getPrev();
  }
    cout << endl;
}


void DoublyLinkedList::Delete(int entry)
{
  Node* temp = m_front;
  if(isEmpty())
  {
    cout << "Delete failed. List is empty" << endl;
    return;
  }
  if(m_front->getEntry() ==entry)
  {
    m_front = m_front->getNext();
    delete temp;
    m_length--;
      cout << "Delete was successful" << endl;
    return;

  }
  else
  {

    while(temp != nullptr)
    {
      if(temp->getEntry() == entry)
      {
        Node* temp2 = temp->getPrev();
        temp2->setNext(temp->getNext());
        delete temp;
        cout << "Delete was successful" << endl;
        return;
      }
      else
      {
        temp = temp->getNext();
      }
    }

    cout << "Delete failed. Number was not found in the list" << endl;
  }


  m_length--;
}



int DoublyLinkedList::getLength()
{
  return m_length;
}

void DoublyLinkedList::Clear()
{
  Node* temp = m_front;
  while(m_front !=nullptr)
  {
    m_front = m_front->getNext();
    delete temp;
    temp = m_front;
    m_length--;
  }
  m_back = nullptr;
  m_front = nullptr;

}



void DoublyLinkedList::SortMergedList()
{
  bool sorted = true;
  Node* temp1;
  Node* temp2 = nullptr;


  while(sorted)
  {
    sorted =false;
    temp1 = m_front;
    while(temp1->getNext() != temp2)
    {
      if(temp1->getEntry() > temp1->getNext()->getEntry())
      {
        int orgEntry = temp1->getEntry();
        temp1->setEntry(temp1->getNext()->getEntry());
        temp1->getNext()->setEntry(orgEntry);
        sorted = true;
      }
      temp1 = temp1->getNext();
    }
    temp2 = temp1;
  }



}
