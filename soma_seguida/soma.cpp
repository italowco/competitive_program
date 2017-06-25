#include <iostream>

using namespace std;
int soma(int m, int a){
	int n;
	if(m == 0){
		return a;
	} else {
		cin >> n;
		return soma(m-1, a+n);
	}
}

int main()
{
	int x;
	cin >> x;
	cout << soma(x, 0) << endl;
}