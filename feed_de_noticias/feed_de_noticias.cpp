#include <iostream>
#include <map>


using namespace std;


struct amigo {
	float friendly;
	int id;
};

struct post {
	string message;
	float time;
	amigo dono;
};

typedef map<float, post> postList;

int main(){

	int n, m, x;
	cin >> n;
	cin >> m;
	post u;
	amigo z;
	amigo myFriends[m];

	for (int i = 0; i < m; i++){
		cin >> z.id;
		cin >> z.friendly;
		myFriends[i] = z;

	}

	cin >> x;

	postList myqueue;

	for (int i = 0; i < x; i++){

		cin >> u.dono.id >> u.time;


		getline(cin, u.message);
		
		float postValue;

		for(int j = 0; j < m; j++) {
			if(u.dono.id == myFriends[j].id){
				u.dono = myFriends[j];
				postValue = (u.dono.friendly * 0.8) + (u.time * 0.2);
			}
		}


		myqueue.insert(make_pair(postValue, u));



	}

	int cont = 0;
	for (auto i = myqueue.crbegin(); cont < n; ++i, cont++)	{
		cout << i->second.dono.id
			 << i->second.message << "\n"; 
	}





}