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
bool contains(vector<Item*>* &inventory, char* name);

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

bool move(Room* &currentRoom){ //Move player from room to room
  bool cont = true;
  char terminal[80];
  currentRoom->listExits();
  cin.get(); //Alternative pause [Ethan Kusse method]
  while(cont){
    cout << "Where do you want to go? (Enter only letters and those of the right case)" << endl;
    cin.clear();
    cin.getline(tmpInput, 101);
  map<char*, Room*>* currentExits = currentRoom->getExits();
  for(map<char*, Room*>::iterator it = currentExits->begin(); it != currentExits->end(); ++it){
    if(!strcmp(tmpInput,(it)->first)){
      currentRoom = (it)->second;
      cont = false;
      cout << "You are in " << currentRoom->getName() << endl;
      return true;
    }
  }
  if(!strcmp(tmpInput, "QUIT")){
    cout << "You change your mind and don't move anywhere" << endl;
    cont = true;
    return = true;
  }
  cout << "Invalid input" << endl;
  }
  return false;
}

bool acquire(Room* &currentRoom, vector<Item*>* &inventory){ //Take item from room and put it in player inventory
  bool cont = true;
  char tmpInput[101];
  cout << "Current Room's Items: " << endl;
  currentRoom->listItems();
  cin.get();
  while(cont){
    cout << "What do you want to take? (Enter exactly as listed or type 'NOTHING' if you don't want to take anything)" << endl;
    cin.clear();
    cin >> tmpInput;
    for(vector<Item*>::iterator it = currentRoom->getItems()->begin(); it != currentRoom->end(); ++it){
      if(!strcmp((*it)->getName(), tmpInput)){
	cont = false;
	cout << "You took the " << (*it)->getName() << endl;
	inventory->push_back(*it);
	currentRoom->removeItem(*it);
	return true;
      }
    }
    if(!strcmp(tmpInput, "NOTHING")){
      cout << "You decide against picking up anything" << endl;
      cont = false;
      return true;
    }else{
      cont = true;
    }
    cout << "Invalid Input" << endl;
  }
}

bool listInventory(vectir<Item*>* &inventory){ //List player inventory
  cout << "Inventory: " << endl;
  for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); ++it){
    cout << (*it)->getName() << endl;
  }
  return true;
}

bool drop(Room* &currentRoom, vector<Item*>* &inventory){ //Drop Item
  bool cont = true;
  char tmpInput[101];
  cout << "What item do you want to drop? (Enter an item or enter 'NOTHING')" << "Inventory: " << endl;
  for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); ++it){
    cout << (*it)->getName() << endl;
  }
  while(cont){
    cin.clear();
    cin >> tmpInput;
    for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); ++it){
      if(!strcmp((*it)->getName(), tmpInput)){
	cont = false;
	cout << "You dropped: " << (*it)->getName() << " while in " << currentRoom->getName() << endl;
	currentRoom->addItem((*it));
	inventory->erase(it);
	return true;
      }
    }
    if(!strcmp(tmpInput, "NOTHING")){
      cout << "You choose not to drop anything" << endl;
      cont = false;
      return true;
    }else{
      cont = true;
    }
    cout << "Invalid Input" <<endl;
  }
  return false;
}

//Load all room info, basically jumpstart game world

bool loadResources(vector<Room*>* &rooms, Room* &currentRoom){
  //Rooms

  char* mainStage0 = new char[101];
  strcpy(mainStage0, "Main Stage");
  Room* mainStage = new Room(mainStage0)

  char* lunchRoom0 = new char[101];
  strcpy(lunchRoom0, "Lunch Room");
  Room* lunchRoom = new Room(lunchRoom0)

  char* hallway0 = new char[101];
  strcpy(hallway0, "Hallway");
  Room* hallway = new Room(hallway0)

  char* outside0 = new char[101];
  strcpy(outside0, "Outside");
  Room* outside = new Room(outside0)

  char* vents0 = new char[101];
  strcpy(vents0, "Vents");
  Room* vents = new Room(vents0)

  char* animatronicStorage0 = new char[101];
  strcpy(animatronicStorage0, "Animatronic Storage");
  Room* animatronicStorage = new Room(1)

  char* arcade0 = new char[101];
  strcpy(arcade0, "Arcade");
  Room* arcade = new Room(arcade0)

  char* bathroom0 = new char[101];
  strcpy(, "Bathroom");
  Room* bathroom = new Room(bathroom0)

  char* storageCloset0 = new char[101];
  strcpy(storageCloset0, "Storage Closet");
  Room* storageCloset = new Room(storageCloset0)

  char* power_electronics0 = new char[101];
  strcpy(power_electronics0, "Power/Electronics");
  Room* power_electronics = new Room(power_electronics0)

  char* airconditioning0 = new char[101];
  strcpy(airconditioning0, "Air Conditioning");
  Room*  airconditioning new Room(airconditioning0)

  char* privateRoom10 = new char[101];
  strcpy(privateRoom10, "Private Room #1");
  Room* privateRoom1 = new Room(privateRoom10)

  char* privateRoom20 = new char[101];
  strcpy(privateRoom20, "Private Room #2");
  Room* privateRoom2 = new Room(privateRoom20)

  char* kitchen0 = new char[101];
  strcpy(kitchen0, "Kitchen");
  Room* kitchen = new Room(kitchen0)

  char* lobby0 = new char[101];
  strcpy(lobby0, "Lobby");
  Room* lobby = new Room(lobby0)
    
  char* securitybooth0 = new char[101];
  strcpy(securitybooth0, "Security Booth");
  Room* securitybooth = new Room(securitybooth0)

  //ITEMS
  char* 


}
