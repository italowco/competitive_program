#include <iostream>
#include <stack>
using namespace std;

int main(){
	int n;
	string s;


	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i)
	{
		stack<char> p,c;
		getline(cin, s);

		for(auto i = s.begin(); i != s.end(); ++i){
			
			if(*i == '('){
				p.push(*i);
			} else if(*i == ')'){
				if(p.empty()){
					p.push(*i);
				} else if (!p.empty()){
					p.pop();
				}
			}

			if(*i == '['){
				c.push(*i);
			} else if(*i == ']'){
				if(c.empty()){
					c.push(*i);
				} else if (!c.empty()){
					c.pop();
				}
			}

		}
		
		if((p.empty() == false) || (c.empty() == false)){
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}



}