//Gordon Chen
// 6/2/24
//Graph Creator

#include <iostream>
#include <cstring>
#include "vtex.h"

using namespace std;

//Function Prototypes

vtex* search(vtex** grid, char input, int indexCount); //Finds & returns pointer to requested Vertex
void print(vtex** grid, int indexCount); //Prints adjacency matrix
void dijkstra(vtex** grid, int indexCount); //Uses Dijkstra's algorithm to find the shortest/fastest/most efficient path
void addEdge(vtex** grid, int indexCount); //Adds Edge
void delEdge(vtex** grid, int indexCount); //Deletes Edge
void addVtex(vtex** grid, int indexCount); //Adds a vertex
void delVtex(vtex** grid, int indexCount); //Deletes a vertex

//definitions (for convenience) | Colors
//Resource used: https://gist.github.com/vratiu/9780109
//Use inspired by friends' githubs
#define RED "\033[31m"
#define BLUE "\033[34m"
#define COLOR_OFF "\033[0m"

int main(){ //main function
  vtex **grid = new vtex*[20];
  int indexCount = 0;
  bool active = true;
  char input[20];
  while(active){
    cout << endl;
    cout << "What would you like to do? COMMANDS: PRINT, FASTESTPATH, ADDEDGE, DELEDGE, ADDVERTEX, DELVERTEX, or QUIT?" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(999, '\n');
    if(strcmp(input, "PRINT") == 0){
      print(grid, indexCount);
    }
    else if(strcmp(input, "FASTESTPATH") == 0){
      dijkstra(grid, indexCount);
    }
    else if(strcmp(input, "ADDEDGE") == 0){
      addEdge(grid, indexCount);
    }
    else if(strcmp(input, "DELEDGE") == 0){
      delEdge(grid, indexCount);
    }
    else if(strcmp(input, "ADDVERTEX") == 0){
      addVtex(grid, indexCount);
      indexCount++;
    }
    else if(strcmp(input, "DELVERTEX") == 0){
      delVtex(grid, indexCount);
      indexCount--;
    }
    else if(strcmp(input, "QUIT") == 0){
      cout << "Program Quit" << endl;
      active = false;
    }
    else{
      cout << "Invalid Input" << endl;
    }
  }
}

vtex* search(vtex** grid, char input, int indexCount){
  int a = 0;
  while(a < indexCount){
    if((grid[a])->returnName() == input){
      return (grid[a]);
    }
    else{
      a++;
    }
  }
  return NULL; //DNE
}

void print(vtex** grid, int indexCount){ //Check over
  char matrix[21][21];
  for(int row = 0; row < 21; row++){    
    for(int column = 0; column < 21; column++){
      matrix[row][column] = ' '; //Empty Matrix
    }
  }
  
  //Pre-Printing Processing
  
  int edgeMatrix[20][20];
  int a = 0;
  while(a < indexCount){
    matrix[0][a+1] = (grid[a])->returnName();
    matrix[a+1][0] = (grid[a])->returnName();
    a++;
  }
  

  //Edge Output List
  for(int row = 0; row < indexCount; row++){
    vtex* tempR = grid[row];
    for(int column = 0; column < indexCount; column++){
      vtex* tempC = grid[column];
      if(tempR->returnEdge(tempC->returnIndex()) != 0){
	edgeMatrix[row][column] = 'T'; //True
      }
      else{
	edgeMatrix[row][column] = 'F'; //False
      }
    }
  }
  
  //edgeMatrix -> matrix
  for(int row = 0; row < indexCount; row++){
    for(int column = 0; column < indexCount; column++){
      matrix[row+1][column+1] = edgeMatrix[row][column];
    }
  }
  
  //PRINT ADJACENCY MATRIX
  for(int row = 0; row < 21; row++){
    for(int column = 0; column < 21; column++){
      if(column != 0 && row != 0 && matrix[row][column] == 'T'){
	cout << BLUE << matrix[row][column] << COLOR_OFF << '\t';
      }
      else if(column != 0 && row != 0 && matrix[row][column] == 'F'){
	cout << RED << matrix[row][column] << COLOR_OFF << '\t';
      }
      else{
	cout << matrix[row][column] << '\t';
      }
    }
    if(matrix[row+1][0] == ' '){ //Edge Case
      break;
    }
  }
}

