#include "DataCollection.h"



void DataCollection::IntializeSet()
{
  inFile.open("data2.txt");
  outFile.open("result.txt");
  int val;
  while(inFile >> val)
  {
    ds.MakeSet(val);
  }
}

void DataCollection::UnionData()
{
  for(int i =1; i<=1000; i++)
  {
    for(int j= i+1; j<=1000; j++)
    {
      ds.Union(i,j);
    }
  }
}

void DataCollection::FindDataWithoutCompression()
{
  outFile<< "--TIME TAKEN TO FIND BEFORE PATH COMPRESSION--" << endl;
  float time;
  for(int i =1; i<=1000; i++)
  {
    t= clock();
    ds.Find(i);
    t= clock() -t;
    time = (((float)t)/ CLOCKS_PER_SEC) * (1000.0) ;
    outFile << i << ": " << setprecision(5) << time << " ms" << endl;
  }
}

void DataCollection::FindDataWithCompression()
{
  outFile << "--TIME TAKEN TO FIND AFTER PATH COMPRESSION--" << endl;
  float time;
  for(int i =1; i<=1000; i++)
  {
    ds.PathCompression(i);
    t= clock();
    ds.Find(i);
    t= clock() -t;
    time = (((float)t)/ CLOCKS_PER_SEC) * (1000.0) ;
    outFile << i << ": " << setprecision(5) << time <<  " ms" << endl;
  }
}
