#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"

using namespace std;

Student::Student(){ //To initialize

}

//Set functions
void Student::setID(int input_ID){
  ID = input_ID;
}

void Student::setGPA(float input_GPA){
  GPA = input_GPA;
}

//Get functions
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

//Print function
void Student::printStud(){
  cout << firstName << " " << lastName << " " << ID << " " << fixed << setprecision(3) << GPA << endl;
}
