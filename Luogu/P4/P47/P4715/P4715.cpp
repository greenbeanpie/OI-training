#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
		freopen("P4715.in","r",stdin);
	#endif
	int n;
	cin >> n;
	queue<int> q;
	int s[(long long)pow(2,n)];
	for(int i=0;i<pow(2,n);i++){
		cin >> s[i];
		q.push(i);
	}
	while(!q.empty()){
		int t1=q.front();
		q.pop();
		int t2=q.front();
		q.pop();
		if(q.empty()){
			if(s[t1]<s[t2]){
				cout << t1+1;
			}
			else{
				cout << t2+1;
			}
			return 0;
		}
		if(s[t1]>s[t2]){
			q.push(t1);
		}
		else{
			q.push(t2);
		}
		
	}
	return 0;
}