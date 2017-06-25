#include <bits/stdc++.h>
using namespace std;
 

typedef pair<int, int> ii; 
typedef vector<ii> vii;	   //vector de ii
typedef vector<vii> vvii;  //vector de vi

typedef vector<int> vi;
typedef vector<vi> vvi;


vvi adj_list;
vi visitados(3000);
int a, b, c;
int sum = 0;



void dfs(int u = 0){
	visitados[u] = 1;
	sum++;
	for (int i = 0; i < adj_list[u].size(); ++i)
	{
		if(visitados[adj_list[u][i]] == 0){
			dfs(adj_list[u][i]);
		}	
	}
}

void add_adj(vi array){
	//percorre o array
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array.size(); j++)
		{
			if(i != j){
				adj_list[array[i]].push_back(array[j]);
			} 
		}
	}
}

int main(){
	cin >> a >> b;
	//Entra no while se a e b != 0
	while((a != 0) || (b != 0)){
		//adiciona a vetores a lista de adjacencias
		for (int i = 0; i < a; ++i)
		{
			vi *linha = new vi();
			adj_list.push_back(*linha);
		}

		//loop roda b vezes
		for (int i = 0; i < b; ++i)
		{	
			//C é o número membros de um grupo
			cin >> c;
			vi grupo(c);
			for (int j = 0; j < c; j++)
			{
				int x;
				scanf("%d", &x);
				grupo[j] = x;
			}
			add_adj(grupo);

		}

		sum = 0;
		for (int i = 0; i < 3000; ++i)
		{
			visitados[i] = 0;
		}
		dfs(0);
		cout << sum << endl;
		adj_list.clear();
		cin >> a >> b;
	}
}