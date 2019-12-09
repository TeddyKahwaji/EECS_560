#ifndef BINARY_NODE_H
#define BINARY_NODE_H



class BinaryNode
{
public:
  BinaryNode();
  BinaryNode(char value);
  void setLeftChild(BinaryNode* left);
  void setRightChild(BinaryNode* right);
  BinaryNode* getLeftChild();
  BinaryNode* getRightChild();
  void setValue(char value);
  char getValue();
private:
  BinaryNode* m_leftChildPtr;
  BinaryNode* m_rightChildPtr;
  char m_value;


};
#endif
