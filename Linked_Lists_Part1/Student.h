#ifndef STUDENT_H
#defint STUDENT_H

#include <iostream>

using namespace std;

class Student{
 public:
  char* getFristName();
  char* getLastName();
  int getID();
  float getGPA();
  char firstName[101];
  char lastName[101];
  int ID;
  float GPA;
};

#endif
