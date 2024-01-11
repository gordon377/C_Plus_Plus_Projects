#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student{
 public:
  Student();

  //(Public) Variables
  char firstName[101];
  char lastName[101];
  int ID;
  float GPA;

  //Set functions
  void setID(int input_ID);
  void setGPA(float input_GPA);
  
  //Get functions
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();

  //Print function
  void printStud();

};
#endif
