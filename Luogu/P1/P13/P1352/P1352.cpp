#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"

bool isroot[6005];
int val[6005],f[6005][2];
vector<int> e[6005];

void dp(int u){
	for(int i:e[u]){
		dp(i);
		f[u][0]+=max(f[i][0],f[i][1]);
		f[u][1]+=f[i][0];
	}
	f[u][1]+=val[u];
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P1352.in","r",stdin);
	freopen("P1352.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fill(isroot,isroot+6005,1);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >> val[i];
	}
	int u,v;
	for(int i=1;i<n;i++){
		cin >> u >> v;
		e[v].push_back(u);
		isroot[u]=0;
	}
	int root;
	for(int i=1;i<=n;i++){
		if(isroot[i]){
			root=i;
			break;
		}
	}
	dp(root);
	cout << max(f[root][0],f[root][1]);
	return 0;
}