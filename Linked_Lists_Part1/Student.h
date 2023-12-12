#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student{
 public:
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
  char firstName[101];
  char lastName[101];
  int ID;
  float GPA;
};

#endif
