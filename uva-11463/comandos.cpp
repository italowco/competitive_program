#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii; 
typedef vector<ii> vii;	   //vector of ii
typedef vector<vii> vvii;  //vector of vector of ii
typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 0x3f3f3f3f;
vvi adjMat;

int T, N, R, a, b;

void floy_marshall(int V){
	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
			}
		}
	}
}


int main(){
	cin >> T;
	int cases = 0;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		cin >> R;
		adjMat.resize(N);

		for (int j = 0; j < N; ++j)
		{
			vi *x = new vi(N, INF);
			adjMat[j] = *x;
			adjMat[j][j] = 0;
		}
		for (int j = 0; j < R; ++j)
		{
			cin >> a >> b;
			adjMat[a][b] = 1;
			adjMat[b][a] = 1;
		}

		cin >> a >> b;
		floy_marshall(N);

    int minTime = 0;
    for (int j = 0; j < N; ++j)
    {
        if (adjMat[a][j] != INF 
            && adjMat[j][b] != INF)
        {
            minTime = max(minTime, adjMat[a][j] + adjMat[j][b]);
        }
     }

		printf("Case %d: %d\n", ++cases, minTime);
		adjMat.clear();
	}
}

