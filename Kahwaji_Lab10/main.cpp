#include <iostream>
using namespace std;
#include "Executive.h"

int main()
{
  Executive exec("data.txt");
  exec.printMenu();
  return 0;
}
