#include "Executive.h"

void Executive::Preorder()
{
  cout << ">Output: " << endl;
  cout << ">Preorder Traversal: ";
  lmh.Preorder();
  cout << endl;
}
void Executive::Inorder()
{
  cout << ">Output: " << endl;
  cout << ">Inorder Traversal: ";
  lmh.Inorder();
  cout << endl;
}
void Executive::Postorder()
{
  cout << ">Output: " << endl;
  cout << ">Postorder Traversal: ";
  lmh.PostOrder();
  cout << endl;
}
void Executive::Levelorder()
{
  cout << ">Output: " << endl;
  cout << ">Levelorder Traversal: ";
  lmh.LevelOrder();
  cout << endl;
}


void Executive::Insert()
{
  int value;
cout << "> Output: Enter the value you want to insert" << endl;
cin >> value;
cout << ">Output: " << value << " has been successfully inserted into the tree." << endl;
lmh.insert(value);
cout << ">The new level order traversal is: ";
lmh.LevelOrder();
cout << endl;
}
void Executive::Merge()
{
  int value;
  LeftistMinHeap temp;
  cout << ">Output: Enter the three elements for the tree H2: ";
  cin >> value;
  temp.insert(value);
  cin >> value;
  temp.insert(value);
  cin >> value;
  temp.insert(value);
  cin >> value;
  lmh.MergeHeaps(temp);
  cout << ">Output: Trees H1 and H2 have been merged to form new tree H3. The new level order" << endl;
  cout << "traversal for tree H3 is: ";
  lmh.LevelOrder();
  cout << endl;
}
void Executive::Deletemin()
{
  if(lmh.isEmpty())
  {
    cout << ">Output: you cannot delete from an empty heap" << endl;
  }
  else
  {
    lmh.DeleteMin();
    cout << ">Output: The minimum element has been deleted, and the tree has been rearranged. The new" << endl;
    cout << "level order traversal is: ";
    lmh.LevelOrder();
    cout << endl;
  }
}


void Executive::FindMin()
{
  if(lmh.isEmpty())
  {
    cout << ">Output: cannot locate minimum element of empty heap" << endl;
  }
  else
  {
    cout << ">Output: The minimum element is " << lmh.FindMin() << endl;
  }
}
Executive::Executive(string fileName)
{
  int value;
  inFile.open(fileName);
  while(inFile>> value)
  {
    lmh.insert(value);
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
    cout << "3. Deletemin" << endl;
    cout << "4. Findmin" << endl;
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
      Deletemin();
    }
    if(selec ==4)
    {
      FindMin();
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
