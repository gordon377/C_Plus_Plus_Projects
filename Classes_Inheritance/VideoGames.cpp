//Implement VideoGames Class Methods/Functions

#include <iostream>
#include "VideoGames.h"

using namespace std;

VideoGames::VideoGames() : Media(){ //Collect Info

  cout << "Enter publisher name: (80 character max)" << endl;
  cin >> publisher;
  cin.clear();
  cin.ignore(10000, '\n');
  if(rating == 0){ //Optional, but easy check

    cout << "Enter a rating (can't be 0): " << endl;
    cin.clear();
    cin.ignore(10000, '\n');
    
  }
}

void VideoGames::Info(){ //Output Info

  cout << "Title: " << title << ", Year: " << year << ", Publisher: " << publisher << ", Rating: " << rating << endl;
  return;
  
}

