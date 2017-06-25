#include <bits/stdc++.h>
 
using namespace std;

string game[3];

bool verify_winner(char player) {
	
	for (int i = 0; i < 3; ++i)
	{
		if(player == game[i][0] && player == game[i][1] && player == game[i][2]){
			return true;
		}

		if(player == game[0][i] && player == game[1][i] && player == game[2][i]){
			return true;
		}

		if(player == game[i][0] && player == game[i][1] && player == game[i][2]){
			return true;
		}

	}

	if (game[0][0] == player && game[1][1] == player && game[2][2] == player) {
      return true;
  }
  if (game[0][2] == player && game[1][1] == player && game[2][0] == player) {
      return true;
  }

  return false;

}

int main() {

	string gameInput;
	cin >> gameInput;
	
	while(gameInput != "end"){

		bool is_finished = true;

		game[0] = gameInput.substr(0, 3);
		game[1] = gameInput.substr(3, 3);
		game[2] = gameInput.substr(6, 3);

		int playerX = 0, playerO = 0;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if(game[i][j] == 'X'){
					playerX++;
				} 
				else if (game[i][j] == 'O'){
					playerO++;
				}
			}
		}

		if((playerX - playerO) > 1){
			is_finished = false;
		}
		if(playerO > playerX){
			is_finished = false;
		}


		//cout << is_finished << endl;

		bool xWinner = verify_winner('X');
		bool oWinner = verify_winner('O');

		//cout << "X: " << verify_winner('X') << " O: " << verify_winner('O') << endl;


		if(xWinner){
			//O jogador X não tiver uma jogada a mais que o jogador O, é invalido
			if((playerX - playerO) != 1){
				is_finished = false;
			}
		} 

		//cout << is_finished << endl;

		if(oWinner){
			//O jogador O só pode vencer quando tiver o mesmo numero de jogadas que X
			if((playerX - playerO) != 0){
				is_finished = false;
			}
		} 


		//cout << is_finished << endl;

		if(xWinner == true && oWinner == true){
			is_finished = false;
		}		

		if(xWinner != true && oWinner != true){
			if((playerO + playerX) != 9){
				is_finished = false;
			}	
		}

		//cout << is_finished << endl;

		if(is_finished){
			cout << "valid\n";
		}
		else{
			cout << "invalid\n";
		}


		cin >> gameInput;

	}

	return 0;

}
