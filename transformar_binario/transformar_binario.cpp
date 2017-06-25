#include <iostream>
#include <stack>
using namespace std;

stack<int> binario(int n, stack<int> pilha){
	if(n == 0){
		return pilha;
	} else {
		pilha.push(n%2);
		return binario(n/2, pilha);
	}
}

int main(){
	int x;
	cin >> x;
	stack<int> s;
	s = binario(x, s);
	if(s.empty()){
		cout << 0 << endl;
	} else {
		while(!s.empty())
		{
			cout << s.top() << endl;
			s.pop();
		}
	}

}