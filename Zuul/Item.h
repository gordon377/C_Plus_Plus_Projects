#ifndef ITEM
#define ITEM

#include <iostream>
#include <cstring>

using namespace std;

class Item{
 public:
  Item(char* nameIN);
  char name[101];
  char* NameInput();

};

#endif
