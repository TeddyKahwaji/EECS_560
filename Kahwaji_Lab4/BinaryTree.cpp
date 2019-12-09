#include "BinaryTree.h"

BinaryTree::~BinaryTree()
{
  clear();
}

void BinaryTree::_ClearHelper(BinaryNode* root)
{
  if(root !=nullptr)
  {
    _ClearHelper(root->getLeftChild());
    _ClearHelper(root->getRightChild());
    delete root;
  }
  m_root = nullptr;
}

void BinaryTree::clear()
{
  BinaryNode* temp = m_root;
  _ClearHelper(temp);
}

void BinaryTree::_PrintLeafHelper(BinaryNode* root)
{
  if(root== nullptr)
  {
    return;
  }
  if(root->getLeftChild()==nullptr && root->getRightChild() == nullptr)
  {
    cout << root->getValue() << " ";
    return;
  }
  if(root->getLeftChild() !=nullptr)
    _PrintLeafHelper(root->getLeftChild());
  if(root->getRightChild() !=nullptr)
    _PrintLeafHelper(root->getRightChild());
}

void BinaryTree::PrintLeaf()
{
  BinaryNode* temp = m_root;
  _PrintLeafHelper(temp);
}
void BinaryTree::AddItem(int x)
{
  if(m_root == nullptr)
  {
    m_root = new BinaryNode(x);
    return;
  }
  if(_Found(m_root, x))
  {
    cout << "Duplicate values are not allowed!" << endl;
    return;
  }
  Queue<BinaryNode*> TreeHolder;
  BinaryNode* temp = m_root;
  TreeHolder.insert(temp);
  while(!TreeHolder.isEmpty())
  {
    BinaryNode* temp2 = TreeHolder.peek();
    TreeHolder.Dequeue();
    if(temp2->getLeftChild() == nullptr)
    {
      temp2->setLeftChild(new BinaryNode(x));
      break;
    }
    else
    {
      TreeHolder.insert(temp2->getLeftChild());
    }

    if(temp2->getRightChild() == nullptr)
    {
      temp2->setRightChild(new BinaryNode(x));
      break;
    }
    else
    {
      TreeHolder.insert(temp2->getRightChild());
    }
  }
  cout << "Value inserted successfully!" << endl;

}
bool BinaryTree::_isFullHelper(BinaryNode* temp)
{
  if(temp == nullptr)
  {
    return true;
  }
  if(temp->getLeftChild() == nullptr && temp->getRightChild() == nullptr)
  {
    return true;
  }
  if(temp->getLeftChild() !=nullptr && temp->getRightChild() != nullptr)
  {
    return (_isFullHelper(temp->getLeftChild()) && _isFullHelper(temp->getRightChild()));
  }
  return false;
}
bool BinaryTree::isFull()
{
  BinaryNode* temp = m_root;
  return (_isFullHelper(temp));
}
void BinaryTree::_addItem(BinaryNode* temp, int x)
{

  if(temp ->getLeftChild() == nullptr)
  {
    temp ->setLeftChild(new BinaryNode(x));
    return;
  }
  else if(temp->getRightChild() == nullptr)
  {
    temp->setRightChild(new BinaryNode(x));
    return;
  }
  else
  {
    _addItem(temp->getLeftChild(),x);


  }
}

int BinaryTree::_getHeightHelper(BinaryNode* temp)
{
  if(temp == nullptr)
  {
    return -1;
  }
  else
  {
    int leftHeight = 1+ _getHeightHelper(temp->getLeftChild());
    int rightHeight = 1 + _getHeightHelper(temp->getRightChild());
    int result = leftHeight >= rightHeight ? leftHeight : rightHeight;
    return result;
  }

}

int BinaryTree::getHeight()
{
  if(m_root == nullptr)
  {
    return -1;
  }
  else
  {
    BinaryNode* temp = m_root;
    return _getHeightHelper(temp);
  }
}

void BinaryTree::_PrintPreOrderHelper(BinaryNode* aRoot)
{
  if(aRoot != nullptr)
  {
      cout << aRoot->getValue() << " ";
    _PrintPreOrderHelper(aRoot->getLeftChild());
    _PrintPreOrderHelper(aRoot->getRightChild());
  }
}
void BinaryTree::_PrintPostOrderHelper(BinaryNode* aRoot)
{
  if(aRoot != nullptr)
  {
    _PrintPostOrderHelper(aRoot->getLeftChild());
    _PrintPostOrderHelper(aRoot->getRightChild());
      cout << aRoot->getValue() << " ";
  }
}

