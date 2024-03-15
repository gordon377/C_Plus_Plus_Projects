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


Node* Node::returnRight(){
  return right;
}

Node* Node::returnLeft(){
  return left;
}

char* Node::returnValue(){
  return value;
}

Node* Node::returnNext(){
  return next;
}





void Node::makeRight(Node* inputRight){
  right = inputRight;
}

void Node::makeLeft(Node* inputLeft){
  left = inputLeft;
}

void Node::makeValue(char* inputValue){
  value = inputValue;
}

void Node::makeNext(Node* inputNext){
  next = inputNext;
}

