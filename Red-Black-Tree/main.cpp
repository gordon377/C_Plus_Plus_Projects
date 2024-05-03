//Red-Black Tree
//Gordon Chen
//March 16, 2024

#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

using namespace std;

//Function Prototypes

void PRINT(Node* currNode, int count);
void SEARCH(Node* currNode, int inputNum);

//Insertion Prototypes
void BINARY_SORT_IN(Node* inputNode, Node* currNode);
void RED_BLACK_SORT_IN(Node* inputNode, Node* rootNode);
Node* FIND_UNCLE(Node* inputNode);
char CHILD_TYPE(Node* inputNode);


int main(){
  bool active = true;
  char input[50];
  int inputValue = 0;
  int count = 0;

  cout << "Input Root Value (Set Root Node)" << endl;
  cin >> inputValue;
  cin.clear();
  cin.ignore(10000, '\n');
  Node* rootNode = new Node();
  rootNode->makeValue(inputValue);

  cout << "How do you want to add the initial group of numbers? MANUAL or FILE?" << endl;
  cin >> input;
  cin.clear();
  cin.ignore(10000, '\n');
  if(strcmp(input, "MANUAL") == 0){
    cout << "How many additional numbers would you like to input?" << endl;
    cin >> inputValue;
    for(int i = 0; i < inputValue; i++){
      cout << "Enter number: " << endl;
      cin >> inputValue;
      cin.clear();
      cin.ignore(10000, '\n');
      Node* tempNode = new Node();
      tempNode->makeValue(inputValue);
      BINARY_SORT_IN(tempNode, rootNode);
      RED_BLACK_SORT_IN(tempNode, rootNode);
    }
  }
  else if(strcmp(input, "FILE") == 0){
    ifstream fin("Numbers.txt");
    while(fin>>inputValue){
      Node* tempNode = new Node();
      tempNode->makeValue(inputValue);
      BINARY_SORT_IN(tempNode, rootNode);
      RED_BLACK_SORT_IN(tempNode, rootNode);
    }
  }

  cout << "DEBUG: INITIAL INSERTIONS FINISHED" << endl;

  //Automatically print (for now)
  PRINT(rootNode, count); 

  return 0;
}


//Defining Functions

//SET PARENTS

void BINARY_SORT_IN(Node* inputNode, Node* currNode){ //Top Down Sort (From Root)
  if(inputNode->returnValue() == currNode->returnValue() && currNode->returnRight() != NULL){ //Equal Case (Sorts Right | Right-Leaning Bias)
    inputNode->makeParent(currNode);
    inputNode->makeRight(currNode->returnRight());
    currNode->makeRight(inputNode);
  }
  else if(inputNode->returnValue() > currNode->returnValue()){ //Greater Case (Check Right)
    if(currNode->returnRight() == NULL){
      inputNode->makeParent(currNode);
      currNode->makeRight(inputNode);
    }
    else{
      currNode = currNode->returnRight();
      BINARY_SORT_IN(inputNode, currNode);
    }
  }
  else if(inputNode->returnValue() < currNode->returnValue()){ //Less than Case (Check Left)
    if(currNode->returnLeft() == NULL){
      inputNode->makeParent(currNode);
      currNode->makeLeft(inputNode);
    }
    else{
      currNode = currNode->returnLeft();
      BINARY_SORT_IN(inputNode, currNode);
    }
  }
  return;
}

void PRINT(Node* currNode, int count){ //Visually print binary tree
  if(currNode->returnRight() != NULL){ //Check Right
    PRINT(currNode->returnRight(), count+1);
  }
  for(int i = 0; i < count; i++){ //Tabs (tree level)
    cout << '\t';
  }
  cout << currNode->returnValue(); //Output (Numeric and Red/Black Value)
  if(currNode->returnRed() == true){
    cout << " (RED)" << endl;
  }
  else if(currNode->returnRed() == false){
    cout << " (BLACK)" << endl;
  }
  if(currNode->returnLeft() != NULL){ //Check Left
    PRINT(currNode->returnLeft(), count+1);
  }
  return;
}

void SEARCH(Node* currNode, int inputNum){
  return;
}

Node* FIND_UNCLE(Node* inputNode){
  if(inputNode->returnParent()->returnParent()->returnLeft() == inputNode && inputNode->returnParent()->returnParent()->returnRight() != NULL){
    return inputNode->returnParent()->returnParent()->returnRight();
  }
  else if(inputNode->returnParent()->returnParent()->returnRight() == inputNode && inputNode->returnParent()->returnParent()->returnLeft() != NULL){
    return inputNode->returnParent()->returnParent()->returnLeft();
  }
  else{
    return NULL;
  }
}

char CHILD_TYPE(Node* inputNode){
  if(inputNode->returnParent()->returnLeft() == inputNode){
    return 'L';
  }
  else if(inputNode->returnParent()->returnRight() == inputNode){
    return 'R';
  }
  else{
    cout << "CHILD_TYPE ERROR" << endl;
  }
}

void ROTATE_LEFT(Node* inputNode){
  return;
}

void ROTATE_RIGHT(Node* inputNode){
  return;
}

void RED_BLACK_SORT_IN(Node* inputNode, Node* rootNode){
  Node* UNCLE = FIND_UNCLE(inputNode);
  //Checking which of four cases
  if(inputNode == rootNode){
    inputNode->recolor(); //Recolor Node to Black
  }
  else if(UNCLE->returnRed() == true){
    inputNode->returnParent()->recolor();
    inputNode->returnParent()->returnParent()->recolor();
    UNCLE->recolor();
  }
  else if((UNCLE->returnRed() == false || UNCLE == NULL) && CHILD_TYPE(inputNode) != CHILD_TYPE(inputNode->returnParent())){
    if(CHILD_TYPE(inputNode) == 'L'){
      ROTATE_RIGHT(inputNode->returnParent());
    }
    else if(CHILD_TYPE(inputNode) == 'R'){
      ROTATE_LEFT(inputNode->returnParent());
    }
  }
  else if((UNCLE->returnRed() == false || UNCLE == NULL) && CHILD_TYPE(inputNode) == CHILD_TYPE(inputNode->returnParent())){
    //Storing original parent and grandparent pointers
    Node* PARENT = inputNode->returnParent();
    Node* GRANDPARENT = inputNode->returnParent()->returnParent();

    if(CHILD_TYPE(inputNode) == 'L'){
      ROTATE_RIGHT(inputNode->returnParent()->returnParent());
    }
    else if(CHILD_TYPE(inputNode) == 'R'){
      ROTATE_LEFT(inputNode->returnParent()->returnParent());
    }

    PARENT->recolor();
    GRANDPARENT->recolor();
  }
  return;
}
