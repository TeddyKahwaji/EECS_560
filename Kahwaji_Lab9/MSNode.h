#ifndef MS_NODE_H
#define MS_NODE_H



class MSNode
{
public:
  MSNode();
MSNode(int value);
void setLeftChild(MSNode* ptr);
void setRightChild(MSNode* ptr);

void setEntry(int entry);

MSNode* getLeftChild();
MSNode* getRightChild();

int getValue();

private:
MSNode* m_lchild =nullptr;
MSNode* m_rchild = nullptr;

int m_entry;
};
#endif
