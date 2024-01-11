#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

Node::Node(){ // Default constructor
  nextNode = NULL;
  student = new Student();
}

Node::Node(Student* newStud){ //Constructor with given student input
  nextNode = NULL;
  student = newStud;
}

Node::~Node(){ // Destructor
  delete student;
  nextNode = NULL;
}


void Node::setStudent(Student* newStud){
  student = newStud;
}

Student* Node::getStudent(){
  return student;
}

void Node::setNext(Node* newNode){
  nextNode = newNode;
}

Node* Node::getNext(){
  return nextNode;
}

