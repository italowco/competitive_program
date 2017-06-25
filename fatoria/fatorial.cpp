#include <iostream>

using namespace std;

int fat(int n, int i = 1){
	if(n == 0) return i;
	else return fat(n - 1, i * n);	
}
int main(){
	int x;
	cin >> x;
	while(x != -1){
		cout << fat(x) << endl;
		cin >> x;
	}
}