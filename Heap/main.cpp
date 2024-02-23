//Heap
//Gordon Chen
//February 14th, 2024

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;


void SORT_INPUT(int array[101], int inputIndex); //Down to top sort
void SORT_REMOVEROOT(int array[101], int inputIndex); //Top down sort
void PRINT(int array[101], int rootIndex, int count, int maxIndex);
void REMOVE_ROOT(int array[101], int &maxIndex); //Removes Root and Outputs it while taking the end index value and placing at the top (root index), before sorting it again | (Instructions say to reduce table size by one, but this function will instead set the value of the right most indext or the swapped index with NULL)

int main(){
  int currMax = 0;
  char input[20];
  int num = 0;
  int num2 = 0;
  int size = 100;
  bool active = true;
  int binTree[101];
  
  cout << "How would you like numbers to be added, manually (up to one hundred values from 1 to 1000) or with a file of 100 predetermined values?" << endl;
  cout << "Commands are as follows: MANUAL or FILE" << endl;
  cin >> input;
  if(strcmp(input, "MANUAL") == 0){
    cin.clear();
    cout << "How many numbers do you want to input? (100 MAX)" << endl;
    cin >> num;
    currMax = num;
    cin.clear();
    cout << "currMax: " << currMax << endl;
    for (int i = 0; i < num; i++){
      cout << "Enter number: " << endl;
      cin >> num2;
      binTree[i+1] = num2;
      SORT_INPUT(binTree, i+1);
    }
    cin.clear();
  }
  else if(strcmp(input, "FILE") == 0){
    cin.clear();
    currMax = 100;
    cout << "currMax: " << currMax << endl;
    ifstream fin("Numbers.txt");
    int tmpValue = 0;
    int index = 0;
    while(fin >> tmpValue){
      index++;
      binTree[index] = tmpValue;
      SORT_INPUT(binTree, index);
    }
    cout << "DEBUG: FILE NUMBERS LOADED" << endl;
  }
  while(active){
    cout << "currMax: " << currMax << endl;
  cout << "\n What would you like to do next? (PRINT, REMOVEROOT, REMOVEREMAININGROOTS, QUIT)" << endl;
  cin >> input;
  if(strcmp(input, "PRINT") == 0){
    PRINT(binTree, 1, 0, currMax);
    cout << endl;
  }
  else if(strcmp(input, "REMOVEROOT") == 0){
    cout << "Root: ";
    cout <<  "currMax: " << currMax << endl;
    REMOVE_ROOT(binTree, currMax);
    cout << endl;
  }
  else if(strcmp(input, "REMOVEREMAININGROOTS") == 0){
    cout << "currMax: " << currMax << endl; //CURR MAX IS SOMEHOW 0 HERE??? BUT ONLY WHEN THE BELOW LOOP IS ACTIVE/THERE???
    cout << "Remaining roots: ";

    int tmpMax = currMax;

    for(int i = 0; i < tmpMax; i++){
      REMOVE_ROOT(binTree, currMax);\
      cout << ", ";
    }
    
    REMOVE_ROOT(binTree, currMax);
    cout << endl;
    //active = false;
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

void SORT_INPUT(int array[101], int inputIndex){ //Note: Arrays are automatically passed by referenced due to the deferencing of square brackets, so the '&' dereferencing symbol isn't necessarily needed
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
  int tempNum = 0;
  int childIndex = inputIndex*2; //childIndex initialized as left child
  
  while(array[inputIndex] < array[childIndex] || array[inputIndex] < array[childIndex+1]){
    if(array[childIndex] >= array[childIndex+1] && array[inputIndex] < array[childIndex]){ //Slightly biased to sorting to the left side of the tree]
      tempNum = array[inputIndex];
      array[inputIndex] = array[childIndex];
      array[childIndex] = tempNum;
      inputIndex = childIndex;
      childIndex = inputIndex*2;
    }
    else if(array[childIndex] <= array[childIndex+1] && array[inputIndex] < array[childIndex+1]){
      tempNum = array[inputIndex];
      array[inputIndex] = array[childIndex+1];
      array[childIndex+1] = tempNum;
      inputIndex = childIndex+1;
      childIndex = inputIndex*2;
    }
  }
}

void REMOVE_ROOT(int array[101], int &maxIndex){
  cout << array[1];
  array[1] = array[maxIndex];
  array[maxIndex] = -1;
  maxIndex--;
  SORT_REMOVEROOT(array, 1);
}

void PRINT(int array[101], int rootIndex, int count, int maxIndex){
  if((rootIndex*2)+1<maxIndex){
    PRINT(array, ((rootIndex*2)+1), count+1, maxIndex);
  }
  for(int i = 0; i < count; i++){
    cout << '\t';
  }
  cout << array[rootIndex] << endl;
  if((rootIndex*2)<maxIndex){
    PRINT(array, (rootIndex*2), count+1, maxIndex);
  }
  return;
}

