//Student List
//Gordon Chen
//October 11th, 2023

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

struct Student { //Define Student structure

  char first_name[81];
  char last_name[81];
  int id;
  float gpa;

};

//function prototypes

void ADD(vector <Student*> &svect);
void PRINT(vector <Student*> &svect);
void DELETE(vector <Student*> &svect);

int main(){

  vector <Student*> svect; //Initialize vector of pointers in the form of the Student structure

  char input[20]; //Function choice input
  bool end = false; //Continue condition
  while(end == false){ //Loops while end == false
    
    cout << "Type ADD, PRINT, DELETE, or QUIT (case sensitive) to interact with this student list" << endl;
    cin >> input; //Take in command
    if(strcmp(input, "ADD") == 0){  //Calling function corresponding to requested command
      ADD(svect);
    }
    else if(strcmp(input, "PRINT") == 0){
      PRINT(svect);
    }
    else if(strcmp(input, "DELETE") == 0){
      DELETE(svect);
    }
    else if(strcmp(input, "QUIT") ==0){
	end = true;
      }
    else{

      cout << "Invalid input (case sensisitve commands)" << endl;  //Other case
      
    }
  
  }
  
  return 0;
}

void ADD(vector <Student*> &svect) { //Adding new student with info

  Student* s = new Student(); //Create new variable of student structure (new is called to keep the information for longer/on the heap)
  cout << "Enter the Student's first name: " << endl;
  cin >> s->first_name; //Same as (*s).first_name | Dots are first in C++ order of operations
  cout << "Enter the Student's last name: " << endl;
  cin >> s->last_name;
  cout << "Enter the Student's ID: " << endl; //Taking in student info
  cin >> s->id;
  cout << "Enter the Student's GPA: " << endl;
  cin >> s->gpa;

  svect.push_back(s); //Pushing information back to vector

}

void PRINT(vector <Student*> &svect) { //Printing stored student data

  vector<Student*>::iterator ptr = svect.begin(); //initialize iterator | (iterator returns pointers) | "ptr" (variable name) is a ptr to a specific value in the vector (in this case points to a specific student list ptr in the vector)
  for(ptr; ptr < svect.end(); ptr++){
    cout  << "Name: " << (*ptr)->first_name << " " << (*ptr)->last_name << endl;
    cout << "ID: " << (*ptr)->id << endl;
    cout << "GPA: " << fixed << setprecision(2) << (*ptr)->gpa << endl; //Precisiion fixed to two decimals
  }
  
}

void DELETE(vector <Student*> &svect) {
  
  float id_input;
  cout << "Enter the ID of the student to delete" << endl;
  cin >> id_input;
  for(vector<Student*>::iterator ptr = svect.begin(); ptr != svect.end(); ptr++){

    if (id_input == (*ptr)->id){

	delete *ptr; //delete student list pointer within vector
	svect.erase(ptr); //delete iterator ptr memory
	break; //leave loop
      }

  }
}

