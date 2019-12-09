#ifndef BINARY_NODE_H
#define BINARY_NODE_H



class BinaryNode
{
public:
  BinaryNode();
  BinaryNode(int value);
  void setLeftChild(BinaryNode* left);
  void setRightChild(BinaryNode* right);
  BinaryNode* getLeftChild();
  BinaryNode* getRightChild();
  void setValue(int value);
  int getValue();
private:
  BinaryNode* m_leftChildPtr;
  BinaryNode* m_rightChildPtr;
  int m_value;


};
#endif
