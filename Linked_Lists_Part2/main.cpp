#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

int validIn();
void ADD(Node* &head, Node* current, Node* prev, Node* inputNode);
void PRINT(Node* head);
void DELETENode(Node* &head, Node* current, Node* prev, int ID);
void AVG(Node* head, float totalGPA, int total);

int main() {
  Node* head = NULL;
  Node* current;
  Node* prev;
  bool active = true;
  while (active == true) {
    int choice = validIn();
    // ADD Function
    if (choice == 1) {
      Student* inputStud = new Student();

      // First Name
      cout << "Please enter the first name." << endl;
      char input[101];
      cin.get(input, 100);
      cin.get();
      strcpy(inputStud->getFirstName(), input);

      // Last Name
      cout << "Please enter a last name." << endl;
      cin.get(input, 20);
      cin.get();
      strcpy(inputStud->getLastName(), input);

      // ID
      cout << "Please enter an ID" << endl;
      int input_ID;
      cin >> input_ID;
      cin.get();
      inputStud->setID(input_ID);

      // GPA
      cout << "Please enter the GPA" << endl;
      float GPAInput;
      cin >> GPAInput;
      cin.get();
      inputStud->setGPA(GPAInput);

      Node* inputNode = new Node();
      inputNode->setStudent(inputStud);
      
      ADD(head, head, head, inputNode);
    }
    // DELETE Function
    else if (choice == 2) {
      int idIn;
      cout << "Please enter the ID of the user you which to delete." << endl;
      cin >> idIn;
      cin.get();
      DELETENode(head, head, head, idIn);
    }
    // PRINT Function
    else if (choice == 3) {
      PRINT(head);
    }
    // AVG Function
    else if (choice == 4) {
      float totalGPA = 0;
      int total = 0;
      AVG(head, totalGPA, total);
    }
    // Exit Function
    else if (choice == 5) {
      active= false;
    }
  }
}

// Return Choice
int validIn() {
  int terminal;
  bool inputChoice = true;
  while (inputChoice == true) {
    cout << endl << "Enter the number corresponding to action you want to do \n 1: ADD Student \n 2: DELETE Student \n 3: PRINT Student Data \n 4: AVERAGE Student Data \n 5: Exit Program" << endl;
    cin >> terminal;
    cin.get();
    if(terminal == 1 || terminal == 2 || terminal == 3 || terminal == 4 || terminal == 5){
      return terminal;
    }
    else {
      cout << "Invalid Input" << endl;
    }
  }
  return -1;
}

void ADD(Node* &head, Node* current, Node* prev, Node* inputNode) {
  if (head == NULL) {
    head = inputNode;
  }
  else {
    // Ordering Nodes by ID value (Check if ID is greater)
    if (inputNode->getStudent()->getID() < head->getStudent()->getID()) {
	Node* tmpNode = head;
	head = inputNode;
	head->setNext(tmpNode);
    }
    // Node added between two other nodes
    else if ((inputNode->getStudent()->getID() > prev->getStudent()->getID()) && (inputNode->getStudent()->getID() < current->getStudent()->getID())) {
      prev->setNext(inputNode);
      inputNode->setNext(current);
    }
    // New Node reaches end of list, therefore has the largest ID and is added at the end
    else if (current->getNext() == NULL) {
      current->setNext(inputNode);
    }
    // Recursion to run through the next Node
    else {
      ADD(head, current->getNext(), current, inputNode);
    }
  }
}
  
void PRINT(Node* head) {
  //Empty List
  if (head == NULL) {
    cout << "Empty List" << endl;
  }
  // List with only head
  else if (head != NULL && head->getNext() == NULL) {
    head->getStudent()->printStud();
  }
  // Recursion & Print Student Data
  else if (head->getNext() != NULL) {
    head->getStudent()->printStud();
    PRINT(head->getNext());
  }
}

void DELETENode(Node* &head, Node* current, Node* prev, int ID) {
  // Empty list
  if (head == NULL) {
    cout << "Empty" << endl;
  }
  // If no student is found of that ID
  else if (current == NULL) {
    cout << "No student in this Linked List matches this ID" << endl;
  }
  // ID & Node Match Case
  else if (current->getStudent()->getID() == ID) {
    // If match is the head and head is the only part of the list
    if (current == head && head->getNext() == NULL) {
      head->~Node();
      head = NULL;
    }
    // If match is the head and head is not the only part of hte list
    else if (current == head) {
      Node* tmpNode = head->getNext();
      head->~Node();
      head = tmpNode;
    }
    // If deleted node has a next node
    else if (current != head && current->getNext() != NULL) {
      prev->setNext(current->getNext());
      current->~Node();
    }
    // If deleted node doesn't have a next node 
    else if (current != head && current->getNext() == NULL) {
      prev->setNext(NULL);
      current->~Node();
    }
  }
  // Recursion to go to next node
  else {
    DELETENode(head, current->getNext(), current, ID);
  }
}

void AVG(Node* head, float totalGPA, int total) {
  // Empty list
  if (head == NULL && total == 0) {
    cout << "Empty List" << endl;
  }
  // Sum up GPAs and Increase total count to keep track of the amount of students accounted for
  else if (head != NULL) {
    totalGPA += head->getStudent()->getGPA();
    total++;
    AVG(head->getNext(), totalGPA, total);
  }
  // Average it!
  else {
    cout << fixed << setprecision(3) << (totalGPA/total);
  }
}
