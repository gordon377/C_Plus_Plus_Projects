//Heap
//Gordon Chen
//February 14th, 2024

#include <iostream>
#include <cstring>
#include <iomanip>
#incldue <fstream> 

using namespace std;


void SORT_INPUT(int array[101], int inputIndex); //Down to top sort
void SORT_REMOVEROOT(int array[101], int inputIndex); //Top down sort
void PRINT(int array[101], int rootIndex, int count, int maxIndex);
int REMOVE_ROOT([placeholder]); //Removes Root and Outputs it while taking the end index value and placing at the top (root index), before sorting it again

int main(){
  int binTree[101];
  int currMax = 0;
  cout << "How would you like numbers to be added, manually (up to one hundred values from 1 to 1000) or with a file of 100 predetermined values?" << endl;
  cout << "Commands are as follows: MANUAL or FILE" << endl;
  cin >> input;
  if(strcmp(input, "MANUAL") == 0){
    cout << "How many numbers do you want to input? (100 MAX)" << endl;
    cin >> input;
    currMax = input;
    for (int i = 0; i < input; i++){
      cout << "Enter number: " << endl;
      cin >> num;
      binTree[i+1] = num;
      SORT_INPUT(binTree, i+1);
    }
    cin.clear();
  }
  else if(strcmp(input, "FILE") == 0){
    cin.clear();
    currMax = 100;
    ifstream fin("Numbers.txt");
    int tmpValue = 0;
    int index = 0
    while(fin >> tmpValue;){
      index++;
      binTree[index] = tmpValue;
      SORT_INPUT(binTree, index);
    }
    cout << "DEBUG: FILE NUMBERS LOADED" << endl;
  }
  cout << "What would you like to do next? (PRINT, REMOVEROOT, REMOVEALL)" << endl;
  cin >> input;
  if(strcmp(input, "PRINT") == 0){
    PRINT(binTree, 1, 0, currMax);
  }
  else if(strcmp(input, "REMOVEROOT") == 0){
    //[PLACEHOLDER]
  }
  return 0;
}

void SORT_INPUT(int &array[101], int inputIndex){ //Note: Arrays are automatically passed by referenced due to the deferencing of square brackets, so the '&' dereferencing symbol isn't necessarily needed
  int tempNum = 0;
  int parentIndex = floor(inputIndex/2);

  while(array[inputIndex] > array[parentIndex]){
    tempNum = array[parentIndex];
    array[parentIndex] = array[inputIndex];
    array[inputIndex] = tempNum;
    inputIndex = parentIndex;
    parentIndex = floor(inputIndex/2);
  }
  return;
}

void SORT_REMOVEROOT(int array[101], int inputIndex){
  
}

void PRINT(int array[101], int rootIndex, int count, int maxIndex){
  if((rootIndex*2)+1<maxIndex){
    PRINT((rootIndex*2)+1, count+1, maxIndex);
  }
  for(int i = 0; i < count; i++){
    cout << '\t';
  }
  cout << array[index] << maxIndex;
  if((rootIndex*2)<maxIndex){
    PRINT((rootIndex*2), count+1, maxIndex);
  }
  return;
}

