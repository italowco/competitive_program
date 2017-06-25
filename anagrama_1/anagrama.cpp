#include <iostream>

using namespace std;

string delSpace(string s){
	for(auto i = s.begin(); i <= s.end() - 1 ; i++){
		*i = tolower(*i);
		if(*i == ' '){
			s.erase(i);
		}
	}
	return s;

}

string reverse(string c,string s, int fim){
	if(fim == 0){
		return c;
	} else {
		if(s.size() > fim - 1){
			s[fim - 1] = tolower(s[fim - 1]);
			c.push_back(s[fim - 1]);
		}
		return reverse(c ,s, fim-1);
	}
}

int main(){
	string in;
	string comp;
	int count;
	cin >> count;
	getchar();
	for (int i = 0; i < count; ++i)
	{
		getline(cin, in);
		
		string n = delSpace(in);
		string a = reverse(comp,n, in.size());
		
		cout << a << " " << n << endl;
		
		if(n.compare(a) == 0){
			cout << "SIM" << endl;
		} else {
			cout << "NAO" << endl;
		}
	}
}