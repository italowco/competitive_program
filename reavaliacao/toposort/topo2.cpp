#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1000000;

typedef vector<int> vi;
typedef vector<vi> vvi;

vector<int> order;
int m, n, indeg[MAX];
vi adjlist[MAX];
set<int>  nextVer;


int counter;


void topo_sort() {
    int u, v;

    counter=0;

    while(!nextVer.empty()) {
        u = *(nextVer.begin());
        nextVer.erase(nextVer.begin());
        order.push_back(u);counter++;
        for(int i=0; i!=adjlist[u].size(); i++) {
            v = adjlist[u][i];
            indeg[v]--;
            if(!indeg[v]) nextVer.insert(v);
        }
    }
}
 
int main() {
    int i, j, k, u, v;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        adjlist[u].push_back(v);
        indeg[v] += 1;
    }
    for(i = 1; i <= n; i++){
        if(!indeg[i]){
            nextVer.insert(i);
        }
    }
    topo_sort();
    
    if(counter != n){
        puts("Sandro fails.");
        
    }else{
        printf("%d", order[0]);
        for(i = 1; i < n; i++){
            printf(" %d", order[i]);
        } 
            printf("\n");    
    }

    
    return 0;
}