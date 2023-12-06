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
  if(loadResources(rooms, currentRoom) == false){
    cout << "Debug: Resources didn't load" << endl;
    return 1;
  }
  cout << "Welcome to the cheapest, lowest end, Five Nights at Freddy's knockoff you've ever seen" << endl;
  cout << "As always, you are a security guard tasked with managing a children's aracade during the night hours" << "\n" << "Your goal? To escape by any means necessary" << endl;
  cout << "Good luck!" << "\n" << endl;

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
  char tmpInput[101];
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
    return true;
  }
  cout << "Invalid input" << endl;
  }
  return false;
}

bool acquire(Room* &currentRoom, vector<Item*>* &inventory){ //Take item from room and put it in player inventory
  bool cont = true;
  char tmpInput[101];
  cout << "Current Room's Items: " << endl;
  currentRoom->OutItems();
  cin.get();
  while(cont){
    cout << "What do you want to take? (Enter exactly as listed or type 'NOTHING' if you don't want to take anything)" << endl;
    cin.clear();
    cin >> tmpInput;
    for(vector<Item*>::iterator it = currentRoom->getItems()->begin(); it != currentRoom->getItems()->end(); ++it){
      if(!strcmp((*it)->getName(), tmpInput)){
	cont = false;
	cout << "You took the " << (*it)->getName() << endl;
	inventory->push_back(*it);
	currentRoom->takeItem(*it);
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

bool listInventory(vector<Item*>* &inventory){ //List player inventory
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
  Room* mainStage = new Room(mainStage0);

  char* lunchRoom0 = new char[101];
  strcpy(lunchRoom0, "Lunch Room");
  Room* lunchRoom = new Room(lunchRoom0);

  char* hallway0 = new char[101];
  strcpy(hallway0, "Hallway");
  Room* hallway = new Room(hallway0);

  char* outside0 = new char[101];
  strcpy(outside0, "Outside");
  Room* outside = new Room(outside0);

  char* vents0 = new char[101];
  strcpy(vents0, "Vents");
  Room* vents = new Room(vents0);

  char* animatronicStorage0 = new char[101];
  strcpy(animatronicStorage0, "Animatronic Storage");
  Room* animatronicStorage = new Room(animatronicStorage0);

  char* arcade0 = new char[101];
  strcpy(arcade0, "Arcade");
  Room* arcade = new Room(arcade0);

  char* bathroom0 = new char[101];
  strcpy(bathroom0, "Bathroom");
  Room* bathroom = new Room(bathroom0);

  char* storageCloset0 = new char[101];
  strcpy(storageCloset0, "Storage Closet");
  Room* storageCloset = new Room(storageCloset0);

  char* power_electronics0 = new char[101];
  strcpy(power_electronics0, "Power/Electronics");
  Room* power_electronics = new Room(power_electronics0);

  char* airconditioning0 = new char[101];
  strcpy(airconditioning0, "Air Conditioning");
  Room*  airconditioning = new Room(airconditioning0);

  char* privateRoom10 = new char[101];
  strcpy(privateRoom10, "Private Room #1");
  Room* privateRoom1 = new Room(privateRoom10);

  char* privateRoom20 = new char[101];
  strcpy(privateRoom20, "Private Room #2");
  Room* privateRoom2 = new Room(privateRoom20);

  char* kitchen0 = new char[101];
  strcpy(kitchen0, "Kitchen");
  Room* kitchen = new Room(kitchen0);

  char* lobby0 = new char[101];
  strcpy(lobby0, "Lobby");
  Room* lobby = new Room(lobby0);
    
  char* securitybooth0 = new char[101];
  strcpy(securitybooth0, "Security Booth");
  Room* securitybooth = new Room(securitybooth0);

  //ITEMS
  char* keyPart10 = new char[101];
  strcpy(keyPart10, "Key Part");
  Item* keyPart1 = new Item(keyPart10);

  char* keyPart20 = new char[101];
  strcpy(keyPart20, "Key Part");
  Item* keyPart2 = new Item(keyPart20);

  char* keyPart30 = new char[101];
  strcpy(keyPart30, "Key Part");
  Item* keyPart3 = new Item(keyPart30);

  char* coffee0 = new char[101];
  strcpy(coffee0, "Coffee");
  Item* coffee = new Item(coffee0);

  char* flashlight0 = new char[101];
  strcpy(flashlight0, "Flashlight");
  Item* flashlight = new Item(flashlight0);

  //Room Exit Orientations

  //to = going away from security booth | from = going to security booth

  char* toMS = new char[101];
  strcpy(toMS, "Stage Entrance");
  securitybooth->setExit(toMS, mainStage);

  char* fromMS = new char[101];
  strcpy(fromMS, "Booth");
  mainStage->setExit(fromMS, securitybooth);

  char* toLR = new char[101];
  strcpy(toLR, "Stained Entrance");
  securitybooth->setExit(toMS, lunchRoom);

  char* fromLR = new char[101];
  strcpy(fromLR, "Booth");
  lunchRoom->setExit(fromLR, securitybooth);

  char* toHall = new char[101];
  strcpy(toHall, "Long Corridor");
  securitybooth->setExit(toHall, hallway);

  char* fromHall = new char[101];
  strcpy(fromHall, "Booth");
  hallway->setExit(fromHall, securitybooth);

  char* toOutside = new char[101];
  strcpy(toOutside, "Locked Door");
  securitybooth->setExit(toOutside, outside);

  char* fromOutside = new char[101];
  strcpy(fromOutside, "Booth");
  outside->setExit(fromOutside, securitybooth);

  char* toVents = new char[101];
  strcpy(toVents, "Dusty Air Vents");
  securitybooth->setExit(toVents, vents);

  char* fromVents = new char[101];
  strcpy(fromVents, "Booth");
  vents->setExit(fromVents, securitybooth);

  char* toaniStorage = new char[101];
  strcpy(toaniStorage, "Creepy Storage Closet");
  securitybooth->setExit(toaniStorage, animatronicStorage);

  char* fromaniStorage = new char[101];
  strcpy(fromaniStorage, "Booth");
  animatronicStorage->setExit(fromaniStorage, securitybooth);

  char* toArcade = new char[101];
  strcpy(toArcade, "Game Room");
  securitybooth->setExit(toArcade, arcade);

  char* fromArcade = new char[101];
  strcpy(fromArcade, "Booth");
  arcade->setExit(fromArcade, securitybooth);

  char* toBR = new char[101];
  strcpy(toBR, "Sanitized Entrance");
  securitybooth->setExit(toBR, bathroom);

  char* fromBR = new char[101];
  strcpy(fromBR, "Booth");
  bathroom->setExit(fromBR, securitybooth);

  char* toStorage = new char[101];
  strcpy(toStorage, "Janitor's Closet Entrance");
  securitybooth->setExit(toStorage, storageCloset);

  char* fromStorage = new char[101];
  strcpy(fromStorage, "Booth");
  storageCloset->setExit(fromStorage, securitybooth);

  char* toPower = new char[101];
  strcpy(toPower, "Breaker/Power Room");
  securitybooth->setExit(toPower, power_electronics);

  char* fromPower = new char[101];
  strcpy(fromPower, "Booth");
  power_electronics->setExit(fromPower, securitybooth);

  char* toAC = new char[101];
  strcpy(toAC, "Air Con Entrance");
  securitybooth->setExit(toAC, airconditioning);

  char* fromAC = new char[101];
  strcpy(fromAC, "Booth");
  airconditioning->setExit(fromAC, securitybooth);

  char* toPR1 = new char[101];
  strcpy(toPR1, "Secluded Entrance 1");
  securitybooth->setExit(toPR1, privateRoom1);

  char* fromPR1 = new char[101];
  strcpy(fromPR1, "Booth");
  privateRoom1->setExit(fromPR1, securitybooth);
  
  char* toPR2 = new char[101];
  strcpy(toPR2, "Secluded Entrance 2");
  securitybooth->setExit(toPR2, privateRoom2);

  char* fromPR2 = new char[101];
  strcpy(fromPR2, "Booth");
  privateRoom2->setExit(fromPR2, securitybooth);

  char* toKit = new char[101];
  strcpy(toKit, "Entrance to Nourishment");
  securitybooth->setExit(toKit, kitchen);

  char* fromKit = new char[101];
  strcpy(fromKit, "Booth");
  kitchen->setExit(fromKit, securitybooth);

  char* toLob = new char[101];
  strcpy(toLob, "Entrance to Reception");
  securitybooth->setExit(toLob, lobby);

  char* fromLob = new char[101];
  strcpy(fromLob, "Booth");
  lobby->setExit(fromLob, securitybooth);

  //adding items to rooms
  kitchen->addItem(coffee);
  securitybooth->addItem(flashlight);
  privateRoom1->addItem(keyPart1);
  arcade->addItem(keyPart2);
  lobby->addItem(keyPart3);

  //push back room info
  rooms->push_back(mainStage);
  rooms->push_back(lunchRoom);
  rooms->push_back(hallway);
  rooms->push_back(outside);
  rooms->push_back(vents);
  rooms->push_back(animatronicStorage);
  rooms->push_back(arcade);
  rooms->push_back(bathroom);
  rooms->push_back(storageCloset);
  rooms->push_back(power_electronics);
  rooms->push_back(airconditioning);
  rooms->push_back(privateRoom1);
  rooms->push_back(privateRoom2);
  rooms->push_back(kitchen);
  rooms->push_back(lobby);
  rooms->push_back(securitybooth);

  currentRoom = securitybooth;
  return true;
 
}
