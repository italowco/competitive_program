#include <bits/stdc++.h>

using namespace std;

string boggle[4];
vector<string> vs;
typedef pair<int, int> ii;
typedef pair<ii, int> piii;
int visitados[4][4];

int score = 0;

void reset_visit(){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j)
		{
			visitados[i][j] = 0;
		}
	}
}


string bfs(string word, int count, int i, int j, string chars){
	
	cout << word << " E " << chars << " " <<  count << endl;

	if(visitados[i][j] == 1) return 0;

	if(count >= 12){
		return 0;
	}


	visitados[i][j] = 1;
	if(word == chars){
		score += count;
		return word;
	}

	else {
		chars += boggle[i][j];
		if(i < 0 || i > 3 || i > 3 || j < 0){
			return 0;
		}
		else {
			
		}

	}
}

int main(){
	int n , c, b= 0;
	
	cin >> n;
	string entrada;
	while(++b){

		for (int i = 0; i < 4; ++i){
			cin >> boggle[i];
		}

		cin >> c;
		
		for (int m = 0; m < c; ++m)
		{
			cin >> entrada;
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{					
					reset_visit();
					bfs(entrada, 0, i, j, "");
				}
			}
		}

		

		if(n == b) break;
	}

}