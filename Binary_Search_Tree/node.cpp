#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node() {
  left = NULL;
  right = NULL;
  value = 0;
}

Node::~Node(){

}


Node* Node::returnRight(){
  return right;
}

Node* Node::returnLeft(){
  return left;
}

int Node::returnValue(){
  return value;
}





void Node::makeRight(Node* inputRight){
  right = inputRight;
}

void Node::makeLeft(Node* inputLeft){
  left = inputLeft;
}

void Node::makeValue(int inputValue){
  value = inputValue;
}
