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

//Tree Prototypes
void treePush(Node*& tree, Node*& space);
void treePop(Node*& tree);

void printInfix(Node* InfixExp);
void printPostfix(Node* PostfixExp);
void printPrefix(Node* PrefixExp);


int main(){
  bool active = true;
  //char instruction[50];
  char inputValue[101];

  Node* top = NULL; //Top node in STACK
  Node* front = NULL; //Front node of QUEUE
  Node* back = NULL; //Back aka Rear node of QUEUE

  cout << "DEBUG: Variables loaded | Shunting Yard Started" << endl;

  while(active){
    cout << "This is a calculator. Please input the expression to calculate in infix notation (Spaces between each number and operator)" << endl;
    cin.get(inputValue, 101);
    cin.ignore(9999, '\n');
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
  cout << top->returnValue << endl;
  Node* tempNode = top; 
  top  = top->returnNext();
  tempNode->makeNext(NULL); //Precautions for tempNode
}

Node* peek(Node* top){ 

}



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

