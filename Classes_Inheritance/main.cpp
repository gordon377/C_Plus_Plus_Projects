

//Gordon Chen
//Classes & Inheritance
//November 8th 2023

#include <iostream>
#include <cstring>
#include <vector>
#include "Movies.h"
#include "Music.h"
#include "VideoGames.h"
#include "Media.h"

using namespace std;

//prototypes
void ADD(vector<Media*>* database);
void DELETE(vector<Media*>* database);
void SEARCH(vector<Media*>* database);

int main(){
  bool proceed = true;
  char input[81];
  vector<Media*>* database = new vector<Media*>(); //Second Star needed because the vector makes pointers to the datatype anyway (this pointers to Media pointers

  while(proceed){

    cout << "Enter of command: (ADD, SEARCH, DELETE, or QUIT | Case Sensitive)" << endl;
    cin >> input; //Do I need to cin.clear and cin.ignore here?
    cin.clear();
    cin.ignore(10000, '\n');
  

    if(strcmp(input, "ADD") == 0){
      ADD(database);
    }
    else if(strcmp(input, "DELETE") == 0){
      DELETE(database);
    }
    else if(strcmp(input, "SEARCH") == 0){
      SEARCH(database);
    }
    else if(strcmp(input, "QUIT") == 0){
      return 0;
    }
    else{
      cout << "Invalid Input" << endl;
    }
  
  }
}

void ADD(vector<Media*>* database){ //Add new info
  char input[81];
  bool proceed = true;

  while(proceed){
    cout << "What media type do you want to add? (MOVIES, MUISC, or VIDEOGAMES?)" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');

    if(strcmp(input, "MOVIES") == 0){
      Movies* movie = new Movies();
      database->push_back(movie);
      proceed = false;
    }
    else if(strcmp(input, "MUSIC") == 0){
      Music* music = new Music();
      database->push_back(music);
      proceed = false;
    }
    else if(strcmp(input, "VIDEOGAMES") == 0){
      VideoGames* videogames = new VideoGames();
      database->push_back(videogames);
      proceed = false;
    }
    else{
      cout << "Invalid Input" << endl;
    }
    
  }
}

  void DELETE(vector<Media*>* database){
    bool proceed = true;
    char input[81];

    while(proceed == true){
      cout << "Search by title or year? (Input t or y)" << endl;
      cin >> input;
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "t") == 0){
	bool match = false;
	cout << "Enter the title: " << endl;
	cin >> input;
	cin.clear();
	cin.ignore(10000, '\n');
	for(vector<Media*>::iterator iter = database->begin(); iter != database->end(); ++iter){
	  if(strcmp(input, (*iter)->getTitle()) == 0){
	    proceed = false;
	    match = true;
	    delete *iter;
	    database->erase(iter);
	    return;
	}
      }
      if(!match){
	cout << "Object requested does not exist" << endl;
      }
      }
      else if(strcmp(input, "y") == 0){
	bool match = false;
	cout << "Enter year: " << endl;
	cin >> input;
	cin.clear();
	cin.ignore(10000, '\n');
        for(vector<Media*>::iterator iter = database->begin(); iter != database->end(); ++iter){
          if((atoi(input) == ((*iter)->getYear())) == 0){ //atoi converted string to integer
            proceed = false;
            match = true;
            delete *iter;
            database->erase(iter);
	    cout << "Deleted" << endl;
            return;
        }

      }
	if(!match){
	  cout << "Object requested does not exist" << endl;
	}
    }
      
  }
  
}

  void SEARCH(vector<Media*>* database){ //Search for and print info about requested object (searching by title or year)
    bool proceed = true;
    char input[81];
    bool match = false;

    while(proceed){
      cout << "Search by title or year? (Input t or y)" << endl;
      cin >> input;
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "t") == 0){
        cout << "Enter the title: " << endl;
        cin >> input;
        cin.clear();
        cin.ignore(10000, '\n');
        for(vector<Media*>::iterator iter = database->begin(); iter != database->end(); ++iter){
          if(strcmp(input, (*iter)->getTitle()) == 0){
            proceed = false;
            match = true;
	    (*iter)->getInfo();
        }
      }
      }
	else if(strcmp(input, "y") == 0){
	  cout << "Enter the year of release: " << endl;
	  cin >> input;
	  cin.clear();
	  cin.ignore(10000, '\n');
	  for(vector<Media*>::iterator iter = database->begin(); iter != database->end(); ++iter){
	    if((atoi(input) == ((*iter)->getYear())) == 0){
	      proceed = false;
	      match = true;
	      (*iter)->getInfo();

	}
      if(!match){
        cout << "Object requested does not exist" << endl;
      }
      }

    
  }
  }
 }
