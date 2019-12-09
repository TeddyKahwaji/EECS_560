#include "Executive.h"



Executive::Executive(string fileName)
{
  m_fileName = fileName;
  IntializeGraph();
}

void Executive::IntializeGraph()
{
  graphFile.open("data1.txt");
  int n;
  int val;
  graphFile >> n;
  int** arr = new int*[n];
  for(int i =0; i<n; i++)
  {
    arr[i] = new int[n];
  }
  for(int i =0; i<n; i++)
  {
    for(int j =0; j<n; j++)
    {
      graphFile >> val;
      arr[i][j] = val;
    }
  }
  g.BuildGraph(arr,n);
}
void Executive::MainMenu()
{
  int selec;
  cout << "--------MAIN MENU--------" << endl;
  cout << "Please select from the following options" << endl;
  cout << "1. Disjoint Lab" << endl;
  cout << "2. Graph Lab" << endl;
  cout << "3. Data Collection For Disjoint Lab" << endl;
  cout << "4. Exit" << endl;
  cout << "> ";
  cin >> selec;
  if(selec ==1)
  {
    printMenuDS();
  }
  if(selec ==2)
  {
    printMenuGraph();
  }
  if(selec ==3)
  {
    cout << "Intializing Set for Data collection: "  << "100%" << endl;
    data.IntializeSet();
    cout << "Unioning Set for Data collection: "  << "100%" << endl;
    data.UnionData();
    cout << "Recording Data without Path Compression: "  << "100%" << endl;
    data.FindDataWithoutCompression();
    cout << "Recording Data with Path Compression: "  << "100%" << endl;
    data.FindDataWithCompression();
    cout << "Data Collection completed and can be found in result.txt file" << endl;
    cout << endl;
    MainMenu();
  }
  if(selec ==4)
  {
    cout << "GoodBye!" << endl;
    return;
  }
}
void Executive::MakeSet()
{
  int val;
  inFile.open(m_fileName);
  while(inFile >> val)
  {
    ds.MakeSet(val);
  }
  cout << ">Output: The disjoint sets have been constructed." << endl;
  m_hasMadeSet = true;
}
void Executive::StartUnion()
{
  if(!m_hasMadeSet)
  {
    cout << ">Output: you cannot union without making set!" << endl;
    return;
  }
  else
  {
    int val1;
    int val2;
    cout << ">Output: Enter the representative elements for the two sets which you wish to union: " << endl;
    cin >> val1>> val2;
    ds.Union(val1,val2);
    cout << ">Output: " <<val1 << " and " << val2 << " have been merged. The reprsentative element is " <<
    ds.Find(val1) << endl;
  }
}
void Executive::Find_Timer()
{
  int selec;
  cout << "> Output: Enter the element you want to find: " << endl;
  cin >> selec;
  if(!ds.Contains(selec))
  {
    cout << "> Output: Sorry! " << selec << " is not found!" << endl;
    return;
  }
  else
  {
    t= clock();
    ds.Find(selec);
    t= clock() -t;
    float time = (((float)t)/ CLOCKS_PER_SEC) * (1000.0) ;
    cout << ">Output: Time taken to find " << selec << " is " << time << " milliseconds" << endl;
  }
}
void Executive::Path_Compression()
{
  int selec;
  cout << "> Output: Enter the element you want to find: " << endl;
  cin >> selec;
  if(!ds.Contains(selec))
  {
    cout << "> Output: Sorry! " << selec << " is not found!" << endl;
    return;
  }
  else
  {
    ds.PathCompression(selec);
    cout << ">Output: Path compression has been done sucessfully" << endl;

  }
}
void Executive::printMenuDS()
{
  while(1)
  {
    int selec;
    cout << "Please choose one of the following commands:"<< endl;
    cout << "1- MakeSet" << endl;
    cout << "2- StartUnion" << endl;
    cout << "3- Find_Timer" << endl;
    cout << "4- Path_Compression" << endl;
    cout << "5- Exit" << endl;
    cout << ">Enter your choice:" << endl;
    cout << ">";
    cin >> selec;

    if(selec == 1)
    {
      MakeSet();
    }
    if(selec == 2)
    {
      StartUnion();
    }
    if(selec == 3)
    {
      Find_Timer();
    }
    if(selec == 4)
    {
      Path_Compression();
    }
    if(selec ==5)
    {
      cout << "Goodbye!" << endl << endl;
      MainMenu();
      break;
    }
  }
}


void Executive::printMenuGraph()
{
  while(1)
  {
    int selec;
    cout << "Please choose one of the following commands: " << endl;
    cout << "1- BFS" << endl;
    cout << "2- DFS" << endl;
    cout << "3- Kruskal MST" << endl;
    cout << "4- Prim MST" << endl;
    cout << "5- Exit" << endl;
    cout << ">";
    cin >> selec;
    if(selec ==1)
    {
      BFS();
    }
    if(selec ==2)
    {
      DFS();
    }
    if(selec ==3)
    {
      Kruskal();
    }
    if(selec ==4)
    {
      Prim();
    }
    if(selec ==5)
    {
      cout << "Bye!" << endl << endl;
      MainMenu();
      break;
    }
  }
}


void Executive::BFS()
{
  g.BFS();
}

void Executive::DFS()
{
  g.DFS();
}

void Executive::Kruskal()
{
  g.Kruskal();
}
void Executive::Prim()
{
  g.Prims();
}
