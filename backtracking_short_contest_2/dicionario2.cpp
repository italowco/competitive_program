#include <bits/stdc++.h>

using namespace std;

int n, m;

string regra;
vector<string> palavras(200);
string digitos[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

void backtrack(int regraM, string resultado){
	/*printf("Na função bt\n");*/
	if(regraM == regra.size()){
		/*cout << "Entrei no resuldado\n";*/
		cout << resultado << endl;
	}
	else if(regra[regraM] == '#'){
		/*cout << "Entrei no else if\n";*/
		for (int i = 0; i < n; ++i)
		{
			/*printf("Loop do else if\n");*/	
			backtrack(regraM + 1, resultado + palavras[i]);
		}
	}
	else {
		/*cout << "Entrei no else\n";*/
		for (int i = 0; i < 10; ++i)
		{
			backtrack(regraM + 1, resultado + digitos[i]);
		}
	}

}

int main(){
	while(scanf("%d", &n) != EOF){
		printf("--\n");
		for (int i = 0; i < n; ++i)
		{	
			cin >> palavras[i];
		}
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
		{
			cin >> regra;
			backtrack(0,"");
		}
	}
}