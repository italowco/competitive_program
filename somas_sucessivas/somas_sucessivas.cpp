#include <iostream>

using namespace std;

int soma(int n, int m, int a){
	if(m == 0){
		return a;
	} else {
		return soma(n, m-1, a+n);
	}
}

int main() {
	int x, y;
	cin >> x >> y;

	cout << soma(x, y, 0);
	

	return 0;
}