#include <bits/stdc++.h>
 
using namespace std;
  
int queens[8], caminho[8];
  
bool visitado(int r, int c) {
    for(int j = 0; j < r; j++) {
        if(c == caminho[j]) 
            return false;
        if(abs(r - j) == abs(c - caminho[j])) 
            return false;
    }
    return true;
}
  
int backtrack(int n) {
    if(n == 8) {
        return 0;
    }

    int dist = 100000;
  
    for(int i = 0; i < 8; i++)
        if(visitado(n, i)) {
            caminho[n] = i;
            if(i == queens[n]){
                dist = min(dist, backtrack(n + 1));  
            }
            else {
                dist = min(dist, 1 + backtrack(n + 1));
            }
        }
  
    return dist;
}
  
int main() {
    int times = 0;
    while(++times){
        for(int i = 0; i < 8; i++) {
            if(scanf("%d", &queens[i]) == -1) 
                return 0;
            queens[i]--; caminho[i] = queens[i];
        }

        printf("Case %d: %d\n", times, backtrack(0));
    }
}