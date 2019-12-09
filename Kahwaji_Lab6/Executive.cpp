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
    t = clock();
    while(inFile >> x)
    {
      max.insert(x);
      min.insert(x);
    }
    t= clock() -t;
    float time = ((float)t)/CLOCKS_PER_SEC;
    cout << "Time taken to heapify heaps: " << time << "s" << endl;
  }
}


void Executive::Insert()
{
  int val;
  cout << "Enter the number: ";
  cin >> val;
  max.insert(val);
  min.insert(val);
  cout << "Output: " << val << " has been added successfully" << endl;
}
void Executive::Delete()
{
  max.Delete();
  min.Delete();
  cout << "Output: The element with the highest priority has been deleted." << endl;
}
void Executive::PQ_Highest()
{
  cout << "MinHeap: The element with highest priority is " << min.PQ_Highest() << endl;
  cout << "MaxHeap: The element with highest priority is " << max.PQ_Highest() << endl;
}
void Executive::PQ_Lowest()
{
  cout << "MinHeap: The element with lowest priority is " << min.PQ_Lowest() << endl;
  cout << "MaxHeap: The element with lowest priority is " << max.PQ_Lowest() << endl;
}
void Executive::LevelOrder()
{
  cout << "Max Heap Output: " << endl;
  cout << "Level Order Traversal" << endl;
  max.LevelOrder();
  cout << endl;
  cout << "Min Heap output: " << endl;
  cout << "Level Order Traversal" << endl;
  min.LevelOrder();
  cout << endl;
}

void Executive::Time_LowestPQ()
{
  t= clock();
  max.PQ_Lowest();
  min.PQ_Lowest();
  t= clock()-t;
  cout << "Time taken for PQ_Lowest: ";
  cout << ((float)t)/ CLOCKS_PER_SEC << "s";
  cout << endl;
}

void Executive::Time_HighestPQ()
{
  t= clock();
  max.PQ_Highest();
  min.PQ_Highest();
  t= clock()-t;
  cout << "Time taken for PQ_Highest: ";
  cout << ((float)t)/ CLOCKS_PER_SEC << "s";
  cout << endl;
}
void Executive::Time_Delete()
{
  t= clock();
  max.Delete();
  min.Delete();
  t= clock()-t;
  cout << "Time taken to delete node: ";
  cout << ((float)t)/CLOCKS_PER_SEC << "s";
  cout << endl;
}
void Executive::PrintMenu()
{
  while(1)
  {
    int selection;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. PQ_Highest" << endl;
    cout << "4. PQ_Lowest" << endl;
    cout << "5. Level_Order" << endl;
    cout << "6. Time_LowestPQ" << endl;
    cout << "7. Time_HighestPQ" << endl;
    cout << "8. Time_Delete" << endl;
    cout << "9. Exit" << endl;
    cout << "> ";
    cin >> selection;
    if(selection ==1)
    {
      Insert();
    }
    if(selection ==2)
    {
      Delete();
    }
    if(selection ==3)
    {
      PQ_Highest();
    }
    if(selection ==4)
    {
      PQ_Lowest();
    }
    if(selection ==5)
    {
      LevelOrder();
    }
    if(selection ==6)
    {
        Time_LowestPQ();
    }
    if(selection ==7)
    {
      Time_HighestPQ();
    }
    if(selection ==8)
    {
        Time_Delete();
    }
    if(selection ==9)
    {
      break;
    }

  }
}
