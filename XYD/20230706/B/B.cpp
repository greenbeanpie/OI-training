#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 5;
int dfn[1005], low[1005];
vector<int> e[1005];
vector<int> road;
bool vis[1005];
int mininum=INT_MAX;
void check(){
	auto start=--road.end();
	for(auto i=--(--road.end());i!=--road.begin();i--){
		if(*i==*start){
			mininum=min(mininum,(int)(start-i));
			break;
		}
	}
	return;
}
void dfs(int now)
{
	for (int i : e[now])
	{
		if(vis[i]){
			road.push_back(i);
			check();
			road.pop_back();
			continue;
		}
		else if (!vis[i])
		{
			vis[i]=true;
			road.push_back(i);
			dfs(i);
			road.pop_back();
			vis[i]=false;
		}
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		e[u].push_back(v);
	}
	memset(low,0x3f3f3f,sizeof(vis));
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	if(mininum>1000){
		cout << "-1";
		return 0;
	}
	cout << mininum;
	return 0;
}