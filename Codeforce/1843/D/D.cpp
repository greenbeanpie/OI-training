#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "D"
#define const constexpr

const int N=2e5+10;
vector<int> e[N];
int sum[N],vis[N];

int dfs(int u){
	vis[u]=1;
	int ans=0;
	for(int i:e[u]){
		if(!vis[i])
			ans+=dfs(i);
	}
	sum[u]=max(1ll,ans);
	vis[u]=0;
	return max(1ll,ans);
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","r",stdin);
	freopen(problemname".out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int u,v;
		for(int i=2;i<=n;i++){
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1);
		int q;
		cin >> q;
		int a,b;
		for(int i=1;i<=q;i++){
			cin >> a >> b;
			cout << sum[a]*sum[b] << endl;
		}
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}
	return 0;
}