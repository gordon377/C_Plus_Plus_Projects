#include <iostream>
#incldue "Student.h"
#include "Node.h"

using namespace std;

Node::Node(Student* newStudent){
  stud = newStudent;
  next = NULL;
}

Node::~Node(){
  delete stud;
  next = NULL;
}

Node* Node::getNext(){
  return next;
}

Student* Node::getStudent(){
  return stud;
}

void Node::setNext(Node* n){
  next = n;
}
