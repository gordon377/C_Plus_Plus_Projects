// Gordon Chen
// September 7th, 2023

// No global variables (global constants are all right)
// No strings (cstrings/character arrays can be used, and the cstring and cctype libraries are okay. Recommendation: use strcmp and strlen in projects.)
// Include <iostream>, not stdio Also, use "new" and "delete" instead of "malloc" and "free"

#include <iostream>

using namespace std;

int main()
{
  
  bool play_again = true;
  
      while (play_again == true){
	srand(time(NULL));
	int randNum = rand() % 101;
	int guess_count = 0;
      
	cout << "Random Number: " << randNum << endl;
	int input = 0;
	char input_restart = 'n';

       while (input != randNum){
	 guess_count++;
	 cout << "What is your guess?" << endl;
	 cin >> input;
	 if (randNum > input){

	 cout << "Nope! Try again and guess higher." << endl;
      }
	 else if (randNum < input){

	   cout << "Nope! Try again and guess lower." << endl;

      }
	 else{

	   cout << "You got the number! Congratulations!" << endl << "Guess count: " << guess_count << endl;
	   cout << "Would you like to play again? (y/n)" << endl;
	   cin >> input_restart;
	   if (input_restart == 'y'){
	     play_again = true;
	     cout << "Great!" << endl;
	   }

	   if (input_restart == 'n'){
	     play_again = false;
	     cout << "Thanks for playing!" << endl;
	   }

	 }
       }
      }
    
    return 0;
}
