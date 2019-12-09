
template <typename T>
bool Queue<T>::isEmpty()
{
  bool result = m_front == nullptr;
  return result;
}

template <typename T>
T Queue<T>::peek()
{
    return m_front->getEntry();
}

template <typename T>
T Queue<T>::Dequeue()
{
  if(!isEmpty())
  {
    T value = m_front->getEntry();
    Node<T>* temp = m_front;
    m_front = m_front->getNext();
    delete temp;
    return value;
  }
}


template <typename T>
void Queue<T>::insert(T value)
{
  Node<T>* newNodePtr = new Node<T>(value);
  if (isEmpty()) {
      m_front = newNodePtr;
      m_back = m_front;
  }
  else {
      m_back -> setNext(newNodePtr);
      m_back = newNodePtr;
  }
}

template <typename T>
Queue<T>::~Queue()
{
  Node<T>* temp = m_front;
  while(m_front !=nullptr)
  {
    m_front = m_front->getNext();
    delete temp;
    temp = m_front;
  }
}
