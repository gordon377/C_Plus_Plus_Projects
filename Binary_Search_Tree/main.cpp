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
bool SEARCH(Node* currNode, int inputNum);



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
      cout << "What number to check for?" << endl;
      cin >> inputValue;
      SEARCH(rootNode, inputValue); //Figure out SEARCH function...
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
  if(inputNode->returnValue() = currNode->returnValue()){ //Equal Case (Sorts Right | Right-Leaning Bias)
    currNode->makeRight(inputNode);
  }
  else if(inputNode->returnValue() > currNode->returnValue()){ //Greater Case (Check Right)
    if(currNode->returnRight() == NULL){
      currNode->makeRight(inputNode);
    }
    else{
      currNode = currNode->returnRight();
      SORT_INPUT(inputNode, currNode);
    }
  }
  else if(inputNode->returnValue() < currNode->returnValue()){ //Less than Case (Check Left)
    if(currNode->returnLeft == NULL){
      currNode->makeLeft(inputNode)
    }
    else{
      currNode = currNode->returnRight();
      SORT_INPUT(inputNode, currNode);
    }
  }
  return;
}

void ADDNUM(int inputNum){ //Add number to binary tree
  Node* tempNode = new Node();
  tempNode->makeValue(inputNum);
  SORT_INPUT(tempNode, rootNode);
  return;
}

void PRINT(){ //Visually print binary tree
  return;
}

void SEARCH(Node* currNode, int inputNum){ //Check if number is in binary tree
  if(currNode->returnValue() == inputNum){ //Matching Case
    cout << "That number is in the binary tree" << endl;
    return;
  }
  else if(currNode->returnValue() < inputNum){ //Input is greater than current node value
    if(currNode->returnRight() == NULL){ //No match
      cout << "That number is not in the binary tree" << endl;
      return;
    }
    else(){ //Go right and continue searching
	currNode = currNode->returnRight();
	SEARCH(currNode, inputNum);
      }
  }
  else if(currNode->returnValue() > inputNum){ //Input is less than current node value
    if(currNode->returnLeft() == NULL){
      cout << "That number is not in the binary tree" << endl;
      return;
    }
    else(){ //Go left and continue searching
	currNode = currNode->returnLeft();
	SEARCH(currNode, inputNum);
      }
  }
}

void REMOVENUM(Node* currNode, int inputNum){ //Essentially SEARCH() with a removing function
  bool numsRemoved = false;
  while(numsRemoved == false){

    
  if(currNode->returnRight()->returnValue() == inputNum){ //Matching Case on Right Side | Remove & Resort
    if(currNode->returnRight()->rightRight() == NULL && currNode->returnRight()->returnLeft() == NULL){ //No children case
      delete currNode->returnRight();
      currNode->makeRight(NULL);
    }
    else if(currNode->returnRight()->returnRight() == NULL && currNode->returnRight()->returnLeft() != NULL){//One child case (Var 1)
      Node* tempNode = new Node();
      tempNode = currNode;
      currNode->makeRight(currNode->returnRight()->returnLeft());
      delete tempNode->returnRight();
    }
    else if(currNode->returnRight()->returnRight() != NULL && currNode->returnRight()->returnLeft() == NULL){//One child case (Var 2)
      Node* tempNode = new Node();
      tempNode = currNode;
      currNode->makeRight(currNode->returnRight()->returnRight());
      delete tempNode->returnRight();
    }
    else if(currNode->returnRight()->returnRight() != NULL && currNode->returnRight()->returnLeft() != NULL){ //Two children case
      bool nullFound = false;
      Node* tempNode = new Node();
      tempNode = currNode->returnRight()->returnRight();
      Node* tempReplacementNode = new Node();
      while(nullFound == false){ //Iterate until reach a left most NULL | temp node becomes the parent the left most non-Null Node
	if(tempNode->returnLeft()->returnLeft() == NULL){ //How to delete the left most non-Null?
	  nullFound = true;
	}
	else(){
	    tempNode = tempNode->returnLeft;
	  }
      }

      //Reordering/Restructuring tree | Replacing deleted position with node of right once left all the way
      
      tempReplacementNode = tempNode->returnLeft();
      tempReplacementNode->makeRight(currNode->returnRight()->returnRight());
      tempReplacementNode->makeLeft(currNode->returnRight()->returnLeft());
      tempNode->makeLeft(NULL);
      delete currNode->returnRight();
      currNode->makeRight(tempReplacementNode);
      
    }

  }
  
  } //End of while loop
}
