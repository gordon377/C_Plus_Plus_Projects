//Gordon Chen
// 6/2/24
//Graph Creator

#include <iostream>
#include <cstring>
#include "vtex.h"

using namespace std;

//Function Prototypes

vtex* search(vtex** grid, char input, int indexCount); //Finds & returns pointer to requested Vertex
void print(vtex** grid, int indexCount); //Prints
void dijkstra(vtex** grid, int indexCount); //Uses Dijkstra's algorithm to find the shortest/fastest/most efficient path
void addEdge(vtex** grid, int indexCount); //Adds Edge
void delEdge(vtex** grid, int indexCount); //Deletes Edge
void addVtex(vtex** grid, int indexCount); //Adds a vertex
void delVtex(vtex** grid, int indexCount); //Deletes a vertex

//definitions (for convenience) | Colors
//Resource used: https://gist.github.com/vratiu/9780109

#define RED "\033[31m"
#define BLUE "\033[34m"
#define COLOR_OFF "\033[0m"

int main(){ //main function
  vtex **grid = new vtex*[20];
  int indexCount = 0;
  bool active = true;
  char input[20];
  while(active){
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
  
}
