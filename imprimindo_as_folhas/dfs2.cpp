#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii; 
typedef vector<ii> vii;	   //vector de ii
typedef vector<vii> vvii;  //vector de vi

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<string> vs;
typedef vector<vs> vvs;

typedef map<string, vs> msvs;

msvs grafo;
vs pilha;


void apagar_no(string no){
	for (msvs::iterator i = grafo.begin(); i != grafo.end(); i++){
		auto it = find(i->second.begin(), i->second.end(), no);
		if(it != i->second.end()){
			i->second.erase(it);
		}
	}

}

void dfs(){
	for (msvs::iterator i = grafo.begin(); i != grafo.end(); i++)
	{
		if(i->second.size() == 0){
			pilha.push_back(i->first);
			grafo.erase(i);
		}
	}
}

int main()
{
	int a;
	string pai, filho;
	int x = 0;
	while(scanf("%d", &a) != EOF){

		while(x < a){
			cin >> pai;
			cin >> filho;
			
			grafo[pai].push_back(filho);
			grafo[filho];
			x++;
		}


		while(grafo.size() != 0){
			dfs();
			sort(pilha.begin(), pilha.end());
			for(int i = 0; i < pilha.size(); i++){
				cout << pilha[i] << endl;
				apagar_no(pilha[i]);
			}
			pilha.clear();
		}
		x = 0;
	}


}	