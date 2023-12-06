//Header Guard Protecction

#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Item.h"

using namespace std;

class Room{

 public:
  Room(char* nameIn); //Room Name
  char* getName(); //Retrieve name information
  char name[101];
  void OutExits(); //Output Exits
  map<char*, Room*>* getExits();
  void OutItems(); //Output Items
  vector<Item*>* getItems(); 
  //Game Manager Stuff
  bool setExit(char* orientation, Room* toRoom);
  bool takeItem(Item* item); //Taking item from room (Room Inventory -> Player Inventory) Remove item from room inventory
  bool addItem(Item* item);

protected: //Not needed in this case, but good practice
  map<char*, Room*>* exits = new map<char*, Room*>();
  vector<Item*>* items = new vector<Item*>();

};

#endif

