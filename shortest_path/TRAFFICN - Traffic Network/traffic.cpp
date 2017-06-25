#include <bits/stdc++.h>
using namespace std;
 
const int INF = (2 << 20);

typedef pair<int, int> ii; 
typedef vector<ii> vii;	   //vector of ii
typedef vector<vii> vvii;  //vector of vector of ii
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adjList;
int cases, v, k, t, a, b, c, j,origem, destino;

int dijkstra(int v, int source, int destiny){
	vi delay_list(v, INF);
	priority_queue< ii, vii, greater<ii> > qe;
	delay_list[source] = 0;
	qe.push(make_pair(source, 0));
	while( !qe.empty() ){
		ii from = qe.top(); qe.pop();
		int d = from.second, u = from.first;	
		if(d > delay_list[u]) continue;
		for(int i = 0; i < adjList[u].size(); i++){
			ii v = make_pair(i,adjList[u][i]);	
			if(delay_list[u] + v.second < delay_list[v.first]){
				delay_list[v.first] = delay_list[u] + v.second;
				qe.push(ii(v.first,delay_list[v.first]));
			}
		}
	}

	return delay_list[destiny];

}

int readint() {
    int n = 0;
    char c = getchar_unlocked();
    while ( !( '0' <= c && c <= '9' ) ) {
        c = getchar_unlocked();
    }
    while ( '0' <= c && c <= '9' ) {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

int main() {
	cin >> cases;
	while (cases--){
		//cin >> v >> j >> k >> origem >> destino;
		v = readint();
		j = readint();
		k = readint();
		origem = readint();
		destino = readint();

		adjList.resize(v+1);
/*		for (int i = 0; i <= v; ++i)
		{
			adjList[i].resize(v+1, INF);
		}*/
		
		for (int i = 1; i <= j; ++i)
		{
			//cin >> a >> b >> c;
			a = readint();
			b = readint();
			c = readint();
			if(adjList[a].size() == 0) adjList[a].resize(v+1, INF);
			adjList[a][b] = c;
		}

		int oneWayResult = dijkstra(v+1, origem, destino);

		for (int i = 1; i <= k; ++i)
		{
			//cin >> a >> b >> c;
			a = readint();
			b = readint();
			c = readint();
			if(adjList[a].size() == 0) adjList[a].resize(v+1, INF);
			adjList[a][b] = c;
			if(adjList[b].size() == 0) adjList[b].resize(v+1, INF);
			adjList[b][a] = c;
		}

//		adjList = oneWay;
		int twoWayResult = dijkstra(v+1, origem, destino);

		if(oneWayResult == INF || twoWayResult == INF){
			cout << -1 << endl;
		} 
		else {
			if(oneWayResult > twoWayResult){
				cout << twoWayResult << endl;
			} else{
				cout << oneWayResult << endl;
			}
		}
		adjList.clear();
	}
}
