#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MAX_COLUMN 7

typedef vector< vector<int> > matriz;

bool

void set_cadidates(matriz tabuleiro, pair<int, int> cordendas, int candidates[]){
	
	if (/* condition */)
	{
		/* code */
	}
	else
	{
		for (int i = 0; i < 8; i++)		
		{	
			
			for (int j = 0; j < 8; j++)
			{
				if(i == cordenadas.first || j == cordenadas.second){
					//não é candidato
				
				else if(abs(i - cordenadas.first) == abs(j - cordenadas.second)){
					
				}
				else {
					set_cadidates();
				}
			}
		}	
	}
	


}


int main(){
	//array de resposta
	int cadidates[8];

	//tabuleiro
	matriz tabuleiro(8, vector<int>(8));
	//Entradas
	pair<int,int> cordenadas;
	cin >> cordenadas.first >> cordenadas.second;
	//preencher o tabuleiro com 0
	for (int i = 0; i < 8; i++)		
	{	
		
		for (int j = 0; j < 8; j++)
		{
			tabuleiro[i][j] = 0;
		}
	}

	tabuleiro[cordenadas.first][cordenadas.second] = 1;

	for (auto i = tabuleiro.begin(); i <= tabuleiro.end() - 1; i++)		
	{	
		for (auto j = (*i).begin(); j <= (*i).end() - 1; j++)
		{
			cout << *j;
		}
		cout << endl;
	}
}