#include "MinSkewHeap.h"


void MinSkewHeap::clear(MSNode* root)
{
  if(root !=nullptr)
  {
    clear(root->getLeftChild());
    clear(root->getRightChild());
    delete root;
  }
}
MinSkewHeap::~MinSkewHeap()
{
  clear(m_root);
}

bool MinSkewHeap::isEmpty()
{
  return m_root == nullptr;
}

void MinSkewHeap::PreOrderPrint(MSNode* temp)
{
  if(temp != nullptr)
  {
    cout << temp->getValue() << " ";
    PreOrderPrint(temp->getLeftChild());
    PreOrderPrint(temp->getRightChild());
  }
}

void MinSkewHeap::InOrderPrint(MSNode* temp)
{
  if(temp != nullptr)
  {
    InOrderPrint(temp->getLeftChild());
    cout << temp->getValue() << " ";
    InOrderPrint(temp->getRightChild());
  }
}
void MinSkewHeap::PostOrderPrint(MSNode* temp)
{
  if(temp != nullptr)
  {
    PostOrderPrint(temp->getLeftChild());
    PostOrderPrint(temp->getRightChild());
    cout << temp->getValue() << " ";
  }
}

void MinSkewHeap::Inorder()
{
  MSNode* temp = m_root;
  InOrderPrint(temp);
}
void MinSkewHeap::Preorder()
{
  MSNode* temp = m_root;
  PreOrderPrint(temp);
}


void MinSkewHeap::PostOrder()
{
  MSNode* temp = m_root;
  PostOrderPrint(temp);
}
void MinSkewHeap::LevelOrder()
{
  MSNode* temp = m_root;
  _PrintLevelOrderHelper(temp);
}

bool MinSkewHeap::FindHelper(MSNode* root, int value)
{
  if(root == nullptr)
  {
    return false;
  }
  if(root->getValue() == value)
  {
    return true;
  }
  bool lookLeft = FindHelper(root->getLeftChild(), value);
  bool lookRight = FindHelper(root->getRightChild(), value);
  return lookLeft || lookRight;
}
bool MinSkewHeap::Find(int value)
{
  MSNode* temp = m_root;
  return FindHelper(temp, value);
}
MSNode* MinSkewHeap::FindNode(MSNode* root, int value)
{

  if(root == nullptr)
  {
    return nullptr;
  }
  else if(root->getValue() == value)
  {
      return root;
  }

  MSNode* temp1 =  FindNode(root->getLeftChild(), value);
  MSNode* temp2 = FindNode(root->getRightChild(), value);

  if(temp1!= nullptr && temp1->getValue() == value)
  {

    return temp1;
  }
  else if (temp2 !=nullptr && temp2->getValue() == value)
  {

    return temp2;
  }


}

MSNode* MinSkewHeap::findParent(MSNode* root, MSNode* target)
{
  if(root == nullptr)
  {
      return nullptr;
  }
  else if (root->getLeftChild() == target || root->getRightChild() == target)
  {
    m_left = root->getLeftChild() == target;
    m_right = root->getRightChild() == target;
    return root;
  }
  MSNode* left = findParent(root->getLeftChild(), target);
  MSNode* right = findParent(root->getRightChild(), target);
  return left!= nullptr ? left : right;

}
void MinSkewHeap::DeleteValue(int x)
{
  m_size--;
  if(m_root->getValue() == x)
  {
    MSNode* temp = m_root;
    m_root = Merge(m_root->getLeftChild(), m_root->getRightChild());
    delete temp;
  }
  else
  {

    MSNode* target = FindNode(m_root,x);
    MSNode* temp = target;

    MSNode* parent = findParent(m_root, target);

    target = Merge(target->getLeftChild(), target->getRightChild());
    if(m_left)
    {
      parent->setLeftChild(target);
    }
    else
    {
      parent->setRightChild(target);
    }

    delete temp;
  }


  m_left = false;
  m_right = false;

}
MSNode* MinSkewHeap::BreakTrees(MSNode* h1, MSNode* h2)
{
  if(h1->getLeftChild() == nullptr)
  {
    h1->setLeftChild(h2);
  }
  else
  {
    h1->setRightChild(Merge(h1->getRightChild(),h2));
   swapSubTrees(h1);
  }
  return h1;
}
void MinSkewHeap::setRoot(MSNode* aVal)
{
  m_root = aVal;
}
MSNode* MinSkewHeap::getRoot()
{
  return m_root;
}
void MinSkewHeap::MergeHeaps(MinSkewHeap& newHeap)
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
MSNode* MinSkewHeap::Merge(MSNode* h1, MSNode* h2)
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

MSNode* MinSkewHeap::getFarRightNode(MSNode* root)
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


void MinSkewHeap::swapSubTrees(MSNode* h1)
{
  MSNode* temp = h1->getLeftChild();
  h1->setLeftChild(h1->getRightChild());
  h1->setRightChild(temp);
}
void MinSkewHeap::insert(int x)
{
  m_size++;
  MSNode* temp = new MSNode(x);
  m_root= Merge(temp, m_root);
}

int MinSkewHeap::getHeight(MSNode* root)
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
int MinSkewHeap::getHeight()
{
  if(m_root== nullptr)
  {
    return -1;
  }
  else
  {
    MSNode* temp = m_root;
    return getHeight(temp);
  }
}
void MinSkewHeap::_PrintLevelOrderHelper(MSNode* root)
{
  int height = getHeight();
  for(int i =0; i<= height; i++)
  {
    _PrintLevel(root, i);
  }
}
void MinSkewHeap::_PrintLevel(MSNode* root, int level)
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
