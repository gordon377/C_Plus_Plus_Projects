#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "student.h"

/* Node Structure: Pair of data, one is a student following the defined structure
 * and the other is a pointer to the next node
 * in the sequence (Linear Linked List)
 */

class Node{
 public:
  Node(); // Default constructor
  Node(Student*); // Manual constructor to set specific students
  ~Node(); // Destructor

  //Next Node functions
  void setNext(Node*); // set next node pointer
  Node* getNext(); // return next node in list

  //Student functions
  void setStudent(Student*); // set student to node
  Student* getStudent(); // return pointer to student

 private:
  Student* student; // return student value of node
  Node* nextNode; // return next node value of node
};
#endif
