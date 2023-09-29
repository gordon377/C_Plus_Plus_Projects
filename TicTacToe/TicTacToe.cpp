//TicTacToe Game
//Gordon Chen
// September 29th, 2023

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char arr[4][4]={
    {' ','1', '2', '3'},
    {'a',' ', ' ', ' '},
    {'b',' ',' ', ' '},
    {'c', ' ', ' ', ' '}
  };

  int i,j;

  for (int k = 0; k < 2; k++){
    char temp_i;
    int temp_j;

    //add second loop things

    cout << "Player 1 (X): Input your row letter" << endl;
    cin >> temp_i;
    cout << "Player 1 (X): Input your column number" << endl;
    cin >> temp_j;

    j = temp_j-1;

      if(temp_i == 'a'){
	i = 1;
      }
      else if(temp_i == 'b'){
	i = 2;
      }
      else{
	i = 3;
      }
    
    cout << "Current Board: ";
    
    for(i=0; i<3; i++){
      cout << "\n";
      for(j=0; j<3; j++){
	cout<< "\t"<<arr[i][j];
      }
    }

  }

  cout << "\ni value: " << i;
  
  return 0;
}
