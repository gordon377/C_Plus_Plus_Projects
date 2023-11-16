//Implement Movie Functions/Methods

#include "Movies.h"
#include <iostream>

using namespace std;

Movies::Movies() : Media(){  //Collect Info

  cout << "Enter name of director(s): " << endl;
  cin >> director;
  cin.clear();
  cin.ignore(10000, '\n');
  cout << "Enter the duration of the music (in minutes | numbers only): " << endl; //Could make a valid input checker here
  cin >> duration;
  cin.clear();
  cin.ignore(10000, '\n');
  if(rating == 0){

    cout << "Enter a rating (can't be 0): " << endl;
    cin.clear();
    cin.ignore(10000, '\n');

  }

}

void Movies::Info(){ //Output Info

  cout << "Title: " << title << ", Year: " << year << ", Director: " << director << ", Duration: " << duration << ", Rating: " << rating << endl;
  return;
  
}
