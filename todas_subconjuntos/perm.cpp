#include <iostream>

using namespace std;

bool is_solution(int n,int k){
	if (n == k){
		return true;
	} else {
		return false;
	}
}

void backtracking(int a[], int n, int k[], int size){
	int nsolutions[2] = {1, 0};
	int i;

	if(is_solution(size, n)){
	    printf("{");
	    for (i=0; i < size; i++){
	        if (k[i] == 1) printf(" %d",a[i]);
	    }
	    printf(" }\n");
	}
	else {
		n += 1;
		for (i = 0; i <= 1; ++i)
		{
			k[n-1] = nsolutions[i];
			backtracking(a, n, k, size);	
		}
	}
}

int main(){
	int a;
	cin >> a;
	int array[a];
	int saida[a];
	for (int i = 0; i < a; ++i)
	{
		array[i] = i+1;
	}
	backtracking(array, 0, saida, a);


}