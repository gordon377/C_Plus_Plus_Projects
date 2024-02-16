//Heap
//Gordon Chen
//February 14th, 2024

#include <iostream>
#include <cstring>
#include <iomanip>
#incldue <fstream>

using namespace std;


void SORT(int array, int inputIndex);

int main(){
  int binTree[101];
  int currMax = 1;
  cout << "How would you like numbers to be added, manually (up to one hundred values from 1 to 1000) or with a file of 100 predetermined values?" << endl;
  cout << "Commands are as follows: MANUAL or FILE" << endl;
  cin >> input;
  if(strcmp(input, "MANUAL") == 0){
    for (int i = 0; i < 100; i++){
      cout << "Enter number: " << endl;
      cin >> num;
      binTree[i+1] = num;
      SORT(binTree, i);
    }
  }
  return 0;
}

void SORT(int array, int inputIndex){
  while (inputIndex >= 1){
    if(index % 2 = 1){
      index--;
    }
    int parentIndex = inputIndex/2;
    if(array[parentIndex] < array[inputIndex]){
      int tempNum = array[parentIndex];
      array[parentIndex] = array[inputIndex];
      array[inputIndex] = tempNum;
      inputIndex = parentIndex;
    }
    else(){
	break;
      }
  }
  return;
}

