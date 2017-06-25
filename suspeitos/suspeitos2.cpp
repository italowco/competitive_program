#include <bits/stdc++.h>
using namespace std;
 

typedef pair<int, int> ii; 
typedef vector<ii> vii;	   //vector de ii
typedef vector<vii> vvii;  //vector de vi

typedef vector<int> vi;
typedef vector<vi> vvi;


vvi adj_list;
vi visitados;
int a, b, c;

bool visited(int a){
	for (int i = 0; i < visitados.size(); ++i)
	{
		if(a == visitados[i]){
			return true;
		}
	}
	return false;
}

void dfs(int u){
	visitados.push_back(u);

	for (int i = 0; i < adj_list[u].size(); ++i)
	{
		if(!visited(adj_list[u][i])){
			dfs(adj_list[u][i]);
		}
	}
}

void add_adj(vi array){
	vi *x = new vi();
	//percorre o array
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array.size(); j++)
		{
			if(i != j){
				x->push_back(array[j]);
			
			} 
		}

		for (int j = 0; j < x->size(); j++)
			{
				adj_list[array[i]].push_back(x->at(j));
			}

		

		x->clear();
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

		dfs(0);
		cout << visitados.size() << endl;;

		adj_list.clear();
		visitados.clear();
		
		cin >> a >> b;
	}
}