//Heap
//Gordon Chen
//February 14th, 2024

#include <iostream>
#include <cstring>
#include <iomanip>
#incldue <fstream>

using namespace std;


void SORT(int array, int inputIndex);
void PRINT(int array, int maxIndex);
int REMOVE_ROOT([placeholder]);
void REMOVE_ALL_BY_ROOT([placeholder]);

int main(){
  int binTree[101];
  int currMax = 1;
  cout << "How would you like numbers to be added, manually (up to one hundred values from 1 to 1000) or with a file of 100 predetermined values?" << endl;
  cout << "Commands are as follows: MANUAL or FILE" << endl;
  cin >> input;
  if(strcmp(input, "MANUAL") == 0){
    cin.clear();
    cout << "How many numbers do you want to input? (100 MAX)" << endl;
    cin >> input;
    currMax = input;
    for (int i = 0; i < input; i++){
      cout << "Enter number: " << endl;
      cin >> num;
      binTree[i+1] = num;
      SORT(binTree, i+1);
    }
    cin.clear();
  }
  else if(strcmp(input, "FILE") == 0){
    currMax = 100;
    //PLACEHOLDER
  }
  return 0;
}

void SORT(int array, int inputIndex){
  int tempNum = 0;
  int parentIndex = 0;
  int temp_index = inputIndex;
  
  if(inputIndex % 2 = 1){
    temp_index = inputIndex - 1;
  }
  while(inputIndex > 1){
    parentIndex = temp_index/2;
    if(array[parentIndex] < array[inputIndex]){
      tempNum = array[parentIndex];
      array[parentIndex] = array[inputIndex];
      inputIndex = parentIndex;
      temp_index = inputIndex;
    }
    else(){
	cout << "Sorting Finished!" << endl;
	break;
      }
  }
  return;
}

void PRINT(int array, int currIndex){
  int evenIndex = 0;
  int parentIndex = 0;
  int treeLevel = 0;
  int tmpIndex = currIndex;

  while(currIndex >= 1){
    while(tmpIndex >= 1){
      if(tmpIndex % 2 = 1){
	evenIndex = tmpIndex - 1;
      }
      else(){
	  evenIndex = tmpIndex;
	}
      tmpIndex = evenIndex/2;
      treeLevel++;
    }
    cout << "Amount of tree levels (rows): " << treeLevel << endl;
    if(currIndex % 2 = 1){
       evenIndex = currIndex - 1;
    }
    else(){
	evenIndex = currIndex;
      }
     parentIndex = evenIndex/2;
   for(int i = 0; i < treeLevel; i++){
     cout << "\t";
   }
   cout << array[currIndex] << endl;
   currIndex = parentIndex;
  }
  return;
}
