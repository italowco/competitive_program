#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MAX_COLUMN 7

typedef vector< vector<int> > matriz;
typedef map<int, int> local;


bool is_solution(int coluna){
	if (coluna > MAX_COLUMN){
		return true;
	} 
	else{
		return false;
	}

}

bool procurar_rainha(matriz v, iterator x, iterator y){
	for (auto i = x; i != v.end() - 1; ++i)
	{
			
	}
}

void backtracking(int entrada[] , matriz v, int coluna){
	if(is_solution()){

	}
	else{
		for (auto i = v.begin(); i <= v.end() - 1; ++i)
			{
				for (auto j = (*i).begin(); j <= (*i).end(); j++)
				{
					if(*j == 1){
						backtracking(xadrez, conluna + 1);
					}
				}
			}	
	}
}

int main(){
	int a[2];
	cin >> a[0] >> a[1];
	matriz xadrez(8, vector<int>(8));
	local mapa;
	for (auto i = xadrez.begin(); i <= xadrez.end() - 1; i++)		
	{	
		for (auto j = (*i).begin(); j <= (*i).end() - 1; j++)
		{
			*j = 0;
			cout << *j;
		}
		cout << endl;
	}
	xadrez[a[0]][a[1]] = 1;
	backtracking(xadrez, 0);
	
}