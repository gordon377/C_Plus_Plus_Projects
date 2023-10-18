//Student List
//Gordon Chen
//October 11th, 2023

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Student {

  char first_name[81];
  char last_name[81];
  int id;
  float gpa;

};

void ADD(vector <Student*> &svect);
void PRINT(vector <Student*> &svect);
void DELETE(vector <Student*> &svect);
void QUIT();

int main(){

  vector <Student*> svect; //Initialize vector of pointers in the form of the Student structure

  char input[20]; //Function choice input
  cout << "Type ADD, PRINT, DELETE, or QUIT (case sensitive) to interact with this student list" << endl;
  cin >> input;
  if(strcmp(input, "ADD") == 0){
    ADD(vector <Student*> &svect);
  } 
  
  return 0;
}

void ADD(vector <Student*> &svect) {

  Student* s = new Student();
  cout << "Enter the Student's first name: " << endl;
  cin >> s->first_name; //Same as (*s).first_name | Dots are first in C++ order of operations
  cout << "Enter the Student's last name: " << endl;
  cin >> s->last_name;
  cout << "Enter the Student's ID: " << endl;
  cin >> s->id;
  cout << "Enter the Student's GPA: " << endl;
  cin >> s->gpa;

  svect.pushback(s);

}

void PRINT(vector <Student*> &svect) {

  vector<int>::iterator ptr;
  for(ptr = vect.begin(); ptr < vect.end(); ptr++){
    cout  << "Name: " << (*ptr)->first_name << " " << (*ptr)->last_name << endl;
    cout << "ID: " << (*ptr)->id << endl;
    cout << "GPA: " << fixed << setprecision(2) << (*ptr)->gpa << endl;
  }
  
}

void DELETE(vector <Student*> &svect) {

}

void QUIT() {

}
