#include "Graph.h"

Graph::~Graph()
{
  for(int i =0; i<m_cost; i++)
  {
    delete[] m_costArray[i];
  }
  delete[] m_costArray;
  delete[] eArray;
  delete[] m_vArray;
}

void Graph::Prims()
{
  Queue<Edge> Et;
  Queue<Edge> ignore;
  Queue<int> Vt;
  Edge ignoreSet(1,3);
  ignore.insert(ignoreSet);
  int totalCost = 0;
  Vt.insert(1);
  MinHeap Q;
  for(int i =0; i<m_sizeEdgesArray;i++)
  {
    if(!ignore.contains(eArray[i]) && Vt.contains(eArray[i].getFirstVertice()) && !Vt.contains(eArray[i].getSecondVertice()))
    {
      Q.insert(eArray[i]);
    }
  }

    while(Vt.getLength() != m_cost && !Q.isEmpty())
    {
      Edge x = Q.PQ_Highest();
      Q.Delete();
      Et.insert(x);
      totalCost += x.getWeight();
      Vt.insert(x.getSecondVertice());
        for(int i =0; i<m_sizeEdgesArray;i++)
        {
         if(!ignore.contains(eArray[i]) && Vt.contains(eArray[i].getFirstVertice()) && !Vt.contains(eArray[i].getSecondVertice()))
          {
            Q.insert(eArray[i]);
          }
         else if(!ignore.contains(eArray[i]) && !Vt.contains(eArray[i].getFirstVertice()) && Vt.contains(x.getSecondVertice()))
          {
            Q.insert(eArray[i]);
          }
        }
      }

    if(Vt.getLength() == m_cost)
    {
      Node<Edge>* temp = Et.getFront();
        while(temp != nullptr)
        {
          cout << temp->getEntry().getEdge() << "{" << temp->getEntry().getWeight() << "}" << " ";
          temp = temp->getNext();
        }
        cout << endl << "Total cost = " << totalCost << endl;
    }
    else
    {
      cout << "No minimum spanning tree exists" << endl;
    }

}

void Graph::Kruskal()
{
  int minCost =0;
  int n = m_cost;
  DisjointSet d;
  MinHeap m;
  Queue<Edge> result;
  for(int i =0; i<m_cost; i++)
  {
    d.MakeSet(m_vArray[i]);
  }
  for(int i =0; i<m_sizeEdgesArray;i++)
  {
    m.insert(eArray[i]);
  }
  while(!m.isEmpty() && result.getLength() < n-1)
  {
    Edge e = m.PQ_Highest();
    m.Delete();
    if(d.Find(e.getFirstVertice()) != d.Find(e.getSecondVertice()))
    {
      result.insert(e);
      d.Union(e.getFirstVertice(), e.getSecondVertice());
      minCost += e.getWeight();
    }
  }
  if(result.getLength() == n-1)
  {
    Node<Edge>* temp = result.getFront();
    while(temp != nullptr)
    {
      cout << temp->getEntry().getEdge() << "{" << temp->getEntry().getWeight() << "}" << " ";
      temp = temp->getNext();
    }
    cout << endl << "Total Cost = " << minCost << endl;
  }
  else
  {
    cout << "No minimum spanning tree exists" << endl;
  }
}

void Graph::_DFS(int vertice, bool* arr)
{
  arr[vertice] = true;
  string result = "(" + to_string(vertice) + ",";
  if(lookUpTable[vertice].getFront() != nullptr)
  {
    result += to_string(lookUpTable[vertice].getFront()->getEntry()) + ")" + " ";
    cout << result;
    Edge e(vertice, lookUpTable[vertice].getFront()->getEntry());
    currentEdges.insert(e);
  }

  Node<int>* temp = lookUpTable[vertice].getFront();
  while (temp !=nullptr)
  {
    if(!arr[temp->getEntry()])
    {
      _DFS(temp->getEntry(), arr);
    }
    temp = temp->getNext();
  }
}

void Graph::DFS()
{
  bool visitedVertices[m_sizeEdgesArray];
  for(int i =0; i<m_sizeEdgesArray;i++)
  {
    visitedVertices[i] = false;
  }
  cout << "Tree Edges: ";
  _DFS(1, visitedVertices);
  cout << endl;
  cout << "Back Edges: ";
  for(int i =0; i<m_sizeEdgesArray;i++)
  {
    if(!currentEdges.contains(eArray[i]))
    {
      cout << eArray[i].getEdge() << " ";
    }
  }
  cout << endl;
  currentEdges.clear();
}

void Graph::BFS()
{
  int start = 1;
  bool seen[m_sizeEdgesArray];
  for(int i =0; i<m_sizeEdgesArray;i++)
  {
    seen[i]= false;
  }
  Queue<Edge> temp;
  seen[start] = true;
  temp.insert(lookUpEdgeTable[start].getFront()->getEntry());
  currentEdges.insert(lookUpEdgeTable[start].getFront()->getEntry());
  Node<Edge>* temp2 = lookUpEdgeTable[start].getFront()->getNext();
  cout << "Tree Edges: ";
  while(!temp.isEmpty())
  {
    Edge e = temp.peek();
    cout << e.getEdge() << " ";
    temp.Dequeue();
    while(temp2 != nullptr)
    {
      if(!seen[temp2->getEntry().getSecondVertice()])
      {
        seen[temp2->getEntry().getSecondVertice()] = true;
        temp.insert(temp2->getEntry());
        currentEdges.insert(temp2->getEntry());
      }
      temp2 = temp2->getNext();
    }
  }
  cout << endl;
  cout << "Cross Edges: ";
  for(int i =0; i<m_sizeEdgesArray;i++)
  {
    if(!currentEdges.contains(eArray[i]))
    {
      cout << eArray[i].getEdge() << " ";
    }
  }
  cout << endl;
  currentEdges.clear();
}

void Graph::intializeLookUpTable()
{
  for(int i =0; i<m_sizeEdgesArray;i++)
  {
    lookUpTable[eArray[i].getFirstVertice()].insert(eArray[i].getSecondVertice());
  }
}
void Graph::intializeLookUpEdgeTable()
{
  for(int i =0; i<m_sizeEdgesArray;i++)
  {
    lookUpEdgeTable[eArray[i].getFirstVertice()].insert(eArray[i]);
  }
}
void Graph::BuildGraph(int** cost, int n)
{
  m_cost = n;
  m_costArray = cost;
  buildVertices();
  buildEdgesArray();
  intializeLookUpTable();
  intializeLookUpEdgeTable();
}


void Graph::buildVertices()
{
  m_vArray = new int[m_cost];
  for(int i =0; i<m_cost; i++)
  {
    m_vArray[i] = i+1;
  }
}


void Graph::buildEdgesArray()
{
  m_sizeEdgesArray =0;
  eArray = new Edge[100];
  for(int i =0; i<m_cost;i++)
  {
    for (int j =0; j<m_cost; j++)
    {
      if(m_costArray[i][j] != 1 && m_vArray[i] < m_vArray[j] && m_costArray[m_vArray[i]-1][m_vArray[j]-1] != -1)
      {
        int v1 = m_vArray[i];
        int v2 = m_vArray[j];
        Edge e(v1, v2);
        e.setWeight(m_costArray[v1-1][v2-1]);
        eArray[m_sizeEdgesArray] = e;
        m_sizeEdgesArray++;
      }
    }
  }
}
