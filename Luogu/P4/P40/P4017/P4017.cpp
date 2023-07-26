#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

vector<int> e[5005];
int in[5005],max_val[5005];
queue<int> q;

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P4017.in","r",stdin);
	freopen("P4017.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int u,v;
	for(int i=1;i<=m;i++){
		cin >> u >> v;
		e[u].push_back(v);
		in[v]++;
	}
	for(int i=1;i<=n;i++){
		if(!in[i]){
			q.push(i);
			max_val[i]=1;
		}
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i:e[now]){
			max_val[i]+=max_val[now];
			max_val[i]%=80112002;
			if(!--in[i]){
				q.push(i);
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(e[i].empty()){
			sum+=max_val[i];
			sum%=80112002;
		}
	}
	cout <<sum%80112002;
	return 0;
}