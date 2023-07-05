#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;


int main(){
	#ifndef ONLINE_JUDGE
		freopen("UVA11576_1.in","r",stdin);
		freopen("UVA11576_1.out","w",stdout);
	#endif
	int T;
	cin >> T;
	while(T--){
		cc_hash_table<int,bool> vis;
		int n,t;
		cin >> n;
		deque<int> q;
		int maxinum=0;
		for(int i=1;i<=n;i++){
			cin >> t;
			if(!vis[t]){
				q.push_front(t);
				vis[t]=true;
			}
			else{
				while(vis[t]){
					vis[q.back()]=false;
					q.pop_back();
				}
				q.push_front(t);
				vis[t]=true;
			}
			maxinum=max(maxinum,(int)q.size());
		}
		cout << maxinum<<"\n";
	}
}