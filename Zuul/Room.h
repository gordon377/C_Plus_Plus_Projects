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
  char* NameInput();
  char name[101];
  void OutExits(); //Output Exits
  map<char*, Room*>* InputExits(); //Input Exits
  void OutItems(); //Output Items
  vector<Item*>* InputItems(); //Input Items
  //Game Manager Stuff
  bool setExit(char* orientation, Room* toRoom);
  bool takeItem(Item* item); //Taking item from room (Room Inventory -> Player Inventory)
  bool addItem(Item* item);

  
  //Description of room (flavor)
  bool trapped = false; //extra condition for making rooms trapped (can lose game)

protected:
  map<char*, Room*>* exits = new map<char*, Room*>();
  vector<Item*>* items = new vector<Item*>();

};

#endif

