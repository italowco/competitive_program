#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

int cases, v, k, t, a, b, c, j,origem, destino;
vvii adjList;

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
			ii v = adjList[u][i];
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


int main(){
	cases = readint();
		while(cases--){
			//cin >> v >> j >> k >> origem >> destino;
			v = readint();
			j = readint();
			k = readint();
			origem = readint();
			destino = readint();

			adjList.resize(v+1);

			for (int i = 1; i <= j; ++i)
			{
				//cin >> a >> b >> c;
				a = readint();
				b = readint();
				c = readint();
				adjList[a].push_back(make_pair(b,c));
			}

			int oneWayResult = dijkstra(v+1, origem, destino);

			for (int i = 1; i <= k; ++i)
			{
				//cin >> a >> b >> c;
				a = readint();
				b = readint();
				c = readint();
				adjList[a].push_back(make_pair(b,c));
				adjList[b].push_back(make_pair(a,c));
			}

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