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
Node* SEARCH(Node* currNode, int inputNum);

//Insertion-Related Prototypes
void BINARY_SORT_IN(Node* inputNode, Node* currNode);
void RED_BLACK_SORT_IN(Node* inputNode, Node* &rootNode);
Node* FIND_UNCLE(Node* inputNode);
char CHILD_TYPE(Node* inputNode);
void ROTATE_LEFT(Node* inputNode);
void ROTATE_RIGHT(Node* inputNode);


int main(){
  bool active = true;
  char input[50];
  int inputValue = 0;
  int manualCount = 0;
  int count = 0;

  cout << "Input Root Value (Set Root Node)" << endl;
  cin >> inputValue;
  cin.clear();
  cin.ignore(10000, '\n');
  Node* rootNode = new Node();
  rootNode->makeValue(inputValue);
  rootNode->recolor(); //Set root to black

  cout << "How do you want to add the initial group of numbers? MANUAL or FILE?" << endl;
  cin >> input;
  cin.clear();
  cin.ignore(10000, '\n');
  if(strcmp(input, "MANUAL") == 0){
    RED_BLACK_SORT_IN(rootNode, rootNode);
    cout << "How many additional numbers would you like to input?" << endl;
    cin >> manualCount;
    for(int i = 0; i < manualCount; i++){
      cout << "Enter number: " << endl;
      cin >> inputValue;
      cin.clear();
      cin.ignore(10000, '\n');
      Node* tempNode = new Node();
      tempNode->makeValue(inputValue);
      BINARY_SORT_IN(tempNode, rootNode);
      if(tempNode->returnParent() == NULL){ //Didn't Activate, therefore parent value must be assigned...
	cout << "NO PARENT" << endl;
      }
      cout << "------------PRE RED BLACK SORT PRINT--------------" << endl;
      PRINT(rootNode, count);
      RED_BLACK_SORT_IN(tempNode, rootNode);
      cout << "------------POST RED BLACK SORT PRINT-------------" << endl;
      PRINT(rootNode, count);
    }
  }
  else if(strcmp(input, "FILE") == 0){
    ifstream fin("numbers-short.txt");
    while(fin>>inputValue){
      Node* tempNode = new Node();
      tempNode->makeValue(inputValue);
      BINARY_SORT_IN(tempNode, rootNode);
      cout << "------------PRE RED BLACK SORT PRINT--------------" << endl;
      PRINT(rootNode, count);
      RED_BLACK_SORT_IN(tempNode, rootNode);
      cout << "------------POST RED BLACK SORT PRINT-------------" << endl;
      PRINT(rootNode, count);
    }
  }

  cout << "DEBUG: INITIAL INSERTIONS FINISHED" << endl;
  cout << "------------------FINAL INSERTION PRINT-------------------" << endl;
  
  PRINT(rootNode, count);

  cout << "------------------FINAL INSERTION PRINT FINISHED---------------------" << endl;


  while(active){
    cout << "\n Enter one of the following commands: PRINT, ADDNUM, REMOVENUM, SEARCH, QUIT" << endl;
    cin >> input;
    if(strcmp(input, "PRINT") == 0){
      PRINT(rootNode, count);
      cout << "DEBUG: PRINT FINISHED" << endl;
    }
    else if(strcmp(input, "ADDNUM") == 0){
      cout << "What number to add?" << endl;
      cin >> inputValue;
      cin.clear();
      cin.ignore(10000, '\n');
      Node* tempNode = new Node();
      tempNode->makeValue(inputValue);
      BINARY_SORT_IN(tempNode, rootNode);
      RED_BLACK_SORT_IN(tempNode, rootNode);
      cout << "Number added!" << endl;
    }
    else if(strcmp(input, "SEARCH") == 0){
      cout << "What number to check for?" << endl;
      cin >> inputValue;
      if(SEARCH(rootNode, inputValue) != NULL){
	cout << "That number is in the tree!" << endl;
      }
      else{
	cout << "That number is not in the tree!" << endl;

      }
    }
    else if(strcmp(input, "REMOVENUM") == 0){
      cout << "What number/value to remove?" << endl;
      cin >> inputValue;
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "WORK IN PROGRESS" << endl;
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


//Defining Functions

//SET PARENTS

void BINARY_SORT_IN(Node* inputNode, Node* currNode){ //Top Down Sort (From Root)
  if(inputNode->returnValue() == currNode->returnValue()){ //Equal Case (Sorts Right | Right-Leaning Bias)
    inputNode->makeParent(currNode);
    inputNode->makeRight(currNode->returnRight());
    if(currNode->returnRight() != NULL){
      currNode->returnRight()->makeParent(inputNode);
    }
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

Node* SEARCH(Node* currNode, int inputNum){
  if(currNode->returnValue() == inputNum){
    return currNode;
  }
  else if(currNode->returnValue() < inputNum){
    if(currNode->returnRight() == NULL){
      return NULL;
    }
    else{
      currNode = currNode->returnRight();
      SEARCH(currNode, inputNum);
    }
  }
  else if(currNode->returnValue() > inputNum){
    if(currNode->returnLeft() == NULL){
      return NULL;
    }
    else{
      currNode = currNode->returnLeft();
      SEARCH(currNode, inputNum);
    }
  }
}


Node* FIND_UNCLE(Node* inputNode){
  if(inputNode->returnParent() == NULL){
    return inputNode;
  }
  if(inputNode->returnParent()->returnParent() != NULL){
    if(inputNode->returnParent() == inputNode->returnParent()->returnParent()->returnLeft()){
      return inputNode->returnParent()->returnParent()->returnRight();
    }
    else if(inputNode->returnParent() == inputNode->returnParent()->returnParent()->returnRight()){
      return inputNode->returnParent()->returnParent()->returnLeft();
    }
    else{
      return NULL;
    }
  }
  else{
    return NULL;
  }
}

char CHILD_TYPE(Node* inputNode){ //Requires Parent to Exist to work...
  if(inputNode->returnParent() == NULL){
    cout << "Child_Type Check: Parent Doesn't Exist" << endl;
    return 'E';
  }
  else if(inputNode->returnParent()->returnLeft() == inputNode){
    return 'L';
  }
  else if(inputNode->returnParent()->returnRight() == inputNode){
    return 'R';
  }
  else{
    cout << "CHILD_TYPE ERROR" << endl;
    return 'E';
  }
}

void ROTATE_LEFT(Node* inputNode){ //This might work? Check over again. CONTINUE HERE
  //Input Node's parent might be NULL.....
  cout << "LEFT ROTATE ACTIVATED" << endl;
  Node* tmpParent = inputNode->returnParent(); //Original Parent
  Node* tmpRChild = inputNode->returnRight(); //Original Right Child
  if(CHILD_TYPE(inputNode) == 'L' && tmpParent != NULL){
    tmpParent->makeLeft(inputNode->returnRight());
  }
  else if(CHILD_TYPE(inputNode) == 'R' && tmpParent != NULL){
    tmpParent->makeRight(inputNode->returnRight());
  }
  else if(tmpParent == NULL){
    tmpRChild->makeParent(NULL);
  }
  
  inputNode->makeParent(tmpRChild);
  cout << "STEP 1 Finished" << endl;
  
  if(tmpRChild != NULL){
    cout << "STEP 2 (tmpRChild Exists)" << endl;
    inputNode->makeRight(tmpRChild->returnLeft());
    cout << "STEP 3" << endl;
    if(tmpRChild->returnLeft() != NULL){
      tmpRChild->returnLeft()->makeParent(inputNode);
    }
    cout << "STEP 4" << endl;
    tmpRChild->makeLeft(inputNode);
    cout << "STEP 5" << endl;
    if(tmpParent != NULL){
      tmpRChild->makeParent(tmpParent);
    }
  }

  return;
}

void ROTATE_RIGHT(Node* inputNode){
  cout << "RIGHT ROTATE ACTIVATED" << endl;
  Node* tmpParent = inputNode->returnParent(); //Original Parent
  Node* tmpLChild = inputNode->returnLeft(); //Original Left Child

  if(CHILD_TYPE(inputNode) == 'L' && tmpParent != NULL){
    tmpParent->makeLeft(inputNode->returnLeft());
  }
  else if(CHILD_TYPE(inputNode) == 'R' && tmpParent != NULL){
    tmpParent->makeRight(inputNode->returnLeft());
  }
  else if(tmpParent == NULL){
    tmpLChild->makeParent(NULL);
  }

  inputNode->makeParent(tmpLChild);
  cout << "STEP 1 Finished" << endl;

  if(tmpLChild != NULL){
    cout << "STEP 2 (tmpLChild Exists)" << endl;
    inputNode->makeLeft(tmpLChild->returnRight());
    cout << "STEP 3" << endl;
    if(tmpLChild->returnRight() != NULL){
      tmpLChild->returnRight()->makeParent(inputNode);
    }
    cout << "STEP 4" << endl;
    tmpLChild->makeRight(inputNode);
    cout << "STEP 5" << endl;
    if(tmpParent != NULL){
      tmpLChild->makeParent(tmpParent);
    }
  }
  return;
}

void RED_BLACK_SORT_IN(Node* inputNode, Node* &rootNode){
  if(inputNode->returnParent() != NULL){
    if(inputNode->returnParent()->returnRed() == true){
 
  Node* UNCLE = FIND_UNCLE(inputNode); //UNCLE could be NULL... || If inputNode == ROOT, UNCLE is inputNode
  //Checking which of four cases
  if(inputNode == rootNode && inputNode->returnRed() == true){ //Input is root
    inputNode->recolor(); //Recolor Node to Black
  }
  else if((UNCLE != inputNode) && (inputNode->returnParent() != NULL) && (UNCLE == NULL || UNCLE->returnRed() == false) && (CHILD_TYPE(inputNode) != CHILD_TYPE(inputNode->returnParent())) && (inputNode->returnParent()->returnParent() != NULL)){ //Uncle is Black or NULL & in Triangle formation with input

    cout << "Black Uncle Triangle Case" << endl;
    cout << "inputNode Child Type: " << CHILD_TYPE(inputNode) << endl;
    cout << "Parent Node Child Type: " << CHILD_TYPE(inputNode->returnParent()) << endl;


    Node* PARENT = inputNode->returnParent(); //Original Parent
    
    if(CHILD_TYPE(inputNode) == 'L'){
      ROTATE_RIGHT(inputNode->returnParent());
      if(inputNode->returnRight()->returnRed() == true){
	RED_BLACK_SORT_IN(inputNode->returnRight(), rootNode);
      }
    }
    else if(CHILD_TYPE(inputNode) == 'R'){
      ROTATE_LEFT(inputNode->returnParent());
      if(inputNode->returnLeft()->returnRed() == true){
	RED_BLACK_SORT_IN(inputNode->returnLeft(), rootNode);
      }
    }
    if(PARENT == rootNode){
      rootNode = inputNode;
    }
  }
  else if((UNCLE != inputNode) && (UNCLE == NULL || UNCLE->returnRed() == false) && (inputNode->returnParent() != NULL) && (inputNode->returnParent()->returnParent() != NULL) && (CHILD_TYPE(inputNode) == CHILD_TYPE(inputNode->returnParent()))){ //Uncle is Black or NULL & is in a Line formation with input
    //If statement should guaratnee there is a non-NULL grandparent

    cout << "Black Uncle Line Case" << endl;

    //Storing original parent and grandparent
    Node* PARENT = inputNode->returnParent();
    Node* GRANDPARENT = PARENT->returnParent();

    if(PARENT == NULL){
      cout << "DEBUG: NULL PARENT" << endl;
    }

    cout << "inputNode Child Type: " << CHILD_TYPE(inputNode) << endl;

    if(CHILD_TYPE(inputNode) == 'L'){
      ROTATE_RIGHT(inputNode->returnParent()->returnParent());
    }
    else if(CHILD_TYPE(inputNode) == 'R'){
      ROTATE_LEFT(inputNode->returnParent()->returnParent());
    }

    if(GRANDPARENT == rootNode){
      rootNode = PARENT;
    }

    cout << "Rotations Finished" << endl;
    
    PARENT->recolor();
    if(GRANDPARENT != NULL){
      GRANDPARENT->recolor();
    }
  }
  else if((UNCLE != inputNode) && (UNCLE != NULL)){
    if(UNCLE->returnRed() == true){ //Uncle is Red
      cout << "Red Uncle Case" << endl;
      if(inputNode->returnParent()->returnParent() != rootNode){ //Is a subtree (GRANDPARENT isn't the Root Node)
	inputNode->returnParent()->recolor();
	inputNode->returnParent()->returnParent()->recolor();
	UNCLE->recolor();
      }
      else if(inputNode->returnParent()->returnParent() == rootNode){ //Is not a subtree (GRANDPARENT is the Root Node)
	inputNode->returnParent()->recolor();
	UNCLE->recolor();
      }
      if(inputNode->returnParent()->returnParent() != rootNode && inputNode->returnParent()->returnParent()->returnRed() == true){
	if(inputNode->returnParent()->returnParent()->returnParent()->returnRed() == true){
	  RED_BLACK_SORT_IN(inputNode->returnParent()->returnParent(), rootNode);
	}
      }
    }
  }
  }
  }
  else{
    cout << "No Case Fit" << endl;
  }

  return;
}
