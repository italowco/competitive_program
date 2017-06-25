#include <bits/stdc++.h>

using namespace std;

char matriz[30][30];
int n;

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n || matriz[i][j] != '1'){
        
        return;  
    } 
        
    matriz[i][j] = '2';
    dfs(i-1,j-1);
    dfs(i-1,j);
    dfs(i-1,j+1);
    dfs(i,j-1);
    dfs(i,j+1);
    dfs(i+1,j-1);
    dfs(i+1,j);
    dfs(i+1,j+1);
}

int main() {
    int i , j, count, kase = 0;
    while (cin >> n) {
        getchar();
        for (i = 0; i < n; i++){
            cin >> matriz[i];
        }
        count = 0;
        for (i = 0; i < n ;i++){
            for (j = 0; j < n; j++){
                if (matriz[i][j] == '1' ) {
                    count++;
                    dfs(i,j);
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n",++kase,count);
    }
}