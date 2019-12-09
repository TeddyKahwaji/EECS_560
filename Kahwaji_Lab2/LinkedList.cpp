template <typename T>
bool LinkedList<T>::isEmpty()
{
  return m_length ==0;
}

template <typename T>
void LinkedList<T>::insert(T entry)
{
  if(isEmpty())
  {
    m_front = new Node<T>(entry);
    m_length++;
  }
  else
  {
    m_length++;
    Node<T>* temp = new Node<T>(entry);
    temp->setNext(m_front);
    m_front = temp;

  }
}

template <typename T>
void LinkedList<T>::Print()
{
  Node<T>* temp = m_front;
  while(temp !=nullptr)
  {
    cout << temp->getEntry() << "-> ";
    temp = temp->getNext();
  }
}

template <typename T>
int LinkedList<T>::getLength()
{
  return m_length;
}

template <typename T>
Node<T>* LinkedList<T>::getFront()
{
  return m_front;
}
template <typename T>
LinkedList<T>::LinkedList()
{

}
template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}



template <typename T>
void LinkedList<T>::clear()
{
  Node<T>* temp = m_front;
  m_length =0;
  while(m_front !=nullptr)
  {
    m_front = m_front->getNext();
    delete temp;
    temp = m_front;
  }

}



template <typename T>
bool LinkedList<T>::contains(T entry)
{
  Node<T>* temp = m_front;
  while(temp != nullptr)
  {
    if(temp->getEntry() == entry)
    {
      return true;
    }
    temp = temp->getNext();
  }
  return false;
}

template <typename T>
void LinkedList<T>::Remove(T anEntry)
{
  Node<T>* walker = m_front;
  Node<T>* runner = m_front;
  if(walker->getEntry() == anEntry)
  {
    m_front = m_front->getNext();
    delete walker;
    m_length--;
    return;
  }

  while(walker !=nullptr)
  {
    runner = runner->getNext();
    if(runner->getEntry() == anEntry)
    {
      Node<T>* temp = runner;
      walker->setNext(runner->getNext());
      delete temp;
      m_length--;
      return;
    }
    walker = walker->getNext();
  }
}
