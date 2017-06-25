#include <bits/stdc++.h>

using namespace std;

void analisa_regra(vector<string> palavra, vector<string> rules, int nPalavra, int nRegra, int n, int m){
	cout << "Entrei na função" << endl;
	
	if(n == nPalavra || m == nRegra){
		cout << "Encerrei aqui" << endl;
	}
	else{
		cout << "ENTREI NO ELSE" << endl;
		for (int i = 0; i < 10; ++i)
		{

			vector<string>::iterator dicionario = palavra.begin();
			
			for (auto j = rules[nRegra].begin(); j != rules[nRegra].end(); ++j)
			{
				//Imprimir palavras do array de palavras
				if(*j == '#'){

					cout << *dicionario;
					if (dicionario == palavra.end())
					{
						dicionario = palavra.begin();
					}
					else{
						++dicionario;
					}
					
				}
				else if(*j == '0'){

					cout << i;
				}
			}
			
			cout << endl;

		}

		analisa_regra(palavra, rules, nPalavra+1, nRegra, n, m);
		analisa_regra(palavra, rules, nPalavra, nRegra+1, n, m);

	}	
}


int main()
{
	int n;
	while(scanf("%d", &n) != EOF){
		gets
		vector<string> dictionary(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> dictionary[i];
		}
		int m;
		cin >> m;
		
		vector<string> rules(m);
		for (int i = 0; i < m; ++i)
		{
			cin >> rules[i];
		}
		analisa_regra(dictionary, rules, 0, 0, n, m);
	}

}