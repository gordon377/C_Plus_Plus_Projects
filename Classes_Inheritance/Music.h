//Define Music Class Structure

#ifndef MUSIC
#define MUSIC

#include <iostream>
#include "Media.h"

using namespace std;

class Music : public Media{
 public:
  Music(); //Main function of the class (don't have to declare a return type | Function usually defined in a .cpp file
  char artist[80];
  char publisher[80];
  int duration = 0;
  void Info();

};

#endif
