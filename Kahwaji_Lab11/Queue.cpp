template <typename T >
bool Queue<T>::contains(T value)
{
  Node<T>* temp = m_front;
  while(temp !=nullptr)
  {
    if(temp->getEntry() == value)
    {
      return true;
    }
    temp = temp->getNext();
  }
  return false;
}

template <typename T>
Node<T>* Queue<T>::getFront()
{
  return m_front;
}

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
    m_length--;
    T value = m_front->getEntry();
    Node<T>* temp = m_front;
    m_front = m_front->getNext();
    delete temp;
    return value;
}

template <typename T>
T Queue<T>::getMin()
{
  Node<T>* temp = m_front;
  T min = temp->getEntry();
  while(temp != nullptr)
  {
    if(temp->getEntry() < min)
    {
      min = temp->getEntry();
    }
    temp = temp->getNext();
  }
  return min;
}

template <typename T>
void Queue<T>::print(void op(T obj))
{
  Node<T>* temp = m_front;
  while(temp!= nullptr)
  {
    op(temp->getEntry());
    temp = temp->getNext();
  }
  cout << endl;
}

template <typename T>
int Queue<T>::getLength()
{
  return m_length;
}

template <typename T>
void Queue<T>::insert(T value)
{
  m_length++;
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
void Queue<T>::clear()
{
  Node<T>* temp = m_front;
  while(m_front !=nullptr)
  {
    m_front = m_front->getNext();
    delete temp;
    temp = m_front;
  }
  m_length =0;
}

template <typename T>
Queue<T>::~Queue()
{
  clear();
}
