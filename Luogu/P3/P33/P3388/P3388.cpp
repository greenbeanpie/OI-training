#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e4 + 5;
int vdcc,dfn[N], low[N], vis[N], nowdfn, cnt;
vector<int> e[N];
void tarjan(int u,bool isroot=false)
{
	int son=0;
	dfn[u]=low[u]=++nowdfn;
	for(int i:e[u]){
		if(!dfn[i]){
			son++;
			tarjan(i);
			low[u]=min(low[u],low[i]);
			if(!isroot&&dfn[u]<=low[i]&&!vis[u]){
				vis[u]=true;
				vdcc++;
			}
		}
		else{
			low[u]=min(low[u],dfn[i]);
		}
	}
	if(son>=2&&isroot&&!vis[u]){
		vis[u]=true;
		vdcc++;
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3388.in", "r", stdin);
	freopen("P3388.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n,m;
	cin >> n >> m;
	int u,v;

	for(int i=1;i<=m;i++){
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i,true);
		}
	}
	cout << vdcc << endl;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			cout << i << " ";
		}
	}
	return 0;
}