#include <iostream>
#include "Student.h"

using namespace std;

char* Student::getFirstName(){
  return firstName;
}

char* Student::getLastName(){
  return lastName;
}

int Student::getID(){
  return ID;
}

float Student::getGPA(){
  return GPA;
}
