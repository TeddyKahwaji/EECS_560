
template <typename T>
bool Queue<T>::isEmpty()
{
  bool result = m_front == nullptr;
  return result;
}

template <typename T>
T Queue<T>::peek()
{
  if(m_front !=nullptr)
  {
    return m_front->getEntry();
  }
}

template <typename T>
T Queue<T>::Dequeue()
{
  if(m_front !=nullptr)
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
  if(m_front == nullptr)
  {
    m_front = new Node<T>(value);
  }
  else if(m_back == nullptr)
  {
    m_back = new Node<T>(value);
    m_front->setNext(m_back);
  }
  else
  {
    m_back->setNext(new Node<T>(value));
    m_back = m_back->getNext();
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
