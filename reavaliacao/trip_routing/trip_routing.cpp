#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 501;
typedef pair<int, int> ii;
typedef pair<string, int> si; 
typedef vector<ii> vii;	
typedef vector<vii> vvii;
typedef vector<si> vsi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vsi> vvsi;
typedef map<string, int> maps;

string route[MAX][MAX];
int n;
int c[MAX][MAX];
int trace[MAX][MAX];
int tam[MAX];
maps routeMap;
vector<string> name;

int cases, a, b;

void floyd_warshal() {
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				if(c[j][k] > c[j][i] + c[i][k]) {
					c[j][k] = c[j][i] + c[i][k];
					trace[j][k] = trace[j][i];
				}
			}
		}
	}
}

void init(){
	for (int i = 1; i <= MAX - 1; ++i)
	{
		for (int j = 1; j <= MAX - 1; ++j)
		{
			c[i][j] = c[i][j] = INF;
			trace[i][j] = j;
			trace[j][i] = i;
			route[i][j] = route[j][i] = "";
		}
	}
	name.clear();
	name.push_back("TESTE");
	routeMap.clear();
	n = 0;
}


int main()
{
	init();
	string s, citySource, cityDest, r = "";
	int distIn, u, v;
	routeMap.insert(make_pair("Los Angeles", 0));
	getline(cin, s);
	while(s != ""){
		int k = 0, w, v, u ;
		string r = "";
		int a;
		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i] == ','){
				if(k == 0){
					citySource = s.substr(0, i);
					a = i + 1;
					k++;
				}
				else if(k == 1){
					cityDest = s.substr(a, i - a);
					a = i + 1;
					k++;
				}
				else if(k == 2){
					r = s.substr(a, i - a);
					a = i + 1;
					k++;
				}
			}
		}
		string aux = s.substr(a, s.size() - a);
		string::size_type st;
		distIn = stoi(aux, &st);
		
		//cout << citySource << " " << cityDest << " " << r << " " << distIn << endl;


		
		u = routeMap[citySource];
		if(u == 0){
			u = routeMap[citySource] = ++n;
			name.push_back(citySource);
			tam[n] = name[n].length();
		}
				
		v = routeMap[cityDest];
		if(v == 0){
			v = routeMap[cityDest] = ++n;
			name.push_back(cityDest);
			tam[n] = name[n].length();
		}

		if(distIn < c[u][v]){
			c[u][v] = c[v][u] = distIn;
			route[u][v] = route[v][u] = r;
		}

		getline(cin, s);
	}

	floyd_warshal();

	while(getline(cin, s)) {
		int len = s.size();
		int k = 0, a = 0;
		for (int i = 0; i < len; ++i)
		{
			if(s[i] == ','){
				if(k == 0){
					citySource = s.substr(0, i);
					a = i + 1;
					k++;	
				}
			}

		}
		cityDest = s.substr(a, len - a);

		u = routeMap[citySource];
		v = routeMap[cityDest];


	  printf("\n\n");
    puts("From                 To                   Route      Miles");
    puts("-------------------- -------------------- ---------- -----");


    int x, y;
    y = u;

    do {
        cout << name[y];
        for (int i = tam[y]; i < 21; i++) printf(" ");
        x = trace[y][v];
        cout << name[x];
        for (int i = tam[x]; i < 21; i++) printf(" ");
        cout << route[x][y];
        for (int i = route[x][y].size(); i < 11; i++) printf(" ");
        printf("%5d\n", c[x][y]);
        y = x;
    } while (y != v);
 
    puts("                                                     -----");
    printf("                                          Total      ");
    printf("%5d\n", c[u][v]);
	}


}