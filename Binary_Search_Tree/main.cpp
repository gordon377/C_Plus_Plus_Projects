//Binary Search Tree
//Gordon Chen
// March 18, 2024

#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

using namespace std;

//Function Prototypes

void SORT_INPUT(Node* inputNode, Node* currNode); //Input Value into tree properly (with respect to the root value)
void PRINT();
void REMOVENUM(); //To remove a nodes of a certain num
void ADDNUM(int inputNum);
bool SEARCH();



int main(){
  bool active = true;
  char input[50];
  int numElements = 0;
  int rootNum = 0; //Root Value to reference
  int inputValue = 0;
  Node* tempParentNode = new Node(); //Node to hold parent at given instant (for comparison) | Globally holds/represents the root (initial state before iterations)

  cout << "Input Root Value (First Input)" << endl; //Set root/begin tree
  cin >> rootNum;
  cin.clear();
  cin.ignore(10000, '\n');
  Node* rootNode = new Node(); //Being Tree
  rootNode->makeValue(rootNum);
  tempParentNode->makeValue(rootNum); //Set temp parent as root value for frist instance of iteration
  
  cout << "Input method for initial additional numbers: MANUAL or FILE?" << endl;
  cin >> input;
  cin.clear();
  cin.ignore(10000, '\n');
  if(strcmp(input, "MANUAL") == 0){
    cout << "How many additional numbers would you like to input?" << endl;
    cin >> numElements;
    numElements++;
    for (int i = 0; i < numElements-1; i++){
      
      cout << "Enter number: " << endl; //Continue to sort into tree
      cin >> inputValue;
      cin.clear();
      cin.ignore(10000, '\n');

      Node* tempNode = new Node();
      tempNode->makeValue(inputValue);
      
      SORT_INPUT(tempNode, rootNode); 
      
    }
  }
  else if(strcmp(input, "FILE") == 0){
    ifstream fin("Numbers.txt");
    int tmpValue = 0;
    while(fin >> tmpValue){
      numElements++;
      Node* tempNode = new Node(); //Does iterating to create a new node work like this? The same names won't conflict?
      tempNode->makeValue(inputValue);
      SORT_INPUT(tempNode, rootNode);
    }
  }
  cout << "DEBUG: INITIAL NUMBER LOADING FINISHED" << endl;

  while(active){
    cout << "\n Enter one of the following commands: PRINT, ADDNUM, REMOVENUM, QUIT" << endl;
    cin >> input;
    if(strcmp(input, "PRINT") == 0){
      PRINT(); //Figure out print function...
    }
    else if(strcmp(input, "REMOVENUM") == 0){
      REMOVENUM(): //Figure out remove num function...
    }
    else if(strcmp(input, "ADDNUM") == 0){
      cout << "What number to add?" << endl;
      cin >> inputValue;
      cout << "DEBUG: Current inputValue is " << inputValue << endl;
      ADDNUM(inputValue);
    }
    else if(strcmp, (input, "SEARCH") == 0){
      SEARCH(); //Figure out SEARCH function...
    }
    else if(strcmp(input, "QUIT") == 0){
      active = false;
    }
    else{
      cout << "Invalid Input" << endl;
    }
  }

  
  return 0;
}

void SORT_INPUT(Node* inputNode, Node* currNode){ //Top Down Sort (From Root)
  if(inputNode->returnValue = currNode->returnValue){ //Equal Case (Sorts Right | Right-Leaning Bias)
    currNode->makeRight(inputNode);
  }
  else if(inputNode->returnValue > currNode->returnValue){ //Greater Case (Check Right)
    if(currNode->returnRight == NULL){
      currNode->makeRight(inputNode);
    }
    else{
      currNode = currNode->returnRight;
      SORT_INPUT(inputNode, currNode);
    }
  }
  else if(inputNode->returnValue < currNode->returnValue){ //Less than Case (Check Left)
    if(currNode->returnLeft == NULL){
      currNode->makeLeft(inputNode)
    }
    else{
      currNode = currNode->returnRight;
      SORT_INPUT(inputNode, currNode);
    }
  }
  return;
}

void ADDNUM(int inputNum){
  Node* tempNode = new Node();
  tempNode->makeValue(inputNum);
  SORT_INPUT(tempNode, rootNode);
  return;
}

void PRINT(){
  return;
}

void SEARCH(){
  return;
}

void REMOVENUM(){
  return;
}
