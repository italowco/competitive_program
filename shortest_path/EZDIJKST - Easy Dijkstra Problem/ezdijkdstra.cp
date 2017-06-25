#include <bits/stdc++.h>
using namespace std;
 
int INF = (2 << 20);

typedef pair<int, int> ii; 
typedef vector<ii> vii;	   //vector of ii
typedef vector<vii> vvii;  //vector of vector of ii
typedef vector<int> vi;
typedef vector<vi> vvi;

/*OLHAR TODOS AS POSIÇÔES DO ARRAYS QUE COMEÇAM COM ZERO*/

vvi adjList;
int cases, v, k, a, b, c, origem, destino;

int dijkstra(int v, int source, int destiny){
	vi delay_list(v, INF);
	priority_queue< ii, vii, greater<ii> > qe;
	delay_list[source] = 0;
	qe.push(make_pair(source, 0));
	
	while( !qe.empty() ){

		ii from = qe.top(); qe.pop();
		int d = from.second, u = from.first;
	
		if(d > delay_list[u]) continue;

		for(int i = 1; i < adjList[u].size(); i++){

			ii v = make_pair(i,adjList[u][i]);	

			if(delay_list[u] + v.second < delay_list[v.first]){
				delay_list[v.first] = delay_list[u] + v.second;
				qe.push(ii(v.first,delay_list[v.first]));
			}
		}

	}

	return delay_list[destiny];

}


int main() {
	cin >> cases;
	for (int i = 0; i < cases; ++i)
	{
		cin >> v >> k;
		adjList.resize(v+1);
		for (int j = 0; j < v+1; ++j)
		{
			adjList[j].resize(v+1, INF);
		}
		for (int j = 0; j < k; ++j)
		{
			cin >> a >> b >> c;
			adjList[a][b] = c;
		}

		cin >> origem >> destino;
		int saida = dijkstra(v+1, origem, destino);
		if( saida != INF){
			cout << saida << endl;
		} else {
			cout << "NO\n";
		}

		adjList.clear();
	}
}
