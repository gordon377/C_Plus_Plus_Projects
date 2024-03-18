//Binary Search Tree
//Gordon Chen
// March 18, 2024

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//Function Prototypes

void SORT_INPUT(int rootVal, Node* rootNode); //Input Value into tree properly (with respect to the root value)

int main(){

  char input[50];
  int numElements = 0;
  int rootNum = 0; //Root Value to reference

  cout << "Initial Number input method: MANUAL or FILE?" << endl;
  cin >> input;
  cin.clear();
  cin.ignore(10000, '\n');
  if(strcmp(input, "MANUAL") == 0){
    cout << "Input Root Value (First Input)" << endl; //Set root/begin tree
    cin >> rootNum;
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "How many additional numbers would you like to input?" << endl;
    cin >> numElements;
    numElements++;
    for (int i = 0; i < numElements-1; i++){
      cout << "Enter number: " << endl; //Continue to sort into tree
    }
  }

  
  return 0;
}