void BinaryTree::_PrintInOrderHelper(BinaryNode* aRoot)
{
  if(aRoot != nullptr)
  {
    _PrintInOrderHelper(aRoot->getLeftChild());
      cout << aRoot->getValue() << " ";
    _PrintInOrderHelper(aRoot->getRightChild());

  }
}


void BinaryTree::PrintPreOrder()
{
  BinaryNode* temp = m_root;
  _PrintPreOrderHelper(temp);
}

void BinaryTree::PrintPostOrder()
{
  BinaryNode* temp = m_root;
  _PrintPostOrderHelper(temp);
}
void BinaryTree::PrintLevelOrder()
{
  BinaryNode* temp = m_root;
  _PrintLevelOrderHelper(temp);
}

void BinaryTree::_PrintLevelOrderHelper(BinaryNode* aRoot)
{
  int height = getHeight();
  for(int i =0; i<= height; i++)
  {
    _PrintLevel(aRoot,i);
  }
}
void BinaryTree::_PrintLevel(BinaryNode* root, int level)
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

void BinaryTree::PrintInOrder()
{
  BinaryNode* temp = m_root;
  _PrintInOrderHelper(temp);
}
bool BinaryTree::_Found(BinaryNode* temp, int x)
{
  if(temp == nullptr)
  {
    return false;
  }
  if(temp->getValue() == x)
  {
    return true;
  }

  else
  {
    bool leftSub = _Found(temp->getLeftChild(),x);
    bool rightSub =_Found(temp->getRightChild(),x);
    return leftSub || rightSub;
  }
}

BinaryNode* BinaryTree::_isLeafHelper(BinaryNode* temp,int x)
{
  if(temp == nullptr)
  {
    return nullptr;
  }
  if(temp->getValue() ==x)
  {
    return temp;
  }
    BinaryNode* temp2 = _isLeafHelper(temp->getLeftChild(),x);
    BinaryNode* temp3 =_isLeafHelper(temp->getRightChild(),x);
    if(temp2 !=nullptr)
    {
      return temp2;
    }
    else
    {
      return temp3;
    }
}
bool BinaryTree::isLeaf(int x)
{
  BinaryNode* temp = m_root;
  if(!_Found(temp,x))
  {
    return false;
  }
  BinaryNode* possibleLeaf = _isLeafHelper(temp,x);
  if(possibleLeaf == nullptr)
  {
    return false;
  }
  else if(possibleLeaf->getLeftChild() == nullptr && possibleLeaf->getRightChild() == nullptr)
  {
    return true;
  }
}

void BinaryTree::DeletePath(BinaryNode* initialRoot, BinaryNode* destination)
{
  Queue<BinaryNode*> queue;
  queue.insert(initialRoot);
  BinaryNode* temp;
  while(!queue.isEmpty())
  {
    temp = queue.peek();
    queue.Dequeue();
    if(temp == destination)
    {
      temp = nullptr;
      delete destination;
      return;
    }
    if(temp->getRightChild() !=nullptr)
    {
      if(temp->getRightChild() == destination)
      {
        temp->setRightChild(nullptr);
        delete destination;
        return;
      }
      else
      {
        queue.insert(temp->getRightChild());
      }
    }
    if(temp->getLeftChild() !=nullptr)
    {
      if(temp->getLeftChild() == destination)
      {
        temp->setLeftChild(nullptr);
        delete destination;
        return;
      }
      else
      {
        queue.insert(temp->getLeftChild());
      }
    }
  }
}

void BinaryTree::Delete()
{
  if(m_root == nullptr)
  {
    cout << "You cannot delete the root node!" << endl;
    return;
  }
  else if(m_root->getLeftChild() == nullptr && m_root->getRightChild() == nullptr)
  {
    delete m_root;
    m_root = nullptr;
    cout << "The last value is " << m_root->getValue() << ", and it has been deleted." << endl;
    return;
  }
  else
  {
    Queue<BinaryNode*> queue;
    queue.insert(m_root);
    BinaryNode* temp;
    while(!queue.isEmpty())
    {
      temp = queue.peek();
      queue.Dequeue();
      if(temp->getLeftChild() !=nullptr)
      {
        queue.insert(temp->getLeftChild());
      }
      if(temp->getRightChild() !=nullptr)
      {
        queue.insert(temp->getRightChild());
      }
    }
    DeletePath(m_root, temp);
    cout << "The last value is " << temp->getValue() << ", and it has been deleted. " << endl;
    return;
  }
}
