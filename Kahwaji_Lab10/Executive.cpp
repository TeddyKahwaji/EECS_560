#include "Executive.h"



Executive::Executive(string fileName)
{
  inFile.open(fileName);
  int val;
  while(inFile >> val)
  {
    bq.insert(val);
  }
}
void Executive::_insert()
{
  int element;
  cout << ">Output: Enter the element you want to be inserted:";
  cin >> element;
  bq.insert(element);
  cout << ">Output: " << element << " has been successfully inserted." << endl;

}
void Executive::_LevelOrder()
{
  cout << "> Output:" << endl;
  cout << "Local Level Order: " << endl;
  bq.levelOrder();
}
void Executive::_DeleteMin()
{
  if(bq.isEmpty())
  {
    cout << ">Output: Cannot delete minimum element from empty heap" << endl;
    return; 
  }
  bq.DeleteMin();
  cout << ">Output: Minimum element has been deleted." << endl;
}
void Executive::printMenu()
{
  while(1)
  {
    int selection;
    cout << "Please choose one of the following commands:" << endl;
    cout << "1- Insert" << endl;
    cout << "2- DeleteMin" <<endl;
    cout << "3- LevelOrder" << endl;
    cout << "4- Exit" << endl;
    cout << ">Enter your choice: ";
    cin >> selection;
    if(selection==1)
    {
      _insert();
    }
    if(selection==2)
    {
      _DeleteMin();
    }
    if(selection==3)
    {
      _LevelOrder();
    }
    if(selection ==4)
    {
      break;
    }
  }
}
