#include <iostream>

using namespace std;

int fibo(int a, int vetor[]){
	if (a == 0){
		
		return vetor[0] = 0;
	}
	else if (a == 1|a == 2){
		vetor[1] = 1;
		vetor[2] = 1;
		return 1;
	}
	else if (vetor[a] == 0) {
		return vetor[a] = fibo(a - 1, vetor) + fibo(a - 2, vetor);
	}  

}

int main()
{
	int x;
	int v[200];

	cin >> x;
	while(x != 0){
		for (int i = 0; i < 200; i++)
		{
			v[i] = 0;
		}
		for (int i = 0; i < x; i++)
		{
			if(i == x-1) cout << fibo(i, v) << endl;
			else cout << fibo(i, v) << " ";			
		}
		cin >> x;
	}
}