#include <iostream>

using namespace std;

int reverse(string string, int fim){
	cout << string[fim-1];
	if(fim == 0){
		return 0;
	} else {
		return reverse(string, fim-1);
	}
}


int main(){
	string in;
	getline(cin, in);
	reverse(in, in.size());
}