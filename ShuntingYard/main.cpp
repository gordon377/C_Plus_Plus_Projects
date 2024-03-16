#include <iostream>
#incluyde <cstring>
#include "node.h"

using namespace std;

//Function Prototypes here


//Order Prototype
int order(char* o); //Checks the operator and assigns a number to denote the order in which the expression should be evaluated

//Stack Prototypes
void push(Node*& top, char* inputVal); //Add new value to top of stack
void pop(Node*& top); //Return & Remove top node
Node* peek(Node* top); //Return top node only

//Queue Prototypes
void enqueue(Node*& front, Node*& back, char* inputVal); //Add new value to back of queue 
void dequeue(Node*& front, Node*& back); //Output & Remove Value at front of the queue
bool queueEmpty(Node* front, Node* back); //Check if queue is empty
void printQueue(Node* front, Node* back); //Print out queue for debugging
void outFront(Node* front, Node* back); //Output front element value

//Tree Prototypes
void treePush(Node*& tree, Node*& placeholder);
void treePop(Node*& tree);

void printInfix(Node* InfixExp);
void printPostfix(Node* PostfixExp);
void printPrefix(Node* PrefixExp);


int main(){
  bool active = true;
  char inputValue[101];

  Node* top = NULL; //Top node in STACK
  Node* front = NULL; //Front node of QUEUE
  Node* back = NULL; //Back aka Rear node of QUEUE

  cout << "DEBUG: Variables loaded | Shunting Yard Started" << endl;

  while(active){
    cout << "This is a calculator. Please input the expression to calculate in infix notation (Spaces between each number and operator)" << endl;
    cin.get(inputValue, 101);
    cin.ignore(9999, '\n');
    char** extraTemp = new char* [100];
    //Set initial values for Everything
    int charCount = 0; //Chars before a space
    int inputLength = 0; //Number of chars pointers in extraTemp
    top = NULL;
    front = NULL;
    back = NULL;
    for (int i = 0; i< strlen(input); i++){
      if(inputValue[i] == ‘ ‘){ //If space
        if(charCount == 1){
          char* tempChar = new char[15];
          for(int num = 0; num < sizeof(temp); num++){
            tempChar[num] = 0;
          }
          tempChar[0] = inputValue[i -1];
          extraTemp[inputLength] = tempChar;
          inputLength++;
          charCount = 0;
        }
        else{
          char* tempChar = new char[15];
          for(int num = 0; num < sizeof(tempChar); num++){
            tempChar[num] = 0;
          }
          for (int num = 0; num < 1; num++){
            tempChar[num] = inputValue[i + num - 1];
          }
          extraTemp[inputLength] = tempChar;
          inputLength++;
          charCount = 0;
        }
      }
      else{
        char* tempChar = new char[15];
        for (int num = 0; num < sizeof(tempChar); num++){
          tempChar[num] = 0;
        }
        charCount++;
        if(i == strlen(inputValue) -1){
          for (int num = 0; num < 1; num++){
            tempChar[num] = inputValue[i+num+charCount+1];
          }
          extraTemp[inputLength] = tempChar;
          inputLength++;
        }
      }
    }
    cout << “Expression Inputted: “ << endl;
    for (int num = 0; num < inputLength; num++){
      cout << extraTemp[num] << “Order: “ << order(extraTemp[num]) << endl;
    }
    int shuntCount = 0; //Tracks the current element
    while (shuntCount < inputCount){ //Shunting Yard Algorithm
      if(order(extraTemp[shuntCount]) == 0){ //If input element is a num
        enqueue(front, back, extraTemp[shuntCount]);
      }
      if (order(extraTemp[shuntCount]) == 3 || order(extraTemp[shuntCount]) == 2 || order(extraTemp[shuntCount]) == 1){ //If input element is an operator
        if (top != NULL) {
          while (order(top->returnValue()) >= order(extraTemp[shuntCount]) && *top->returnValue() != ‘(‘){
            //pop stack & enqueue
            enqueue(front, back, top->returnValue());
            pop(top);
            if(top == NULL){
              break;
            }
          }
        }
        push(top, extraTemp[shuntCount]); //Transfer to stack
      }
      if (*extraTemp[shuntCount] == ‘(‘){ //If value is left parenthesis
        push(top, extraTemp[shuntCount]); //Transfer to stack
      }
      if (*extraTemp[shuntCount] == ‘)’) { //If value is right parenthesis
        while (*top->returnData() != ‘(‘) {
          enqueue(front, back, top->returnValue());
          pop(top);
        }
        if (*top->returnData() == ‘(‘){
          pop(top);
        }
      }
      shuntCount++;; 
    }
    if (shuntCount == inputLength_ {
      while(top != NULL){
        enqueue(front, back, top->returnValue());
        pop(top;
      }
    }
    cout << “Expression Tree: “ << endl;

  }





  

  return 0;
} //main function end

//Function Definitions

//Stack Function Definitions

void push(node*& top, char* inputVal){ //Adds new value to top of stack
  Node* tempNode = new Node();
  tempNode->makeValue(inputVal);
  tempNode->makeNext(top);
  top = tempNode; 
}

void pop(Node*& top){ //Outputs & Removes the top element
  if (top == NULL){
    cout << “NULL Stack” << endl;
  }
  else {
    cout << top->returnValue << endl;
    Node* tempNode = top; 
    top  = top->returnNext();
    tempNode->makeNext(NULL); //Precautions for tempNode
  }
}

Node* peek(Node* top){ //Only outputs top element (For debugging purposes)
  if(top == NULL){
    cout << “NULL Stack” << endl;
    Node* nullPlaceholder = new Node();
  return nullPlaceholder;
  }
  else{
    return top;
  }
}

//Order Function Definition (Order of Operations)
//Higher return value = Higher priority in order
int order(char* o){
  if(*o == ‘+’ || *o == ‘-’){
    return 1;
  }
  else if(*o == ‘*’ || *o == ‘/’){
    return 2;
  }
  else if(*o == ‘^’){ //No root functionality added
    return 3;
  }
  else if(*o == ‘(’ || *o == ‘)’){ //Highest Priority (Parenthesis | Returned number must be highest)
    return 10;
  }
  else { //Character must be a pure number
    return 0;
  }
}

//Queue Function Definitions

void printQueue(Node* front, Node* back) {
  if(queueEmpty(front, back)){
     cout << “NULL Queue” << endl;
  }
  else {
    Node* tempNode = front;
    while(tempNode != NULL){
      cout << tempNode->returnValue() << “ “;
      tempNode = tempNode->returnNext();
    }
    cout << endl;
  }
}

void outFront(Node* front, Node* back){
  if(queueEmpty(front, back)){
     cout << “NULL Queue” << endl;
  }
  else {
    cout << front->returnValue();
  }
}

bool queueEmpty(Node* front, Node* back){ //Empty Queue Checker
  if (front != NULL && back != NULL){
    return false;
  }
  else {
    return false;
  }
}

void enqueue(Node*& front, Node*& back, char* inputVal){ //Add value to end of queue
  Node* tempNode = new Node();
  tempNode->makeValue(inputVal);
  tempNode->makeNext(NULL);
  if (front == NULL){ //When there are no nodes (first input case)
    front = tempNode;
    back = tempNode;
  }
  else{
    back->makeNext(tempNode);
    back = tempNode;
  }
}

void dequeue(Node*& front, Node*& back){ //Output & Remove Element at Front of Queue
  if(queueEmpty(front, back)){
    cout << “NULL Queue” << endl;
  }
  else if (front == back) { //One node case
    back == NULL;
    front == NULL;
    //Manual delete final node
  }
  else{
    Node* tempNode = front;
    front = front->returnNext();
    temp->makeNext(NULL);
  }
}

//Tree Function Definitions

void treePop(Node*& tree){
  if(tree == NULL){ //Check if tree is empty
    cout << “NULL Tree” << endl;
  }
  else{
    Node* tempNode = tree;
    tree = tree->returnNext();
    tempNode->makeNext(NULL);
  }  
}

void treePush(Node*& tree, Node*& placeholder){
  if(tree == NULL){ //First tree input case
    placeholder->makeNext(tree);
    tree = placeholder;
  }
  else {
    if (order(placeholder->returnValue()) == 0) { //If a raw number\
      placeholder->makeNext(tree);
      tree = placeholder;
    }
    else{ //If value is not a number (is an operator)
      Node* left = tree;
      treePop(tree);
      left->makeNext(NULL);
      Node* right = tree;
      treePop(tree);
      right->makeNext(NULL);
      tree = placeholder;
      tree->makeRight(right);
      tree->makeLeft(left);
    }
  }
}

//Printing Tree Function Definitions

void printPostfix(Node* PostfixExp){
  if(PostfixExp != NULL){ //Print Expression in Postfix Notation from Expression Tree
    printPostfix(PostfixExp->returnLeft());
    printPostfix(PostfixExp->returnRight());
    cout << PostFixExp->returnValue() << “ “;
  }
}

void printPrefix(Node* PrefixExp){ //Print Expression in Prefix Notation from Expression Tree
  if(PrefixExp != NULL) {
    cout << PrefixExp->returnValue() << “ “;
    printPrefix(PrefixExp->returnLeft());
    printPrefix(PrefixExp->returnRight());
  }
}

void printInfix(Node* InfixExp){ //Print Expression in Infix Notation from Expression Tree
  if(InfixExp != NULL) {
    if(order(InfixExp->returnValue()) != 0){ //If an operator
      cout << “( “;
    }
    printInfix(InfixExp->returnLeft());
    cout << InfixExp->returnValue() << “ “;
    printInfix(InfixExp->returnRight());
    if (order(InfixExp->returnValue()) != 0){ //If an operator
      cout << “) “;
    }
  }
}

