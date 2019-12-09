#include "Executive.h"



Executive::Executive(string fileName)
{
  inFile.open(fileName);
  char value;
  while(inFile >> value)
  {
    m_tree.Insert(value);
  }
  PrintMenu();
}
void Executive::SearchItem()
{
  char x;
cout << "Enter the character to be found." << endl;
cin >> x;
  if(m_tree.contains(x))
  {
    cout << "The character is present in the tree." << endl;
  }
  else
  {
    cout << "The character is not present in the tree." << endl;
  }
}
void Executive::AddItem()
{
  char value;
  cout << "Please enter the character which you want to enter into the tree." << endl;
  cin >> value;
  cout << "Output: The element was inserted successfully" << endl;
  m_tree.Insert(value);
}

void Executive::Delete()
{
  char c;
  cout << "Please enter the character to be deleted." << endl;
    cin >> c;
  if(!m_tree.contains(c))
  {
    cout << "Deletion failed. The character is not present in the tree" << endl;
    return;
  }

  m_tree.Delete(c);
  cout << "Deletion was successful." << endl;
}
void Executive::Leaf()
{
  char value;
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
  cout << "Output: " << "Pre Traversal-";
  m_tree.PrintPreOrder();
  cout << endl;
}
void Executive::PostOrder()
{
  cout << "Output: " << "Postorder Traversal-";
  m_tree.PrintPostOrder();
  cout << endl;
}
void Executive::InOrder()
{
  cout << "Output: " << "Inorder Traversal-";
  m_tree.PrintInOrder();
  cout << endl;
}
void Executive::LevelOrder()
{
  cout << "Output: " << "Levelorder Traversal-";
  m_tree.PrintLevelOrder();
  cout << endl;
}

void Executive::PrintLeafs()
{
  cout << "Output: " << "The leaves are: ";
  m_tree.PrintLeafNodes();
  cout << endl;
}

void Executive::PrintMenu()
{
  while(1)
  {
    int choice;
    cout << "--------------------------------------------------------" << endl;
    cout << "Please choose one of the following commands:" << endl;
    cout << "1- AddItem " << endl;
    cout << "2- Delete " << endl;
    cout << "3- Leaf " << endl;
    cout << "4- PrintLeaf " << endl;
    cout << "5- TreeHeight " << endl;
    cout << "6- Preorder " << endl;
    cout << "7- Postorder " << endl;
    cout << "8- Inorder " << endl;
    cout << "9- Levelorder " << endl;
    cout << "10- SearchItem " << endl;
    cout << "11- Exit " << endl;
    cout << ">";
    cin >> choice;

    if(choice ==1)
      AddItem();
    if(choice == 2)
      Delete();
    if(choice ==3)
      Leaf();
    if(choice ==4)
      PrintLeafs();
    if(choice ==5)
      Height();
    if(choice ==6)
      PreOrder();
    if(choice ==7)
      PostOrder();
    if(choice ==8)
      InOrder();
    if(choice ==9)
      LevelOrder();
    if(choice ==10)
      SearchItem();
    if(choice ==11)
    {
      cout << "Output: Goodbye!" << endl;
      break;
    }
  }

}
