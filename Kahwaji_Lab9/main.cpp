#include <iostream>
#include <cstring>
#include <fstream>
#include "Executive.h"
#include "MinSkewHeap.h"

using namespace std;
int main()
{
MinSkewHeap mh;
fstream inFile;
Executive exec("data.txt");
exec.printMenu();
  return(0);
}
