#include "Executive.h"


Executive::Executive(string fileName)
{
  inFile.open(fileName);
  if(inFile.is_open())
  {
    int listValue;
    while(inFile>> listValue)
    {
      List.insert(listValue);
    }
    printMenu();
  }
  else
  {
    cout << "Invalid Filename" << endl;
  }
}

void Executive::Insert()
{
  int value;

    cout << "Enter the number to be inserted in list: ";
    cin >> value;
  List.insert(value);
}

void Executive::Delete()
{
  int value;
  cout << "Enter the number to be deleted: ";
  cin >> value;
  List.Delete(value);
}
void Executive::Smallest()
{
  cout << "Smallest number: " << List.getSmallest() << endl;
}


void Executive::Largest()
{
  cout << "Largest number: " << List.getLargest() << endl;
}

void Executive::Average()
{
  cout << "Average: " << List.getAverage() << endl;
}
void Executive::Print()
{
    cout << "List: ";
 List.Print();
}

void Executive::Merge()
{
  cout << "Enter new list to be merged" << endl;
  int x;
  while(cin >> x)
  {
    List.insert(x);
    if(cin.peek() == '\n')
      break;
  }

List.SortMergedList();

cout << "Merged List: ";
List.Print();

}


void Executive::Reverse()
{
  List.ReverseList();
}
void Executive::printMenu()
{
  while(1)
  {
    int input;
    cout << endl;
    cout << "Choose one operation from the options below:" << endl << endl;
    cout << "1. Insert" << endl << "2. Delete" << endl << "3. Find smallest number" << endl;
    cout << "4. Find largest number" << endl << "5. Average of numbers" << endl << "6. Merge2Lists" << endl;
    cout << "7. Print" << endl << "8. ReverseList" <<endl <<  "9. Exit" << endl << endl;
    cout << ">> ";
    cin >> input;

    if(input ==1)
      Insert();
    if(input ==2)
      Delete();
    if(input ==3)
      Smallest();
    if(input ==4)
      Largest();
    if(input ==5)
      Average();
    if(input ==6)
      Merge();
    if(input ==7)
      Print();
    if(input ==8)
      Reverse();
    if(input ==9)
      break;
  }
}
