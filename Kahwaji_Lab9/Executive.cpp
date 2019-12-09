#include "Executive.h"

void Executive::Preorder()
{
  cout << ">Output: " << endl;
  cout << ">Preorder Traversal: ";
  msh.Preorder();
  cout << endl;
}
void Executive::Inorder()
{
  cout << ">Output: " << endl;
  cout << ">Inorder Traversal: ";
  msh.Inorder();
  cout << endl;
}
void Executive::Postorder()
{
  cout << ">Output: " << endl;
  cout << ">Postorder Traversal: ";
  msh.PostOrder();
  cout << endl;
}
void Executive::Levelorder()
{
  cout << ">Output: " << endl;
  cout << ">Levelorder Traversal: ";
  msh.LevelOrder();
  cout << endl;
}


void Executive::Insert()
{
  int value;
cout << "> Output: Enter the value you want to insert" << endl;
cin >> value;
cout << ">Output: " << value << " has been successfully inserted into the tree." << endl;
msh.insert(value);
cout << ">The new level order traversal is: ";
msh.LevelOrder();
cout << endl;
}
void Executive::Merge()
{
  int value;
  MinSkewHeap temp;
  cout << ">Output: Enter the three elements for the tree H2: ";
  cin >> value;
  temp.insert(value);
  cin >> value;
  temp.insert(value);
  cin >> value;
  temp.insert(value);
  msh.MergeHeaps(temp);
  cout << ">Output: Trees H1 and H2 have been merged to form new tree H3. The new level order" << endl;
  cout << "traversal for tree H3 is: ";
  msh.LevelOrder();
  cout << endl;
}
void Executive::Delete()
{
  if(msh.isEmpty())
  {
    cout << ">Output: you cannot delete from an empty heap" << endl;
  }
  else
  {
    int element;
    cout << ">Output: Enter the element to be deleted: ";
    cin >> element;
    if(!msh.Find(element))
    {
    cout << ">Output: The element is not contained within heap, therefore it cannot be deleted" << endl;
    return;
    }
    msh.DeleteValue(element);
    cout << ">Output: The element was sucessfully deleted from the skew heap." << endl;

  }
}


void Executive::Find()
{
  if(msh.isEmpty())
  {
    cout << ">Output: cannot locate element in an empty heap" << endl;
  }
  else
  {
    int val;
    cout << ">Output: Enter the element to be found: ";
    cin >> val;
    if(msh.Find(val))
    {
      cout << ">Output: The element is found in the min-skew heap." << endl;
    }
    else
    {
      cout << ">Output: The element is NOT found in the min-skew heap." << endl;
    }
  }
}
Executive::Executive(string fileName)
{
  int value;
  inFile.open(fileName);
  while(inFile>> value)
  {
    msh.insert(value);
  }
}

void Executive::printMenu()
{
  while(1)
  {
    int selec;
    cout << "Please choose on of the following commands:" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Merge" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Find" << endl;
    cout << "5. Preorder" << endl;
    cout << "6. Inorder" << endl;
    cout << "7. Postorder" << endl;
    cout << "8. Levelorder" << endl;
    cout << "9. Exit" << endl;
    cout << ">Enter your choice: ";
    cin >> selec;
    if(selec ==1)
    {
      Insert();
    }
    if(selec ==2)
    {
      Merge();
    }
    if(selec ==3)
    {
      Delete();
    }
    if(selec ==4)
    {
      Find();
    }
    if(selec ==5)
    {
      Preorder();
    }
    if(selec ==6)
    {
      Inorder();
    }
    if(selec ==7)
    {
      Postorder();
    }
    if(selec ==8)
    {
      Levelorder();
    }
    if(selec ==9)
    {
      cout << "Goodbye!" << endl;
      break;
    }
  }
}
