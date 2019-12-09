#ifndef NODE_H
#define NODE_H





class Node
{
public:
  Node(int entry);
  Node();
  void setNext(Node* next);
  void setPrev(Node* prev);
  Node* getNext();
  Node* getPrev();
  int getEntry();
  void setEntry(int entry);
private:
  Node* m_next;
  Node* m_prev;
  int m_entry;

};

#endif
