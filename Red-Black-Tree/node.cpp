#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(){
  red = true;
  parent = NULL;
  left = NULL;
  right = NULL;
  value = 0;
}

Node::~Node(){ //May have to adjust when looking into deletions
  delete left;
  delete right;
}

bool Node::returnRed(){
  return red;
}

Node* Node::returnParent(){
  return parent;
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



void Node::recolor(){
  if(red == true){
    red = false;
  }
  else if(red == false){
    red = true;
  }
}

void Node::makeParent(Node* inputParent){
  parent = inputParent;
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
