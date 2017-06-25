#include <bits/stdc++.h>
using namespace std;

int INF = (2 << 20);

typedef pair<int, int> ii; 
typedef vector<ii> vii;	   //vector of ii
typedef vector<vii> vvii;  //vector of vector of ii
typedef vector<int> vi;
typedef vector<vi> vvi;


vvi adjList;

vi dijkstra(int v, int source){
	vi delay_list(v, INF);
	priority_queue< ii, vii, greater<ii> > qe;
	delay_list[source] = 0;
	qe.push(make_pair(source, 0));
	
	while( !qe.empty() ){
		
		ii from = qe.top(); qe.pop();
		int d = from.second, u = from.first;
		if(d > delay_list[u]) continue;
		
		for(int i = 0; i < adjList[u].size(); ++i){
			
			ii v = make_pair(i,adjList[u][i]);
			qe.push(make_pair(u, adjList[u][i]));

			if(delay_list[u] + v.second < delay_list[v.first]){
				delay_list[v.first] = delay_list[u] + v.second;
				qe.push(ii(v.first,delay_list[v.first]));
				cout << "TO AQUI" << v.first;
			}
		}
	}
}

int main(){
	int v, qtV, to, delay;
	cout << "Numero de vertices:\n";
	cin >> v;
	while(v != 0){
		for (int i = 0; i < v; ++i)
		{
			cout << "Numero de arestas para o vertice " << i << ":\n" ;
			cin >> qtV;
			vi *x = new vi(qtV);
			adjList.push_back(*x);
			for (int j = 0; j < qtV; ++j)
			 {
			 	cin >> to >> delay;
			 	adjList[i][to] = delay;
			 }
		}
		cout << "Resolvendo usando dijkstra agora\n";
		int a, b;
		cin >> a >> b;
		dijkstra(a,b);
		cout << "Uma nova entrada";
		cin >> v;
	}
}
