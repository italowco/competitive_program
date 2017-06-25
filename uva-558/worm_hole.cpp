#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair<int, int> ii; 
typedef vector<ii> vii;	
typedef vector<vii> vvii;  
typedef vector<int> vi;
typedef vector<vi> vvi;

int cases, v, k, a, b, c;
vvii adjList;

void bellman_ford(int v, int s){
	vi dist(v, INF);
	dist[s] = 0;

	for (int i = 0; i < v-1; i++)
	{
		for (int u = 0; u < v; u++)
		{
			for (int j = 0; j < adjList[u].size(); j++)
			{
				ii v = adjList[u][j];
				dist[v.first] = min(dist[v.first], dist[u] + v.second);
			}
		}
	}
	bool hasCycle = false;
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < adjList[i].size(); ++j)
		{
			ii v = adjList[i][j];
			if(dist[v.first] > dist[i] + v.second){
				hasCycle = true;
			}
		}
	}

	printf("%s\n", hasCycle ? "possible" : "not possible");
}


int main()
{
	cin >> cases;
		while(cases--){
			cin >> v >> k;

			adjList.resize(v);

			for (int i = 0; i < k; ++i)
			{
				cin >> a >> b >> c;
				adjList[a].push_back(make_pair(b,c));
			}

			bellman_ford(v, 0);

			adjList.clear();

		}
}