void dijkstra(vtex** grid, int indexCount){
  if(grid[0] == NULL || grid[1] == NULL){ //Edge Case
    cout << "Less than two verticies" << endl;
    return;
  }
  char begin;
  char end;

  cout << "Enter Start Vertex" << endl;
  cin >> begin;
  cin.clear();
  cout << "Enter End Vertex" << endl;
  cin >> end;
  cin.clear();

  //Pre-Processing

  vtex* beginning = search(grid, begin, indexCount);
  vtex* ending = search(grid, end, indexCount);
  if(beginning == NULL || ending == NULL){
    cout << "Those verticies don't exist" << endl;
    return;
  }
  else{
    cout << "DEBUG 0" << endl;
    int tempinC = indexCount;
    int maximum = indexCount;
    int lim = 99; //Arbitrarily high value to function as infinity
    int pred[lim];
    int weight[lim][lim];
    int distance[lim];
    int history[lim];
    int count;
    int minDistance;
    int nextPos;
    int a;
    int b;
    cout << "DEBUG AGAIN" << endl;
    int startPos = beginning->returnIndex();
    cout << "START POS: " << startPos << endl;
    int endPos = ending->returnIndex();
    cout << "END POS: " << endPos << endl;
    cout << "VARIABLE DEBUG" << endl;
    for(a = 0; a < tempinC; a++){
      for(b = 0; b < tempinC; b++){
	if(grid[a]->returnEdge(b) == 0){
	  weight[a][b] = lim;
	}
	else{
	  weight[a][b] = grid[a]->returnEdge(b);
	}
      }
    }
    //Dijkstra's Algorithm

    for(a = 0; a < tempinC; a++){
      distance[a] = weight[startPos][a];
      pred[a] = startPos;
      history[a] = 0;
    }
    count = 1;
    history[startPos] = 1;
    distance[startPos] = 0;
    cout << "DEBUG 1" << endl;
    while(count < tempinC-1){
      minDistance = lim;
      for(a = 0; a < tempinC; a++){
	if(distance[a] < minDistance && !history[a]){
	  minDistance = distance[a];
	  nextPos = a;
	}
      }
      history[nextPos] = 1;
      cout << "DEBUG 2" << endl;
      for(a = 0; a < tempinC; a++){
	if(!history[a]){
	  if(minDistance + weight[nextPos][a] < distance[a]){
	    distance[a] = minDistance+weight[nextPos][a];
	    pred[a] = nextPos;
	  }
	}
      }
      count++;
    }
    //Print output

    cout << "DEBUG 3" << endl;
    for(a = 0; a < tempinC; a++){
      if(a == endPos){
	cout << "Weight/Distance: " << distance[a] << endl;
	cout << "Path: " << grid[a]->returnName();
	b = a;
	while(b != startPos){
	  b = pred[b];
	  cout << "<<--" << grid[b]->returnName();
	}
      }
    }
  }
}

void addEdge(vtex **grid, int indexCount){
  if(grid[1] == NULL || grid[0] == NULL){ //Two verticies check
    cout << "Need two verticies" << endl;
    return;
  }
  char in1;
  char in2;
  int num;
  cout << "Enter the first vertex this edge will be added to" << endl;
  cin >> in1;
  cin.clear();
  cout << "Now enter the second vertex" << endl;
  cin >> in2;
  cin.clear();
  //Pre-processing
  vtex* vertex1 = search(grid, in1, indexCount);
  vtex* vertex2 = search(grid, in2, indexCount);
  if(vertex1 == NULL || vertex2 == NULL){
    cout << "Verticies not found" << endl;
    return;
  }
  //Setting values
  cout << "What is the edge value?" << endl;
  cin >> num;
  cin.clear();
  vertex1->mkEdge(vertex2->returnIndex(), num);
  vertex2->mkEdge(vertex1->returnIndex(), num);
}

void delEdge(vtex** grid, int indexCount){
  if(grid[1] == NULL || grid[0] == NULL){ //Two verticies check
    cout << "Need two verticies" << endl;
    return;
  }
  char in1;
  char in2;
  cout << "Enter one of the vectors that is connected to this edge" << endl;
  cin >> in1;
  cin.clear();
  cout << "Enter the second vector" << endl;
  cin >> in2;
  cin.clear();
  //Pre-processing
  vtex* vertex1 = search(grid, in1, indexCount);
  vtex* vertex2 = search(grid, in2, indexCount);
  if(vertex1 == NULL || vertex2 == NULL){
    cout << "Verticies not found" << endl;
    return;
  }
  //Deletion
  vertex1->mkEdge(vertex2->returnIndex(), 0);
  vertex2->mkEdge(vertex1->returnIndex(), 0);
  cout << "EDGE DELETION FINISHED" << endl;
}

void addVtex(vtex** grid, int indexCount){
  char in;
  //Initilize new vertex
  vtex* newVtex = new vtex();
  newVtex->mkIndex(indexCount);
  cout << "Enter a character for the new vertex" << endl;
  cin >> in;
  cin.clear();
  newVtex->mkName(in);
  grid[indexCount] = newVtex;
  cout << "Vertex " << newVtex->returnName() << " added!" << endl; //Debugging purposes
}

void delVtex(vtex** grid, int indexCount){
  if(grid[0] == NULL){
    cout << "There are no verticies to delete" << endl;
    return;
  }
  char input;
  cout << "Enter the vertex to be deleted" << endl;
  cin >> input;
  cin.clear();
  vtex* vertex = search(grid, input, indexCount);
  if(vertex == NULL){
    cout << "No such vector exists" << endl;
    return;
  }
  int index = vertex->returnIndex();
  vertex->~vtex(); //Empty data
  cout << "DEBUG: Vertex Removed" << endl;
  //Stitching edge values per vertex
  for(int row = 0; row < indexCount; row++){
    vtex* curr = grid[row];
    for(int edge = index; edge < indexCount; edge++){
      if(edge == indexCount - 1){
	curr->mkEdge(edge, 0);
      }
      else{ //Iteration step
	int nextPos = edge+1;
	curr->mkEdge(edge, curr->returnEdge(nextPos));
      }
    }
    grid[row] = curr;
  }
  //Correct grid
  grid[index] = NULL;
  //Shift latter elements
  while(index < indexCount){
    if(index == indexCount - 1){
      grid[index] = NULL;
      break;
    }
    grid[index] = grid[index+1];
    (grid[index])->mkIndex(index);
    index++;
  }
  cout << "OVERALL DEBUG: VECTOR DELETION FULLY FINISHED" << endl;
}
