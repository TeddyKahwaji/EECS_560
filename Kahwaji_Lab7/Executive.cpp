#include "Executive.h"




Executive::Executive(string FileName)
{
  inFile.open(FileName);

  if(!inFile.is_open())
  {
    cout << "Incorrect file name!" << endl;
    return;
  }
  else
  {
    int x;
    while(inFile >> x)
    {
      MinMax.insert(x);
    }
  }
}


void Executive::BuildHeap()
{
  cout << "Output: " << endl;
  if(MinMax.isEmpty())
  {
    cout << "cannot build an empty heap" << endl;
  }
  else
  {
    MinMax.BuildHeap();
    cout << endl;
  }

}
void Executive::Insert()
{
  int input;
  cout << ">Enter the element to be inserted: ";
  cin >> input;
  MinMax.insert(input);
  cout << "Output: " << input << " has been inserted successfully." << endl;
}
void Executive::Delete()
{
  if(MinMax.isEmpty())
  {
    cout << "Output: cannot delete from empty heap"  << endl;
  }
  else
  {
    MinMax.Delete();
    cout << "Output: " << "the root node has been deleted" << endl;
  }

}
void Executive::MinLevelElements()
{
  cout << "Output: ";
  MinMax.PrintMinLevels();
}
void Executive::MaxLevelElements()
{
  cout << "Output: ";
  MinMax.PrintMaxLevels();
}
void Executive::PrintMenu()
{
  while(1)
  {
    int selection;
    cout << "1. BuildHeap" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Delete" << endl;
    cout << "4. MinLevelElements" << endl;
    cout << "5. MaxLevelElements" << endl;
    cout << "6. Exit" << endl;
    cout << ">Enter your choice: " << endl;
    cout << "> ";
    cin >> selection;
    if(selection ==1)
    {
      BuildHeap();
    }
    if(selection ==2)
    {
      Insert();
    }
    if(selection ==3)
    {
      Delete();
    }
    if(selection ==4)
    {
      MinLevelElements();
    }
    if(selection ==5)
    {
      MaxLevelElements();
    }
    if(selection ==6)
    {
        break;
    }

  }
}
