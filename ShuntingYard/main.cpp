#include <iostream>
#incluyde <cstring>
#include "node.h"

using namespace std;

//Function Prototypes here


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
}
