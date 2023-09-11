// Gordon Chen
// September 7th, 2023

// No global variables (global constants are all right)
// No strings (cstrings/character arrays can be used, and the cstring and cctype libraries are okay. Recommendation: use strcmp and strlen in projects.)
// Include <iostream>, not stdio Also, use "new" and "delete" instead of "malloc" and "free"

#include <iostream>

using namespace std;

int main()
{

    srand(time(NULL));
    int randNum = rand() % 101;
    int guess_count = 0;
    bool play_again = false;
      
    cout << "Random Number: " << randNum << endl;
    int input = 0;

    
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

	cout << "You got the number! Congratulations!" << endl;

      }

      
   
    }
    
    return 0;
}
