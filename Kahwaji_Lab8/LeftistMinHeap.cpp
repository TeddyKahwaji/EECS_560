#include "LeftistMinHeap.h"


void LeftistMinHeap::clear(LNode* root)
{
  if(root !=nullptr)
  {
    clear(root->getLeftChild());
    clear(root->getRightChild());
    delete root;
  }
}
LeftistMinHeap::~LeftistMinHeap()
{
  clear(m_root);
}

bool LeftistMinHeap::isEmpty()
{
  return m_root == nullptr;
}

void LeftistMinHeap::PreOrderPrint(LNode* temp)
{
  if(temp != nullptr)
  {
    cout << temp->getValue() << " ";
    PreOrderPrint(temp->getLeftChild());
    PreOrderPrint(temp->getRightChild());
  }
}

void LeftistMinHeap::InOrderPrint(LNode* temp)
{
  if(temp != nullptr)
  {
    InOrderPrint(temp->getLeftChild());
    cout << temp->getValue() << " ";
    InOrderPrint(temp->getRightChild());
  }
}
void LeftistMinHeap::PostOrderPrint(LNode* temp)
{
  if(temp != nullptr)
  {
    PostOrderPrint(temp->getLeftChild());
    PostOrderPrint(temp->getRightChild());
    cout << temp->getValue() << " ";
  }
}

void LeftistMinHeap::Inorder()
{
  LNode* temp = m_root;
  InOrderPrint(temp);
}
void LeftistMinHeap::Preorder()
{
  LNode* temp = m_root;
  PreOrderPrint(temp);
}


void LeftistMinHeap::PostOrder()
{
  LNode* temp = m_root;
  PostOrderPrint(temp);
}
void LeftistMinHeap::LevelOrder()
{
  LNode* temp = m_root;
  _PrintLevelOrderHelper(temp);
}
int LeftistMinHeap::FindMin()
{
    return m_root->getValue();
}
void LeftistMinHeap::DeleteMin()
{
  LNode* temp = m_root;
  m_root= Merge(m_root->getLeftChild(), m_root->getRightChild());
  delete temp;
}
LNode* LeftistMinHeap::BreakTrees(LNode* h1, LNode* h2)
{
  if(h1->getLeftChild() == nullptr)
  {
    h1->setLeftChild(h2);
  }
  else
  {
    h1->setRightChild(Merge(h1->getRightChild(),h2));
    if(getRank(h1->getLeftChild()) < getRank(h1->getRightChild()))
    {
       swapSubTrees(h1);
    }
    h1->setRank(getRank(h1->getRightChild()) +1);
  }
  return h1;
}
void LeftistMinHeap::setRoot(LNode* aVal)
{
  m_root = aVal;
}
LNode* LeftistMinHeap::getRoot()
{
  return m_root;
}
void LeftistMinHeap::MergeHeaps(LeftistMinHeap& newHeap)
{
  if(getRoot() == newHeap.getRoot())
  {
    return;
  }
  else
  {
    m_root = Merge(m_root, newHeap.getRoot());
    newHeap.setRoot(nullptr);
  }
}
LNode* LeftistMinHeap::Merge(LNode* h1, LNode* h2)
{
  if(h1 == nullptr)
  {
    return h2;
  }
  if(h2 == nullptr)
  {
    return h1;
  }
  if(h1->getValue() < h2->getValue())
  {
    return BreakTrees(h1,h2);
  }
  else
  {
    return BreakTrees(h2,h1);
  }
}

LNode* LeftistMinHeap::getFarRightNode(LNode* root)
{
  if(root->getRightChild() == nullptr)
  {
    return root;
  }
  else
  {
    return getFarRightNode(root->getRightChild());
  }
}

int LeftistMinHeap::getRank(LNode* ptr)
{
  if(ptr ==nullptr)
  {
    return 0;
  }
  else
  {
    return ptr->getRank();
  }
}
void LeftistMinHeap::swapSubTrees(LNode* h1)
{
  LNode* temp = h1->getLeftChild();
  h1->setLeftChild(h1->getRightChild());
  h1->setRightChild(temp);
}
void LeftistMinHeap::insert(int x)
{
  LNode* temp = new LNode(x);
  m_root= Merge(temp, m_root);
}

int LeftistMinHeap::getHeight(LNode* root)
{
  if(root == nullptr)
  {
    return 0;
  }
  else
  {
    int leftHeight = 1+ getHeight(root->getLeftChild());
    int rightHeight = 1+getHeight(root->getRightChild());
    int result = leftHeight >= rightHeight ? leftHeight : rightHeight;
    return result;
  }
}
int LeftistMinHeap::getHeight()
{
  if(m_root== nullptr)
  {
    return -1;
  }
  else
  {
    LNode* temp = m_root;
    return getHeight(temp);
  }
}
void LeftistMinHeap::_PrintLevelOrderHelper(LNode* root)
{
  int height = getHeight();
  for(int i =0; i<= height; i++)
  {
    _PrintLevel(root, i);
  }
}
void LeftistMinHeap::_PrintLevel(LNode* root, int level)
{
  if(root == nullptr)
  {
    return;
  }
  if(level ==1)
  {
    cout << root->getValue() << " ";
  }
  else if(level > 1)
  {
    _PrintLevel(root->getLeftChild(), level-1);
    _PrintLevel(root->getRightChild(), level-1);
  }
}
