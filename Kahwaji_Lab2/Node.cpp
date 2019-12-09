


template <typename T>
Node<T>::Node()
{
  m_next = nullptr;
}

template <typename T>
Node<T>::Node(T anEntry)
{
  m_next = nullptr;
  m_entry = anEntry;
}


template <typename T>
void Node<T>::setNext(Node<T>* next)
{
  m_next = next;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
  return m_next;
}

template <typename T>
void Node<T>::setEntry(T anEntry)
{
  m_entry = anEntry;
}

template <typename T>
T Node<T>::getEntry()
{
  return m_entry;
}
