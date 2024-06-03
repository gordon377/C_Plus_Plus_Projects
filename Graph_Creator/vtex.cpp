#include <iostream>
#include "vtex.h"

using namespace std;

vtex::vtex(){ //Constructor function
  int x = 0;
  name = '\0';
  while (x < 20){
    edges[x] = 0;
    x++;
  }
}
