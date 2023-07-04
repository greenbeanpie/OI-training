#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long
#define Pii pair<int,int>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
vector<int> e[1005];
unordered_set<int> vis[1005];
int k,n,m;

signed main(){
	#ifdef CODESPACE
		freopen("A.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> k >> n >> m;
	queue<Pii> q;
	int t;
	for(int i=1;i<=k;i++){
		cin >> t;
		q.push({i,t});
		vis[t].insert(i);
	}
	int u,v;
	for(int i=1;i<=m;i++){
		cin >> u >> v;
		e[u].push_back(v);
	}
	while(!q.empty()){
		auto now=q.front();
		q.pop();
		for(int i:e[now.second]){
			if(!vis[i].count(now.first)){
				vis[i].insert(now.first);
				q.push({now.first,i});
			}
		}
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		if(vis[i].size()==k){
			tot++;
		}
	}
	cout << tot;
	return 0;
}