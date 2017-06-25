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

int d, n, m, p, z;
int inputs = 0;
string portos, origem, destino;
msvs grafo;
int resultado; 

map<string, int> fila;
map<string, int> distancias;
vs pilha;

int bfs(string raiz, string chegada){
	string atual;
	fila[raiz] = 2;
	distancias.insert(make_pair(raiz, 0));
	pilha.push_back(raiz);
	while(pilha.size() != 0){
		atual = pilha.back();
		pilha.pop_back();
		for (vs::iterator i = grafo[atual].begin(); i < grafo[atual].end(); i++){
			
			if(fila[*i] == 0){
				fila[*i] = 2;
				distancias[*i] = distancias[atual] + 1;
				pilha.push_back(*i); 	
			}

			if(*i == chegada){
				return distancias[*i];
			}
			fila[atual] = 2;
		}
		
	}
	return 0;

}

int main(){
	cin >> d;
	cout << "SHIPPING ROUTES OUTPUT\n\n";
	for (int i = 0; i < d; ++i)
	{
		cout << "DATA SET  " << ++inputs << endl;
		cin >> m >> n >> p;
		for (int j = 0; j < m; ++j)
		{
			cin >> portos;
			fila.insert(make_pair(portos, 0));
			vs *x = new vs();
			grafo.insert(make_pair(portos, *x));
		}
		cout << endl;
		for (int j = 0; j < n; ++j)
		{
			cin >> origem >> destino;
			grafo[origem].push_back(destino);
			grafo[destino].push_back(origem);
		}
		for (int j = 0; j < p; ++j)
		{
			cin >> z >> origem >> destino;
			resultado = bfs(origem, destino);
			if(resultado){
				cout << '$' << (resultado * 100 * z) << endl;
			} else {
				cout << "NO SHIPMENT POSSIBLE\n";
			}
			for (auto k = fila.begin(); k != fila.end(); ++k)
			{
				k->second = 0;
			}


			distancias.clear();
		}
		grafo.clear();
		fila.clear();
		cout << endl;
	}
	cout << "END OF OUTPUT" << endl;
}