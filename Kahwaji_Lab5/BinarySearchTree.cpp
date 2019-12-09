#include "BinarySearchTree.h"


void BinarySearchTree::_clear(BinaryNode* temp)
{
  if(temp != nullptr)
  {
    _clear(temp->getLeftChild());
    _clear(temp->getRightChild());
    delete temp;
  }
  m_root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
  BinaryNode* temp = m_root;
  _clear(temp);
}

BinaryNode* BinarySearchTree::insertHelper(BinaryNode* root, char c)
{

  if(root == nullptr)
  {
   root = new BinaryNode(c);
  }
  else if((int)c < (int)root->getValue())
  {

    root->setLeftChild(insertHelper(root->getLeftChild(), c));
  }
  else if ((int)c >= (int)root->getValue())
  {

    root->setRightChild(insertHelper(root->getRightChild(), c));
  }
  return root;
}

void BinarySearchTree::Insert(char c)
{
    m_root = insertHelper(m_root,c);
}

bool BinarySearchTree::containsHelper(BinaryNode* root, char c)
{
  if(root == nullptr)
  {
    return false;
  }
  if(root->getValue() == c)
  {
    return true;
  }
  if((int)c< (int)root->getValue())
  {
    return containsHelper(root->getLeftChild(), c);
  }
  else if ((int)c > (int)root->getValue())
  {
    return containsHelper(root->getRightChild(), c);
  }
}


bool BinarySearchTree::contains(char c)
{
  BinaryNode* temp = m_root;
  return containsHelper(temp,c);
}

BinaryNode* BinarySearchTree::getMinNode(BinaryNode* root)
{
  if(root == nullptr)
  {
    return nullptr;
  }
  else if(root ->getLeftChild() != nullptr)
  {
    return getMinNode(root->getLeftChild());
  }
  else
  {
    return root;
  }
}

BinaryNode* BinarySearchTree::DeleteHelper(BinaryNode* root, char aKey)
{

  if (root == nullptr)
  {
      return root;
  }
  if ((int)aKey < (int)root->getValue())
  {
    root->setLeftChild(DeleteHelper(root->getLeftChild(),aKey));
  }
  else if ((int)aKey > (int)root->getValue())
  {
  root->setRightChild(DeleteHelper(root->getRightChild(),aKey));
  }
  else
  {
    if(root->getLeftChild() == nullptr)
    {
      BinaryNode* temp = root->getRightChild();
      delete root;
      return temp;
    }
    else if(root->getRightChild() == nullptr)
    {
      BinaryNode* temp = root->getLeftChild();
      delete root;
      return temp;
    }
    BinaryNode* temp = getMinNode(root->getRightChild());
    root->setValue(temp->getValue());
    root->setRightChild(DeleteHelper(root->getRightChild(),temp->getValue()));

  }
  return root;
}

void BinarySearchTree::Delete(char c)
{

    m_root = DeleteHelper(m_root,c);
}





BinaryNode* BinarySearchTree::isLeafHelper(BinaryNode* root, char c)
{
  if(root == nullptr)
  {
    return nullptr;
  }
  if((int)root->getValue() == (int)c)
  {
    return root;
  }
  if((int)c < (int)root->getValue())
  {
    return isLeafHelper(root->getLeftChild(), c);
  }
  else if ((int)c> (int)root->getValue())
  {
    return isLeafHelper(root->getRightChild(), c);
  }
  return root;
}

bool BinarySearchTree::isLeaf(char c)
{
  BinaryNode* temp = m_root;
  BinaryNode* finder = isLeafHelper(temp, c);
  if(finder == nullptr)
  {
    return false;
  }
  else if(finder->getLeftChild()== nullptr && finder->getRightChild() == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}


void BinarySearchTree::PrintLeafNodes()
{
  BinaryNode* temp = m_root;
  PrintLeafsHelper(temp);
}

BinaryNode* BinarySearchTree::PrintLeafsHelper(BinaryNode* root)
{
  if(root == nullptr)
  {
    //
  }
  if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr)
  {
    cout << root->getValue() << " ";
  }
  if(root->getLeftChild() != nullptr)
  {
    PrintLeafsHelper(root->getLeftChild());
  }
  if(root->getRightChild() !=nullptr)
  {
    PrintLeafsHelper(root->getRightChild());
  }
}


int BinarySearchTree::getHeightHelper(BinaryNode* temp)
{
  if(temp == nullptr)
  {
    return -1;
  }

  else
  {
    int leftSubTree = 1+getHeightHelper(temp->getLeftChild());
    int rightSubTree = 1+getHeightHelper(temp->getRightChild());
    int result = leftSubTree >= rightSubTree ? leftSubTree : rightSubTree;
    return result;
  }
}
int BinarySearchTree::getHeight()
{
  if(m_root == nullptr)
    return -1;

  BinaryNode* temp = m_root;
  return getHeightHelper(temp);
}

void BinarySearchTree::_PrintPreOrderHelper(BinaryNode* aRoot)
{
  if(aRoot != nullptr)
  {
      cout << aRoot->getValue() << " ";
    _PrintPreOrderHelper(aRoot->getLeftChild());
    _PrintPreOrderHelper(aRoot->getRightChild());
  }
}
void BinarySearchTree::_PrintPostOrderHelper(BinaryNode* aRoot)
{
  if(aRoot != nullptr)
  {
    _PrintPostOrderHelper(aRoot->getLeftChild());
    _PrintPostOrderHelper(aRoot->getRightChild());
      cout << aRoot->getValue() << " ";
  }
}

void BinarySearchTree::_PrintInOrderHelper(BinaryNode* aRoot)
{
  if(aRoot != nullptr)
  {
    _PrintInOrderHelper(aRoot->getLeftChild());
      cout << aRoot->getValue() << " ";
    _PrintInOrderHelper(aRoot->getRightChild());

  }
}
void BinarySearchTree::PrintInOrder()
{
  BinaryNode* temp = m_root;
  _PrintInOrderHelper(temp);
}

void BinarySearchTree::PrintPreOrder()
{
  BinaryNode* temp = m_root;
  _PrintPreOrderHelper(temp);
}

void BinarySearchTree::PrintPostOrder()
{
  BinaryNode* temp = m_root;
  _PrintPostOrderHelper(temp);
}

void BinarySearchTree::PrintLevelOrder()
{
  BinaryNode* temp = m_root;
  _PrintLevelOrderHelper(temp);
}

void BinarySearchTree::_PrintLevelOrderHelper(BinaryNode* aRoot)
{
  int height = getHeight();
  for(int i =0; i<= height+1; i++)
  {
    _PrintLevel(aRoot,i);
  }
}
void BinarySearchTree::_PrintLevel(BinaryNode* root, int level)
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
