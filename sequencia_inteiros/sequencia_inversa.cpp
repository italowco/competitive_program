#include <iostream>
#include <stack>
using namespace std;

int sequencia(int n, int cont){
	
	if(cont%2 == 0){
		cout << cont << endl;
	}

	if(cont == 0){
		return 0;
	}
	else {
		return sequencia(n, cont-1);
	}
}
int main() {
	int a;
	cin >> a;
	sequencia(a, a);
}