#include <iostream>

using namespace std;

int mdc(int a, int b){
	
	if(a > b){
		if(a%b == 0){
			 return b;
		}
		else {
			return	mdc(a%b, b);
		}
	} 
	else {
		if(b%a == 0) {
			return a;
		}
		else {
			return	mdc(b%a, a);
		}
	}
}


int main() {
	int a, b;	
	cin >> a >> b;
	cout << mdc(a,b) << endl;
}