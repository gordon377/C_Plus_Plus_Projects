//November 17th, 2023
//Gordon Chen
//Zuul

//Overall coding structure created with help from Ethan Kusse

#include <iostream>
#include <cstdlib> //Library for system class
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

//prototypes here
bool loadResources(vector<Room*>* &rooms, Room* &currentRoom);
bool move(Room* &currentRoom);
bool acquire(Room* &currentRoom, vector<Item*>* &inventory);
bool listInventory(vector<Item*>* &inventory);
bool drop(Room* &currentRoom, vector<Item*>* &inventory);
bool layout(vector<Room*>* &listRooms); //WHAT IS LIST ROOMS
void checkIfWon(Room* &currentRoom, vector<Item*>* &inventory, int rounds);
bool contents(vector<Item*>* &inventory, char* name);

int main(){ //main function
  bool active = true;
  char tmpInput[101];
  Room* currentRoom = NULL;
  vector<Room*>* rooms = new vector<Room*>();
  vector<Item*>* inventory = new vector<Item*>();
  if(loadresources(rooms, currentRoom) == false){
    cout << "Debug: Resources didn't load" << endl;
    return 1;
  }
  cout << "Welcome to the cheapest, lowest end, Five Nights at Freddy's knockoff you've ever seen" << endl;
  cout << "As always, you are a security guard tasked with managing a children's aracade during the night hours" << "\n" << "Your goal? To escape by any means necessary" << endl;
  cout << "Good luck! (Press any key to start)" << endl;
  system("pause"); //Wait for key press
  system("CLS"); //Clear Screen

  cout << "Possible commands (case sensistive): MOVE, MAP, TAKE, DROP, INV, QUIT" << endl;
  cout << "For the MOVE command, use one of the given exit orientations" << endl;
  while(active){ //Iterating Game Manager
    int rounds = 1;
    checkIfWon(currentRoom, inventory, rounds);
    cout << "Enter a command: " << endl;
    cin.clear();
    cin >> tmpInput;
    if(!strcmp(tmpInput, "MOVE")){
      move(currentRoom);
    }else if(!strcmp(tmpInput, "MAP")){
      layout(rooms);
    }else if(!strcmp(tmpInput, "TAKE")){
      acquire(currentRoom, inventory);
    }else if(!strcmp(tmpInput, "DROP")){
      drop(currentRoom, inventory);
    }else if(!strcmp(tmpInput, "INV")){
      listInventory(inventory);
    }else if(!strcmp(tmpInput, "QUIT")){
      return 0;
    }else{
      cout << "Invalid input, try again" << endl;
    }
    ++rounds;
  }
  return 0;
}

//DEFINING FUNCTIONS

void checkIfWon(Room* &currentRoom, vector<Item*>* &inventory, int rounds){ //Check if won + other game manager stuff
  if(rounds == 1){
    char* coffee = new char[101];
    strcpy(coffee, "Coffee");
  }
  if(rounds > 5){
    cout << "You're feeling a bit tired, maybe some coffee would help..." << endl;
  }
  if(rounds > 10){
    cout << "All these late nights haven't been doing you any good..." << "\n" << "You fall asleep and never make it out" << endl;
    cout << "GAME OVER" << endl;
    return;
  }
  char* winRoom = new char[101];
  strcpy(winRoom, "Outside");
  if(strcmp(currentRoom->getName(), winRoom) == 0){
    char* keyPart1 = new char[101];
    strcpy(keyPart1, "Key Part #1");
    char* keyPart2 = new char[101];
    strcpy(keyPart2, "Key Part #2");
    char* keyPart3 = new char[101];
    strcpy(keyPart3, "Key Part #3");
    if(contains(inventory, keyPart1) && contains(inventory, keyPart2) && contains(inventory, keyPart3)){ //Win Condition
      cout << "You finally made it outside! Fresh air never smelled so good." << endl;
      exit(0);
      return;
    } 
  }
  return;
}

bool layout(vector<Room*>* &roomsIN){ //Show layout
  for(vector<Room*>::iterator it = roomsIN->begin(); it != roomsIN->end(); ++it){
    cout << (*it)->getName() << " has exits/leads to: " << endl;
    (*it)->listExits();
  }
  return true;
}

bool contains(vector<Item*>* &inventory, char* name){ //Checking if player inventory contains given item
  for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); ++it){
    if(strcmp((*it)->getName(), name) == 0){
      return true;
    }
  }
  return false;
}

bool move(Room* &currentRoom){
  bool valid = true;
  char terminal[80];
  currentRoom->listExits();
  cin.get(); //Alternative pause [Ethan Kusse method]
  while(valid){
    cout << "Where to?" << endl;
    cin.clear();
    cin.getline(terminal, 101);
  }
}
