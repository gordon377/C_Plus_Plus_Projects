//TicTacToe Game
//Gordon Chen
//September 29th, 2023

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char board[4][4]={ //first num refers to the row, second refers to the column
    {' ','1','2','3'},
    {'a',' ',' ',' '},
    {'b',' ',' ',' '},
    {'c',' ',' ',' '}
  };

  int i,j;
  int k = 0;
  bool game_end = false;
  bool player_1 = false;
  int player_1_wins = 0;
  int player_2_wins = 0;
  
  while (game_end == false){
    char temp_i;
    int temp_j;
    char player_symbol = ' ';

    if(k%2==0){
	cout << "Player 1 (X): Input your row letter" << endl;
	cin >> temp_i;
	cout << "Player 1 (X): Input your column number" << endl;
	cin >> temp_j;
	player_symbol = 'X';
	player_1 = true;
      }
      else {
	cout << "Player 2 (O): Input your row letter" << endl;
	cin >> temp_i;
	cout << "Player 2 (O): Input your column number" << endl;
	cin >> temp_j;
	player_symbol = 'O';
	player_1 = false;
      }

      j = temp_j;
      temp_i = tolower(temp_i);

      if(temp_i == 'a'){
	i = 1;
      }
      else if(temp_i == 'b'){
	i = 2;
      }
      else if(temp_i == 'c'){
	i = 3;
      }

      if(board[i][j] != ' '){
	cout<< "Space already taken, try again" << endl;
	continue;
      }
      else{
	board[i][j] = player_symbol;
	k++;
      }

    cout << "Current Board: ";

    int filled = 0;

    for(i=0; i<4; i++){
      cout << "\n";
      for(j=0; j<4; j++){
	cout<< "\t"<<board[i][j];
	filled++;
      }
    }

    //check if there is a win


    //checks for row wins
    
    j = 1;
    i = 1;
    for(i=1; i<4; i++){
      if(board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2]){
	game_end = true;
      }
    }
    //checks for column wins
    for(j=1; j<4; j++){
      if(board[i][j] == board[i+1][j] board[i][j] == board[i+2][j]{
	  game_end = true;
	}
    }

      //checks for diagonal wins
      if (board[1][1] == board[2][2] && board[1][1] == board[3][3]){
	game_end = true;
      }
      if (board[3][1] == board[2][2] && board[3][1] == board[1][3]{
	  game_end = true;
	}

	if(game_end = true){
	  if(player_1 == true){
	    player_1_wins++;
	    cout << "Player 1 wins!" << endl;
	  }
	  else{
	    player_2_wins++;
	    cout << "Player 2 wins!" << endl;
	  }
	  
	}

    if(filled == 9 && game_end == false){
      cout << "The board is filled! The game ends in a draw" << endl;
    }
    else{
      filled = 0;
    }

	cout << "Current win totals: \n" << "Player 1: " << player_1_wins << '\n' << "Player 2: " << player_2_wins << endl;
	char again;
	cout<<"Play again? (y/n)"<<endl;
	cin >> again;
	if (again == 'y'){
	    game_end = false;
	     board[={ //first num refers to the row, second refers to the column
		 {' ','1','2','3'},
		 {'a',' ',' ',' '},
		 {'b',' ',' ',' '},
		 {'c',' ',' ',' '}

	  }

    
    cout << endl;

  }

  
  return 0;
}
