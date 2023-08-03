#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"

constexpr auto N = 1000005;
int low[N], val[N], to[N], f[N][2];
bool vis[N];
vector<int> circle, e[N];

extern bool tarjan(int u);
extern void solve(int u);
extern void dp(int u);
extern void dp2(int u);


signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P2607.in", "r", stdin);
	freopen("P2607.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i] >> to[i];
		e[i].push_back(to[i]);
		e[to[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!low[i]&&e[i].size()>=3)
		{
			tarjan(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!low[i]&&e[i].size()>=2)
		{
			tarjan(i);
		}
	}
	int ans = 0;
	for (int i : circle)
	{
		solve(i);
		ans += max(f[i][0], f[i][1]);
	}
	cout << ans;
	return 0;
}
bool tarjan(int u)
{
	low[u] = u;
	if (vis[u])
	{
		return false;
	}
	vis[u] = 1;
	if (vis[to[u]])
	{
		low[u] = to[u];
		circle.push_back(to[u]);
	}
	else if (tarjan(to[u]))
	{
		low[u] = low[to[u]];
	}
	
	vis[u] = 0;
	return low[u] != u;
}
void solve(int u)
{
	vis[u]=1;
	for (int i : e[u])
	{
		if (low[i] != i)
		{
			dp2(i);
			f[u][0]=max(f[i][0],f[i][1]);
			f[u][1]=f[i][0]+val[u];
			int temp;
			for(auto j=e[u].begin();j!=e[u].end();j++){
				if(*j!=i){
					temp=*j;
					e[i].erase(j);
					break;
				}
			}
			for(auto j=e[temp].begin();j!=e[temp].end();j++){
				if(*j==u){
					e[temp].erase(j);
					break;
				}
			}
			dp(i);
			f[u][0]=max(max(f[u][0],f[i][0]),f[i][1]);
			break;
		}
	}
	for(int i:e[u]){
		if(low[i]==i){
			dp(i);
			f[u][0]+=max(f[i][0],f[i][1]);
			f[u][1]+=f[i][0];
			break;
		}
	}
}
void dp(int u)
{
	f[u][0]=0;
	f[u][1] = val[u];
	for (int i : e[u])
	{
		if (!vis[i])
		{
			vis[i] = 1;
			dp(i);
			f[u][0] += max(f[i][0], f[u][1]);
			f[u][1] += f[u][0];
		}
	}
}
void dp2(int u)
{
	bool flag=false;
	vis[u] = 1;
	for (int i : e[u])
	{
		if (!vis[i] && low[i] != i)
		{
			flag=true;
			dp2(i);
			f[u][0] += max(f[i][0], f[u][1]);
			f[u][1] += f[u][0];
		}
	}
	vis[u]=0;
	if(flag){
		f[u][1]+=val[u];
	}
}