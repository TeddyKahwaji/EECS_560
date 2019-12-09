#ifndef B_NODE_H
#define B_NODE_H



class BNode
{
public:
  BNode(int m_value);
  BNode();
  void setOrder(int degree);
  int getOrder();
  void setLSibling(BNode* m_child);
  BNode* getLSibling();
  void setRSibling(BNode* m_child);
  BNode* getRSibling();
  void setChild(BNode* child);
  BNode* getChild();
  void setKey(int key);
  int getKey();
  void setParent(BNode* parent);
  BNode* getParent();
private:
  int m_value;
  int m_order;
  BNode* m_parent;
  BNode* m_lsibling;
  BNode* m_rsibling;
  BNode* m_child;
};
#endif
