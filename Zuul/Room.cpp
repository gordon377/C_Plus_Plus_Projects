#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

//Room naming
Room::Room(char* nameIn){
  strcpy(name, nameIn);
}

//Room Items
void Room::OutItems(){ //List Items
  for(vector<Item*>::iterator it = items->begin(); it != items->end(); ++it){
    cout << "Name: " << (*it)->getName() << endl;
  }
}

bool Room:: takeItem(Item* item){ //"item" = name of item requested
  for(vector<Item*>::iterator it = items->begin(); it != items->end(); ++it){
    if(strcmp(((*it)->getName(), item->getName()) == 0){
	items->erase(it);
	return true;
      }
      else{
	return false;
      }
      }
  }
}

bool Room::addItem(Item* item){
  items->push_back(item);
  return true;
}

//Room Exits
bool Room::setExit(char* orientation, Room* toRoom){
  exits->insert(pair<char*, Room*>(direction, toRoom));
  return true;
}

void Room::listExits(){
  for(map<char*. Room*>::iterator it = exits->begin(); it != exits->end(); ++it){
    cout << "Exit " << it->first << " to room: " << it->second->name << endl;
  }
}

char* Room::getName(){
  return name
}

vector<Item*>* Room::getItems(){
  return items;
}

map<char*, Room*>* Room::getExits(){
  return exits;
}
