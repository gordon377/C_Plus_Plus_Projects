#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;

Item::Item(char* nameIN){
  strcpy(name, nameIN);
}

char* Item::getName(){
  return name;
}
