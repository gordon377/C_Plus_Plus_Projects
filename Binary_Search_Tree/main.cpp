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
void PRINT(Node* currNode, int count);
void REMOVENUM(Node* currNode, int inputNum); //To remove a nodes of a certain num
void ADDNUM(Node* inputNum, Node* root);
void SEARCH(Node* currNode, int inputNum);



int main(){
  bool active = true;
  char input[50];
  int numElements = 0;
  int count = 0;
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
    while(fin >> inputValue){
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
      PRINT(rootNode, count); //Figure out print function...
      cout << "DEBUG: PRINT FINISHED" << endl;
    }
    else if(strcmp(input, "REMOVENUM") == 0){
      cout << "What value/number would you like to remove?" << endl;
      cin >> inputValue;
      cin.clear();
      cin.ignore(10000, '\n');
      REMOVENUM(rootNode, inputValue); //Figure out remove num function...
      cout << "Debug: Number Removed" << endl;
    }
    else if(strcmp(input, "ADDNUM") == 0){
      cout << "What number to add?" << endl;
      cin >> inputValue;
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "DEBUG: Current inputValue is " << inputValue << endl;
      Node* tempNode = new Node();
      tempNode->makeValue(inputValue);
      ADDNUM(tempNode, rootNode);
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
  if(inputNode->returnValue() == currNode->returnValue() && currNode->returnRight() != NULL){ //Equal Case (Sorts Right | Right-Leaning Bias)
    inputNode->makeRight(currNode->returnRight());
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
    if(currNode->returnLeft() == NULL){
      currNode->makeLeft(inputNode);
    }
    else{
      currNode = currNode->returnLeft();
      SORT_INPUT(inputNode, currNode);
    }
  }
  return;
}

void ADDNUM(Node* inputNum, Node* root){ //Add number to binary tree
  SORT_INPUT(inputNum, root);
  return;
}

void PRINT(Node* currNode, int count){ //Visually print binary tree
  if(currNode->returnRight() != NULL){ //Check Right
    PRINT(currNode->returnRight(), count+1);
  }
  for(int i = 0; i < count; i++){ //Tabs (tree level)
    cout << '\t';
  }
  cout << currNode->returnValue() << endl;
  if(currNode->returnLeft() != NULL){ //Check Left
    PRINT(currNode->returnLeft(), count+1); 
  }
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
    else{ //Go right and continue searching
	currNode = currNode->returnRight();
	SEARCH(currNode, inputNum);
      }
  }
  else if(currNode->returnValue() > inputNum){ //Input is less than current node value
    if(currNode->returnLeft() == NULL){
      cout << "That number is not in the binary tree" << endl;
      return;
    }
    else{ //Go left and continue searching
	currNode = currNode->returnLeft();
	SEARCH(currNode, inputNum);
      }
  }
}

void REMOVENUM(Node* currNode, int inputNum){ //Essentially SEARCH() with a removing function
  bool numsRemoved = false;
  while(numsRemoved == false){
    if(currNode == NULL){ //Iterated all the way until currNode was set to a NULL (end of tree)
      numsRemoved = true;
      break;
    }
    if(inputNum >= currNode->returnValue()){ //Input num is greater than current node value
      if(currNode->returnRight()->returnValue() == inputNum){ //Matching Case on Right Side | Remove & Resort
	if(currNode->returnRight()->returnRight() == NULL && currNode->returnRight()->returnLeft() == NULL){ //No children case
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
	  Node* beforeTemp = new Node();
	  while(nullFound == false){ //Iterate until reach a left most NULL from deleted position but shifted once to the right | temp node becomes the left most non-Null Node
	    if(tempNode->returnLeft() == NULL){
	      nullFound = true;
	    }
	    else{
	      beforeTemp = tempNode;
	      tempNode = tempNode->returnLeft();
	      }
	  }
	  //Reordering/Restructuring tree | Replacing deleted position with node of right once left all the way
	  currNode->returnRight()->makeValue(tempNode->returnValue());
	  beforeTemp->makeLeft(tempNode->returnRight());
	  delete tempNode;
	  break;
	}
      }
      else{ //Iterate right (input > currNode Value case)
	currNode = currNode->returnRight();
	}
    }
    else if(inputNum <= currNode->returnValue()){ //Input num is less than current node value
      if(currNode->returnLeft()->returnValue() == inputNum){ //Matching Case on Left Side | Remove & Resort
	if(currNode->returnLeft()->returnRight() == NULL && currNode->returnRight()->returnLeft() == NULL){ //No children case
	  delete currNode->returnLeft();
	  currNode->makeLeft(NULL);
	}
	else if(currNode->returnLeft()->returnRight() == NULL && currNode->returnLeft()->returnLeft() != NULL){ //One child case (Var 1)
	  Node* tempNode = new Node();
	  tempNode = currNode;
	  currNode->makeLeft(currNode->returnLeft()->returnLeft());
	  delete tempNode->returnLeft();
	}
	else if(currNode->returnLeft()->returnRight() != NULL && currNode->returnLeft()->returnRight() == NULL){ //One child case (Var 2)
	  Node* tempNode = new Node();
	  tempNode = currNode;
	  currNode->makeRight(currNode->returnLeft()->returnRight());
	  delete tempNode->returnLeft();
	}
	else if(currNode->returnLeft()->returnRight() != NULL && currNode->returnLeft()->returnLeft() != NULL){ //Two children case
	  bool nullFound = false;
	  Node* tempNode = new Node();
	  tempNode = currNode->returnLeft()->returnRight();
	  Node* tempReplacementNode = new Node();
	  Node* beforeTemp = new Node();
	  while(nullFound == false){ //Iterate until reach left most NULL from deleted position but shifted once to the right | temp node becomes the left most non-Null Node
	    if(tempNode->returnLeft() == NULL){
	      nullFound = true;
	    }
	    else{
	      beforeTemp = tempNode;
	      tempNode = tempNode->returnLeft();
	      }
	  }
	  //Reordering/Restructuring tree | Replacing deleted position node value with value of node of right once left all the way, then doing some clean-up connection work
	  currNode->returnLeft()->makeValue(tempNode->returnValue());
	  beforeTemp->makeLeft(tempNode->returnRight());
	  delete tempNode;
	  break;
	  }
	}
      else{ //Iterate left (input < currNode Value case)
	  currNode = currNode->returnLeft();
	}
      }
  } //End of while loop
  return;
} //End of REMOVENUM function 

