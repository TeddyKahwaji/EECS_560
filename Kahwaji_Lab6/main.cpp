#include <iostream>

#include <cstring>
#include "Executive.h"
using namespace std;
int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    cout << "Incorrect number of parameters!\n";
  }
  else
  {


     Executive exec(argv[1]); //sample creation of executive object
     exec.PrintMenu();
  }

  return(0);
}
