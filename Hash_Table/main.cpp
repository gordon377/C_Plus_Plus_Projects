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
void DELETE(Student** hash, int id, int size);
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
		newNextB->previous = NULL;
		ADD(hash, newNextB, doubleSize);
	      }
	    }
	    ADD(hash, current, doubleSize);
	  }
	}
	delete[] tempHash; //Reset rehashing system
	size = doubleSize; //Size update
      }
    }
    else if(strcmp(input, "ADDRANDOM") == 0){
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
		    newNextB->previous = NULL;
		    ADD(hash, newNextB, doubleSize);
		  }
		}
		ADD(hash, current, doubleSize);
	      }
	    }
	    delete[] tempHash; //Reset rehashing system
	    size = doubleSize; //Size update
	  }
	  num--;
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


  void ADD(Student** hash, Student* newStudent, int size) { //Adding new student with info
    int element = (newStudent->id) % size;
    //Inputting Student Data into current Hashtable
    if (hash[element] == NULL){ //No collision case
      hash[element] = newStudent;
    }
    else { //Collision case
      if((hash[element])->next == NULL){ //No collisions here prior
	(hash[element])->next = newStudent;
	(hash[element]->next)->previous = (hash[element])->next; //No next?
      }
      else{ //One collision here prior (unlikely to be more two collisions in one area - can be automated with loops for larger datasets)
	((hash[element])->next)->next = newStudent;
	(((hash[element])->next)->next)->previous = ((hash[element])->next)->next;
      }
    }
}

  void PRINT(Student** hash, int size) { //Printing stored student data
    cout << "\n" << "PRINTING INITIATION" << "\n" << endl;
    for(int i = 0; i < size; i++){
      Student* current = hash[i];
      if(current != NULL){
	cout << current->first_name << " ";
	cout << current->last_name << " ID: ";
	cout << current->id << " GPA: ";
	cout << fixed << setprecision(2) << current->gpa << endl;
	Student* NXT = current->next;
	if (NXT != NULL){
	  cout << '\t' << NXT->first_name;
	  cout << " " << NXT->last_name;
	  cout << " ID: " << NXT->id;
	  cout << " GPA: " << fixed << setprecision(2) << NXT->gpa << endl;
	}
      }
    }
    cout << "PRINTING FINISHED" << endl;
  }

  void DELETE(Student** hash, int id, int size){
    int element = id % size;
    if(hash[element] == NULL){
      cout << "No student with this ID to remove" << endl;
    }
    else{
      if(hash[element]->id == id){ //IDs match, delete
	if(hash[element]->next == NULL){
	  hash[element] = NULL;
	}
	else{ //Cut Student 1 & 2 while setting initial student in linked list as Student 2 (push everything towards beginning by one)
	  Student* newCurr = hash[element]->next;
	  newCurr->previous = NULL;
	  hash[element] = newCurr;
	}
      }
      else{ 
	if(hash[element]->next == NULL){
	  cout << "No student with this ID to remove" << endl;
	}
	else{
	  if(hash[element]->next->id == id){ //IDs match, delete
	    hash[element]->next = NULL;
	  }
	  else{
	    cout << "No student with this ID to remove" << endl;
	  }
	}
      }
    }
  }

  bool collisionCheck(Student** hash, int size){
    bool newHash = false; //Conditional to return | Checks if a new Hash needs to be made (in this case doubling the hashtable)
    int element = 0;
    while(newHash == false && element < size){
      if(hash[element] != NULL){
	if((hash[element])->next != NULL){
	  if(((hash[element])->next)->next != NULL){
	    newHash = true;
	  }
	}
      }
      element++;
    }
    return newHash;
  }

