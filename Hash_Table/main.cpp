//Hash Table
//Gordon Chen
//January 31st, 2024

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

struct Student { //Define Student structure

  char first_name[81];
  char last_name[81];
  int id;
  float gpa;
  Student* next;
  Student* previous;

};

//function prototypes

void ADD(Student** hash, Student* newStudent, int size);
void PRINT(Student** hash, int size);
void DELETE(Student** hash, int, ID, int size);
bool collisionCheck(Student** hash, int size);

int main(){

  char input[20]; //Function choice input
  bool end = false; //Continue condition
  int randID = 0;
  srand(time(NULL));
  randID = rand() % 1000000; //generating random ID value, up to six digits
  Student** hash = new Student* [101]; //101 base slots for 101 potential linked lists
  int size = 101;

  cout << "Starting Variables Initialized" << endl;
  
  while(end == false){ //Loops while end == false

    cout << "Type MANUALADD, ADDRANDOM, PRINT, DELETE, or QUIT (case sensitive) to interact with this student list" << endl;
    cin >> input; //Take in command
    if(strcmp(input, "MANUALADD") == 0){  //Calling function corresponding to requested command
      cout << "Inputting Student" << endl;
      Student* newStudent = new Student();
      newStudent->next = NULL;
      newStudent->previous = NULL;
      cout << "First Name: " << endl;
      cin >> newStudent->first_name;
      cin.clear();
      cout << "Last Name: " << endl;
      cin >> newStudent->last_name;
      cin.clear();
      cout << "ID: " << endl;
      cin >> newStudent->id;
      cin.clear();
      cout << "GPA: " << endl;
      cin >> newStudent->gpa;
      cin.clear();
      ADD(hash, newStudent, size);
      cout << "DEBUG: MANUAL ADD FINISHED" << endl;
      if(collisionCheck(hash, size)){ //Adjusting hash in case of collision
	cout << "Collision detected, adjusting hash table" << endl;
	Student** tempHash = new Student* [size];
	for (int i = 0; i < size; i++){ //Copying hash data into tempHash
	  tempHash[i] = hash[i];
	}
	int doubleSize = size * 2;
	hash = new Student* [doubleSize]; //Override original hash to be empty & double size
	for (int tempNum1 = 0; tempNum1 < doubleSize; tempNum1++){
	  hash[tempNum1] = NULL;
	}
	//reload original data into newly sized list
	for (int tempNum2 = 0; tempNum2 < doubleSize; tempNum2++){
	  if(tempHash[tempNum2] != NULL){
	    Student* current = tempHash[tempNum2];
	    if(current->next != NULL){
	      Student* newNext = current->next;
	      current->next = NULL;
	      newNext->previous = NULL;
	      ADD(hash, newNext, doubleSize);
	      if (newNext->next != NULL){
		Student* newNextB = newNext->next;
		newNext->next = NULL;
		newNext2->previous = NULL;
		ADD(hash, newNext2, newSize);
	      }
	    }
	    ADD(hash, current, doubleSize);
	  }
	}
	delete[] temp; //Reset rehashing system
	size = doubleSize; //Size update
      }
      line--;
    }
    else if(strcmp(input, "ADDRANDOM") == 0{
	int num;
	char** FName = new char* [30];
	char** LName = new char* [30];
	for (int i = 0; i< 20; i++){
	  FName[i] = new char[81];
	  LName[i] = new char[81];
	}
	cout << "How many students do you want to add?" << endl;
	cin >> num;
	cin.clear();
	ifstream myfile1("firstNames.txt");
	int line = 0;
	char first[101];
	while (line < 20) {
	  myfile1.getline(first, 101);
	  strcpy(FName[line], first);
	  line++;
	}
	ifstream myfile2("lastNames.txt");
	char last[101];
	line = 0; //Reset counter
	while (line < 20) {
	  myfile2.getline(last, 101);
	  strcpy(LName[line], last);
	  line++;
	}
	while (num > 0){ //Input Student Data into student structs
	  Student* newStudent = new Student();
	  //Generate and assign random data
	  int randFirst = rand() % 20;
	  int randLast = rand() % 20;
	  strcpy(newStudent->first_name, FName[randFirst]);
	  strcpy(newStudent->last_name, LName[randLast]);
	  newStudent->id = randID;
	  newStudent->gpa = (float)rand()/ (RAND_MAX)*5; //5.0 Scale
	  randID = randID + 22; //Increment to induce potential collisions (COME BACK TO THIS)
	  ADD(hash, newStudent, size); //Add student data
	  if(collisionCheck(hash, size)){ //Adjusting hash in case of collision
	    cout << "Collision detected, adjusting hash table" << endl;
	    Student** tempHash = new Student* [size];
	    for (int i = 0; i < size; i++){ //Copying hash data into tempHash
	      tempHash[i] = hash[i];
	    }
	    int doubleSize = size * 2;
	    hash = new Student* [doubleSize]; //Override original hash to be empty & double size
	    for (int tempNum1 = 0; tempNum1 < doubleSize; tempNum1++){
	      hash[tempNum1] = NULL;
	    }
	    //reload original data into newly sized list
	    for (int tempNum2 = 0; tempNum2 < doubleSize; tempNum2++){
	      if(tempHash[tempNum2] != NULL){
		Student* current = tempHash[tempNum2];
		if(current->next != NULL){
		  Student* newNext = current->next;
		  current->next = NULL;
		  newNext->previous = NULL;
		  ADD(hash, newNext, doubleSize);
		  if (newNext->next != NULL){
		    Student* newNextB = newNext->next;
		    newNext->next = NULL;
		    newNext2->previous = NULL;
		    ADD(hash, newNext2, newSize);
		  }
		}
		ADD(hash, current, doubleSize);
	      }
	    }
	    delete[] temp; //Reset rehashing system
	    size = doubleSize; //Size update
	  }
	  line--;
	}
      }
    else if(strcmp(input, "PRINT") == 0){
      PRINT(hash, size);
    }
    else if(strcmp(input, "DELETE") == 0){
      cout << "ID of Student to Remove: " << endl;
      int inputID;
      cin >> inputID;
      cin.clear();
      DELETE(hash, inputID, size);
    }
    else if(strcmp(input, "QUIT") == 0){
      cout << "DEBUG: Quitting Program" << endl;
      end = true;
      }
    else{

      cout << "Invalid input (case sensisitve commands)" << endl;  //Other case

    }

  }

  return 0;
}

void ADD(vector <Student*> &svect) { //Adding new student with info

  Student* s = new Student(); //Create new variable of student structure (new is called to keep the information for longer/on the hea\
p)
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

  vector<Student*>::iterator ptr = svect.begin(); //initialize iterator | (iterator returns pointers) | "ptr" (variable name) is a ptr to a specific value in the vector (in this case poi\
nts to a specific student list ptr in the vector)
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


