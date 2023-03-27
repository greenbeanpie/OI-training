#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	unordered_map<string,int> m;
	for(int i=0;i<t;i++){
		int op;// 是的就是OP 
		cin >> op;
		if(op==1){
			string a;
			int b;
			cin >> a >> b;
			m[a]=b;
			cout << "OK" << endl;}
		else if(op==2){
				string a;
				cin >> a;
				if(!m.count(a)){
					cout << "Not found" << endl;
				}
				else{
					cout << m[a] << endl;
				}
				}
		else if(op==3){
				string a;
				cin >> a;
				if(!m.count(a)){
					cout << "Not found" << endl;
				}
				else{
					m.erase(m.find(a));
					cout << "Deleted successfully" << endl;
				}
			}
		else{
				cout << m.size() << endl;
				}
		
	}
	return 0;
} 
