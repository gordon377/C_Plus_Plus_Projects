//Implement Music Class Methods/Functions

#include "Media.h"
#include <iostream>

using namespace std;

Music::Music() : Media(){ //Collect Info

  cout << "Enter the name of the artist: " << endl;
  cin >> artist;
  cin.clear();
  cin.ignore(10000, '\n');
  cout << "Enter the duration of the music (in minutes | numbers only): " << endl; //Could make a valid input checker here
  cin >> duration;
  cin.clear();
  cin.ignore(10000, '\n');
  cout << "Enter the name of the publisher: " << endl;
  cin >> publisher;
  cin.clear();
  cin.ignore(10000, '\n');

}

void Music::Info(){ //Return Info

  cout << << "Title: " << title << ", Year: " << year << ", Artist: " << artist << ", Publisher: " << publisher << ", Duration: " << duration << endl;

}
