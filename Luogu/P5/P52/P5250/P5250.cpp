#include <bits/stdc++.h>
using namespace std;
int main(){
	set<int> s;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int op;
		cin >> op;
		if(op==1){
			int l;
			cin >> l;
			if(!s.insert(l).second){
				cout << "Already Exist" << endl;
			}
		}
		else{
			int l;
			cin >> l;
			if(s.empty()){
				cout << "Empty" << endl;
				continue;
			}
			if(s.find(l)!=s.end()){
				cout << l << endl;
				s.erase(s.find(l));
			}
			auto mi1=s.lower_bound(l);
			auto ma1=s.upper_bound(l);
			
			if((mi1==s.end()||*mi1>l)&&mi1!=s.begin()){
				mi1--;
			}
			if(ma1==s.end()){
				ma1--;
			}
			int ma=*ma1;
			int mi=*mi1;
			if(abs(mi-l)==abs(ma-l)||abs(mi-l)<abs(ma-l)){
				cout << mi << endl;
				s.erase(mi1); 
			}
			else{
				cout << ma << endl;
				s.erase(ma1);
			}
		}
	}
} 
