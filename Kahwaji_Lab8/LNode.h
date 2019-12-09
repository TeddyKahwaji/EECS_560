#ifndef L_NODE_H
#define L_NODE_H



class LNode
{
public:
LNode(int value);
void setLeftChild(LNode* ptr);
void setRightChild(LNode* ptr);
void setRank(int rank);
void setEntry(int entry);

LNode* getLeftChild();
LNode* getRightChild();
int getRank();
int getValue();

private:
LNode* m_lchild =nullptr;
LNode* m_rchild = nullptr;
int m_rank=0;
int m_entry;
};
#endif
