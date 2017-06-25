#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector< vector<int> > v;
	vector<string> minas;

	int a = 1,b = 1;
	string campo;
	int field = 1;

	while(a != 0 && b != 0){
		cin >> a >> b;
				

		v.resize(a);
		minas.resize(a);

		for(int i = 0; i < a; i++){
			v[i].resize(b,0);		
			cin >> minas[i];
		}

		cout << "Field #" << field << endl;
		field++;


		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				
				if (minas[i][j] == '*' ){		
					v[i+1][j]++;
					v[i-1][j]++;
					v[i][j+1]++;
					v[i][j-1]++;
					v[i+1][j+1]++;
					v[i+1][j-1]++;
					v[i-1][j+1]++;
					v[i-1][j-1]++;
				}

				cout << v[i][j];
			}	
			cout << endl;	
		}
	}
} 