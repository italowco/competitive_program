#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;
char charToInt(int c)
{
    switch (c)
    {
    case 10:
    	return 'A';
    case 11:
    	return 'B';
    case 12:
    	return 'C';
    case 13:
    	return 'D';
    case 14:
    	return 'E';
    case 15:
    	return 'F';
    default:
    	return c;
    }
}

int main(){

	int vezes;
	cin >> vezes;

	for (int i = 0; i < vezes; ++i)
	{
		stack<int> pilha;
		int base;
		int entrada;

		cin >> entrada >> base;

		while(entrada != 0){
			pilha.push(entrada%base);
			entrada = entrada/base;
		}

		while(!pilha.empty()){
			
			if(pilha.top() > 9){
				cout << charToInt(pilha.top());
			} else {
				cout << pilha.top();

			}

			pilha.pop();
		}

		cout << endl;		/* code */
	}


}

