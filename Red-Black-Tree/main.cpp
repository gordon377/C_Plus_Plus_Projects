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
void RED_BLACK_SORT_IN(Node* inputNode);


int main(){
  bool active = true;
  char input[50];
  int inputValue = 0;

  cout << "Input Root Value (Set Root Node)" << endl;
  cin >> inputValue;
  cin.clear();
  cin.ignore(10000, '\n');
  Node* rootNode = new Node();
  rootNode->recolor(); //Set Node to black
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
      RED_BLACK_SORT_IN(tempNode);
    }
  }
  else if(strcmp(input, "FILE") == 0){
    ifstream fin("Numbers.txt");
    while(fin>>inputValue){
      Node* tempNode = new Node();
      tempNode->makeValue(inputValue);
      BINARY_SORT_IN(tempNode, rootNode);
      RED_BLACK_SORT_IN(tempNode);
    }
  }

  cout << "DEBUG: INITIAL INSERTIONS FINISHED" << endl;

  return 0;
}


//Defining Functions

void BINARY_SORT_IN(Node* inputNode, Node* currNode){ //Top Down Sort (From Root)
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

//CONTINUE FROM HERE (Adjust print so that it prints out red or black value)

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
