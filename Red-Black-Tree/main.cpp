//Red-Black Tree
//Gordon Chen
//March 16, 2024

#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

using namespace std;

//Function Prototypes

void PRINT(Node* currNode, int count, Node* rootNode, bool &active);
Node* SEARCH(Node* currNode, int inputNum);

//Insertion-Related Prototypes
void BINARY_SORT_IN(Node* inputNode, Node* currNode);
void RED_BLACK_SORT_IN(Node* inputNode, Node* &rootNode);
Node* FIND_UNCLE(Node* inputNode);
char CHILD_TYPE(Node* inputNode);
void ROTATE_LEFT(Node* inputNode);
void ROTATE_RIGHT(Node* inputNode);

//Deletion-Related Prototypes
Node* FIND_IN_ORDER_SUCCESSOR(Node* N); //Finds the left most child of the right subtree
Node* FIND_SIBLING(Node* N);
Node* FIND_CLOSE_NEPHEW(Node* N);
Node* FIND_DISTANT_NEPHEW(Node* N); //Might be useful to have a find parent as well?
Node* FIND_PARENT(Node* N); //Added for the sake of consistency

void EVAL_RELATIONS(Node* N, Node* & S, Node* & C, Node* & D, Node* & P);

void D1(Node* & rootNode);

void D2(Node* N, Node* S, Node* C, Node* D, Node* P, Node* & rootNode);

void D3(Node* N, Node* S, Node* C, Node* D, Node* P);

void D4(Node* N, Node* S, Node* C, Node* D, Node* P);

void D5(Node* N, Node* & S, Node* & C, Node* & D, Node* & P);

void D6(Node* N, Node* S, Node* C, Node* D, Node* P);

