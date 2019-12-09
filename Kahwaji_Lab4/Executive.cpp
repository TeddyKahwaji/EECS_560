#include "Executive.h"



Executive::Executive(string fileName)
{
  inFile.open(fileName);
  int value;
  while(inFile >> value)
  {
    m_tree.AddItem(value);
  }
  PrintMenu();
}
void Executive::isFull()
{
  string result = m_tree.isFull() ? "True" : "False";
  cout << "Output: " << result << endl;
}
void Executive::AddItem()
{
  int value;
  cout << "Please enter the value which you want to enter into the tree." << endl;
  cin >> value;
  cout << "Output: ";
  m_tree.AddItem(value);
}

void Executive::Delete()
{
  m_tree.Delete();
}
void Executive::Leaf()
{
  int value;
  cout << "Please enter the value which you want to test as a leaf node." << endl;
  cin >> value;
  if(m_tree.isLeaf(value))
  {
    cout << "Output: ";
    cout << "The node with " << value << " is a leaf node." << endl;
  }
  else
  {
    cout << "Output: ";
    cout << "The node with " << value << " is not a leaf node." << endl;
  }
}

void Executive::Height()
{
  cout << "Output: ";
  cout << "The height of the tree is " << m_tree.getHeight() << endl;
}
void Executive::PreOrder()
{
  cout << "Output: " << "Printing the tree in Pre-Order- ";
  m_tree.PrintPreOrder();
  cout << endl;
}
void Executive::PostOrder()
{
  cout << "Output: " << "Printing the tree in Post-Order ";
  m_tree.PrintPostOrder();
  cout << endl;
}
void Executive::InOrder()
{
  cout << "Output: " << "Printing the tree in In-Order ";
  m_tree.PrintInOrder();
  cout << endl;
}
void Executive::LevelOrder()
{
  cout << "Output: " << "Printing the tree in Level-Order ";
  m_tree.PrintLevelOrder();
  cout << endl;
}

void Executive::PrintLeafs()
{
  cout << "Output: " << "the leaf nodes are: ";
  m_tree.PrintLeaf();
  cout << endl; 
}

void Executive::PrintMenu()
{
  while(1)
  {
    int choice;
    cout << "--------------------------------------------------------" << endl;
    cout << "Please choose one of the following commands:" << endl;
    cout << "1- IsFull " << endl;
    cout << "2- AddItem " << endl;
    cout << "3- Delete " << endl;
    cout << "4- Leaf " << endl;
    cout << "5- PrintLeaf " << endl;
    cout << "6- PrintTreeHeight " << endl;
    cout << "7- Preorder " << endl;
    cout << "8- Postorder " << endl;
    cout << "9- Inorder " << endl;
    cout << "10- Levelorder " << endl;
    cout << "11- Exit " << endl;
    cout << ">";
    cin >> choice;

    if(choice ==1)
      isFull();
    if(choice == 2)
      AddItem();
    if(choice ==3)
      Delete();
    if(choice ==4)
      Leaf();
    if(choice ==5)
      PrintLeafs();
    if(choice ==6)
      Height();
    if(choice ==7)
      PreOrder();
    if(choice ==8)
      PostOrder();
    if(choice ==9)
      InOrder();
    if(choice ==10)
      LevelOrder();
    if(choice ==11)
    {
      cout << "Output: Goodbye!" << endl;
      break;
    }
  }

}
