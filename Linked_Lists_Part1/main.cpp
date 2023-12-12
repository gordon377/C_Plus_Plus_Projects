// First part of the linked student liust program
// Dec. 10th, 2023
// Gordon Chen

#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

int main(){ //Test the Linked List Structure/Set-Up
  Student* firstStud;
  Student* secondStud;
  firstStud->GPA = 4.00;
  secondStud->GPA = 4.40;

  Node* firstNode = new Node(firstStud);
  Node* secondNode = new Node(secondStud);

  firstNode->setNext(secondNode);

  //Debug | Print out GPAs to check if getStudent() works
  cout << "First Stud's GPA: " << firstNode->getStudent()->getGPA() << endl;
  cout<< "Second Stud's GPA: " << secondNode->getStudent()->getGPA() << endl;

  if((firstNode->getNext()) == secondNode) {
    cout << "The next node after the firstNode is the secondNode" << endl;
  }
}