void DELETE_REARRANGE(Node* N, Node* & rootNode);
void DELETE_STITCH_UP(Node* N);


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
      PRINT(rootNode, count, rootNode, active);
      RED_BLACK_SORT_IN(tempNode, rootNode);
      cout << "------------POST RED BLACK SORT PRINT-------------" << endl;
      PRINT(rootNode, count, rootNode, active);
    }
  }
  else if(strcmp(input, "FILE") == 0){
    ifstream fin("numbers-short.txt");
    while(fin>>inputValue){
      Node* tempNode = new Node();
      tempNode->makeValue(inputValue);
      BINARY_SORT_IN(tempNode, rootNode);
      cout << "------------PRE RED BLACK SORT PRINT--------------" << endl;
      PRINT(rootNode, count, rootNode, active);
      RED_BLACK_SORT_IN(tempNode, rootNode);
      cout << "------------POST RED BLACK SORT PRINT-------------" << endl;
      PRINT(rootNode, count, rootNode, active);
    }
  }

  cout << "DEBUG: INITIAL INSERTIONS FINISHED" << endl;
  cout << "------------------FINAL INSERTION PRINT-------------------" << endl;
  
  PRINT(rootNode, count, rootNode, active);

  cout << "------------------FINAL INSERTION PRINT FINISHED---------------------" << endl;


  while(active){
    cout << "\n Enter one of the following commands: PRINT, ADDNUM, REMOVENUM, SEARCH, QUIT" << endl;
    cin >> input;
    if(strcmp(input, "PRINT") == 0){
      PRINT(rootNode, count, rootNode, active);
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
      if(SEARCH(rootNode, inputValue) != NULL){
	DELETE_REARRANGE(SEARCH(rootNode, inputValue), rootNode);
	//DELETE_STITCH_UP(SEARCH(rootNode, inputValue)); Instead, stitch up manually?
	cout << "DELETION COMPLETED" << endl;
      }
      else{
	cout << "That value isn't in the tree to begin with!" << endl;
      }
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

void PRINT(Node* currNode, int count, Node* rootNode, bool &active){ //Visually print binary tree
  if(rootNode == NULL){
    cout << "Empty tree! Run the Program Again Remake the Tree" << endl;
    active = false;
    return;
  }
  else{
    if(currNode->returnRight() != NULL){ //Check Right
      PRINT(currNode->returnRight(), count+1, rootNode, active);
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
      PRINT(currNode->returnLeft(), count+1, rootNode, active);
    }
    return;
  }
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

Node* FIND_SIBLING(Node* N){
  if(N->returnParent() == NULL){
    return NULL;
  }
  if(CHILD_TYPE(N) == 'L'){
    return N->returnParent()->returnRight();
  }
  else if(CHILD_TYPE(N) == 'R'){
    return N->returnParent()->returnLeft();
  }
  else{
    return NULL;
  }
}

Node* FIND_CLOSE_NEPHEW(Node* N){
  if(CHILD_TYPE(N) == 'L' && FIND_SIBLING(N) != NULL){
    return FIND_SIBLING(N)->returnLeft();
  }
  else if(CHILD_TYPE(N) == 'R' && FIND_SIBLING(N) != NULL){
    return FIND_SIBLING(N)->returnRight();
  }
  else{
    return NULL;
  }
}

Node* FIND_DISTANT_NEPHEW(Node* N){
  if(CHILD_TYPE(N) == 'L' && FIND_SIBLING(N) != NULL){
    return FIND_SIBLING(N)->returnRight();
  }
  else if(CHILD_TYPE(N) == 'R' && FIND_SIBLING(N) != NULL){
    return FIND_SIBLING(N)->returnLeft();
  }
  else{
    return NULL;
  }
}

Node* FIND_PARENT(Node* N){
  return N->returnParent();
}

void EVAL_RELATIONS(Node* N, Node* & C, Node* & D, Node* & S, Node* & P){
  P = FIND_PARENT(N);
  S = FIND_SIBLING(N);
  C = FIND_CLOSE_NEPHEW(N);
  D = FIND_DISTANT_NEPHEW(N);
  return;
}

void D1(Node* &rootNode){
  cout << "DEBUG: N is Root | Tree No Longer Exists" << endl;
  rootNode = NULL;
  return;
}

void D2(Node* N, Node* S, Node* C, Node* D, Node* P, Node* & rootNode){
  S->recolor();
  cout << "DEBUG 1" << endl;
  N = P;
  cout << "DEBUG 2" << endl;
  EVAL_RELATIONS(N, S, C, D, P);
  cout << "DEBUG 3" << endl;
  //Continue from here (loop) in main Delete function (recheck cases & check if N becomes NULL)
  if(S != NULL){
    cout << S->returnValue() << endl;
    DELETE_REARRANGE(N, rootNode);
  }
  return;
}

void D3(Node* N, Node* S, Node* C, Node* D, Node* P){
  if(CHILD_TYPE(N) == 'L'){
    ROTATE_LEFT(P);
  }
  else if(CHILD_TYPE(N) == 'R'){
    ROTATE_RIGHT(P);
  }
  P->recolor();
  S->recolor();
  if(D != NULL && D->returnRed() == true){
    D6(N, S, C, D, P);
  }
  else if(C != NULL && C->returnRed() == true){
    D5(N, S, C, D, P);
  }
  else{ //What is C & D are NULL?
    D4(N, S, C, D, P);
  }
  return;
}

void D4(Node* N, Node* S, Node* C, Node* D, Node* P){
  if(S->returnRed() != P->returnRed()){
    S->recolor();
    P->recolor();
  }
  return;
}

void D5(Node* N, Node* & S, Node* & C, Node* & D, Node* & P){
  if(CHILD_TYPE(S) == 'L'){
    ROTATE_LEFT(S);
  }
  else if(CHILD_TYPE(S) == 'R'){
    ROTATE_RIGHT(S);
  }
  if(S->returnRed() != C->returnRed()){
    S->recolor();
    C->recolor();
  }
  EVAL_RELATIONS(N, S, C, D, P);
  D6(N, S, C, D, P);
  return;
}

void D6(Node* N, Node* S, Node* C, Node* D, Node* P){
  if(CHILD_TYPE(N) == 'L'){
    ROTATE_LEFT(P);
  }
  else if(CHILD_TYPE(N) == 'R'){
    ROTATE_RIGHT(P);
  }
  if(S->returnRed() != P->returnRed()){
    S->recolor();
    P->recolor();
  }
  D->recolor(); //D is now set to black
  return;
}

Node* FIND_IN_ORDER_SUCCESSOR(Node* N){
  Node* currNode = N->returnRight();
  while(currNode->returnLeft() != NULL){
    currNode = currNode->returnLeft();
  }
  return currNode;
}

void DELETE_REARRANGE(Node* N, Node* & rootNode){ //I'm less deleting the data, more cutting the node out of the tree, is this valid?
  cout << "DELETION_REARRANGE STARTED" << endl;
  Node* S = FIND_SIBLING(N);
  Node* C = FIND_CLOSE_NEPHEW(N);
  Node* D = FIND_DISTANT_NEPHEW(N);
  Node* P = FIND_PARENT(N);
  
  if(N->returnLeft() != NULL && N->returnRight() != NULL){ //Case 0 | N has two non-NULL children | Verified
    cout << "ENTER DELETION CASE 0" << endl;
    Node* tempNode = FIND_IN_ORDER_SUCCESSOR(N);
    cout << tempNode->returnValue() << endl;
    N->makeValue(tempNode->returnValue());
    if(tempNode->returnRight() == NULL && tempNode != N->returnRight()){
      tempNode->returnParent()->makeLeft(NULL);
      return;
    }
    else if(tempNode == N->returnRight() && tempNode->returnRight() == NULL){
      N->makeRight(NULL);
    }
    else{
      tempNode->returnParent()->makeLeft(tempNode->returnRight());
      tempNode->returnRight()->makeParent(tempNode->returnParent());
    }
    return;
  }
  else if((N->returnLeft() != NULL && N->returnRight() == NULL) || (N->returnLeft() == NULL && N->returnRight() != NULL)){ //Case 1 | N has only one non-NULL child | Verified
    cout << "ENTER DELETION CASE 1" << endl;
    Node* tempNode = new Node();
    if(N->returnLeft() != NULL){
      tempNode = N->returnLeft();
    }
    else if(N->returnRight() != NULL){
      tempNode = N->returnRight();
    }
    if(CHILD_TYPE(N) == 'L'){
      P->makeLeft(tempNode);
    }
    else if(CHILD_TYPE(N) == 'R'){
      P->makeRight(tempNode);
    }
    tempNode->makeParent(P);
    tempNode->recolor(); //Color Child Black
  }
  else if(P == NULL && N->returnRight() == NULL && N->returnLeft() == NULL){ //Case 2 | N is root & has no children | Verified
    cout << "ENTER DELETION CASE 2" << endl;
    rootNode = NULL; //Tree is now functionally empty
    return;
  }
  else if(N->returnRed() == true && N->returnRight() == NULL && N->returnLeft() == NULL){ //Case 3 | N is red & has no children | Verified
    cout << "ENTER DELETION CASE 3" << endl;
    if(CHILD_TYPE(N) == 'L'){
      P->makeLeft(NULL);
    }
    else if(CHILD_TYPE(N) == 'R'){
      P->makeRight(NULL);
    }
    N->makeParent(NULL);
    return;
  }
  else if(N->returnRed() == false && N->returnRight() == NULL && N->returnLeft() == NULL){ //Case 4 (Complex Case) | N is black & has no children (Black Leaf)
    cout << "ENTER DELETION CASE 4" << endl;
    if(CHILD_TYPE(N) == 'L'){
      P->makeLeft(NULL);
    }
    else if(CHILD_TYPE(N) == 'R'){
      P->makeRight(NULL);
    }
    if(P == NULL){ //Case D1 | P, C, S, & D don't exist (N is root) | Already covered by Case 2...
      cout << "ENTER D1" << endl;
      D1(rootNode);
    }
    //What if S == NULL... || S is guaranteed to exist due to red black properties?
    else if((P->returnRed() == false && S->returnRed() == false) && ((C == NULL && D == NULL) || (C->returnRed() == false && D->returnRed() == false))){ //Case D2 | P, S, C, & D are black
      cout << "ENTER D2" << endl;
      D2(N, S, C, D, P, rootNode);
    }
    else if(S->returnRed() == true){ //Case D3 | S is red, therfore P, C, & D are black
      cout << "ENTER D3" << endl;
      D3(N, S, C, D, P);
    }
    else if(S->returnRed() == false && C->returnRed() == false && D->returnRed() == false && P->returnRed() == true){ //Case D4 | P is red & S, C, & D are black
      cout << "ENTER D4" << endl;
      D4(N, S, C, D, P);
    }
    else if(S->returnRed() == false && C->returnRed() == true && D->returnRed() == false){ //Case D5 | S is black, C is red, & D is black
      cout << "ENTER D5" << endl;
      D5(N, S, C, D, P);
    }
    else if(S->returnRed() == false && D->returnRed() == true){ //Case D6 | S is black & D is red
      cout << "ENTER D6" << endl;
      D6(N, S, C, D, P);
    }
    else{
      cout << "DEBUG: ERROR | COMPLEX DELETION CASE" << endl;
    }
  }
}

void DELETE_STITCH_UP(Node* N){
  cout << "DELETE_STITCH_UP STARTED" << endl;
  if(N->returnParent() == NULL){
    cout << "DEBUG: DELETE_STITCH_UP | NO PARENT" << endl;
    return;
  }
  if(CHILD_TYPE(N) == 'L'){
    N->returnParent()->makeLeft(NULL);
  }
  else if(CHILD_TYPE(N) == 'R'){
    N->returnParent()->makeRight(NULL);
  }
  else{
    cout << "DEBUG: DELETE_STITCH_UP | ERROR" << endl;
  }
  return;
}


