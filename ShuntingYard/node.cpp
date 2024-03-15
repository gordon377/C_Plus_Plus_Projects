#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node() {
  left = NULL;
  right = NULL;
  data = NULL;
  next = NULL;
}

Node::~Node(){
  
}
