//Gordon Chen
//Classes & Inheritance
//November 8th 2023

#include <iostream>
#include <cstring>
#include <vector>
#include "Movies.h"
#include "Music.h"
#include "VideoGames.h"
#include "Media.h"

using namespace std;

//prototypes
void ADD(vector<Media*>* datatable);
void DELETE(vector<Media*>* datatable);
void SEARCH(vector<Media*>* datatable);

int main(){
  bool continue = true;
  char input[81];
  vector<Media*>* datatable = new vector<Media*>();
  cout << "Enter of command: (ADD, SEARCH, DELETE, or QUIT | Case Sensitive)" << endl;
  cin >> input; //Do I need to cin.clear and cin.ignore here?


  if(!strcmp(input
  
}
