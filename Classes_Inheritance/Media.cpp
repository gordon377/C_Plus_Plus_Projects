#include <iostream>
#include "Media.h"
#include <cstring>

using namespace std;

Media::Media(){

  cout << "Enter the title: " << endl;
  cin >> title;
  cin.clear();
  cin.ignore(10000, '\n');
  cout << "Enter the year of release: (Not 0 & Numbers only)" << endl; //Could add a checker here
  cin >> year;
  cin.clear();
  cin.ignore(10000, '\n');
  
}

int Media::getYear(){
  return year;
}

char* Media::getTitle(){
  return title;
}

void Media::getInfo(){
  return;
}
