#include <iostream>
#include "vtex.h"

using namespace std;

vtex::~vtex(){ //Deconstructor function
  int y = 0;
  index = 0;
  name = '\0';
  while (y < 20) {
    edges[y] = 0;
    y++;
  }
}

vtex::vtex(){ //Constructor function
  int x = 0;
  name = '\0';
  while (x < 20){
    edges[x] = 0;
    x++;
  }
}

//make functions

void vtex::mkIndex(int inIndex){
  index = inIndex;
}

void vtex::mkName(char inName){
  name = inName;
}

void vtex::mkEdge(int dir, int value){
  edges[dir] = value;
}

//return functions
int vtex::returnIndex(){
  return index;
}

char vtex::returnName(){
  return name;
}

int vtex::returnEdge(int dir){
  return edges[dir];
}
