#include <iostream>

using namespace std;

int fibo(int a, int vetor[]){
	if (a == 0){
		
		return vetor[0] = 0;;
	}
	else if (a == 1 | a == 2){
		vetor[1] = 1;
		vetor[2] = 1;
		return 1;
	}
	else {	
		return vetor[a] = vetor[a - 1] + vetor[a - 2];
	}
}

int main()
{
	int x;
	int v[50];
	cin >> x;
	while(x != 0){
		for (int i = 0; i < x; i++)
		{
			if(i == x-1) cout << fibo(i, v) << endl;
			else cout << fibo(i, v) << " ";
		}
		cin >> x;
	}
}