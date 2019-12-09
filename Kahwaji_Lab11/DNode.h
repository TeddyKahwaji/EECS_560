#ifndef DNODE_H
#define DNODE_H

class DNode
{
public:
  DNode(int value);
  void setParent(DNode* aParent);
  DNode* getParent();
  void setKey(int aKey);
  int getKey();
  void setRank(int aRank);
  int getRank();
private:
  int m_key;
  int m_rank=0;
  DNode* m_parent = this;
};
#endif
