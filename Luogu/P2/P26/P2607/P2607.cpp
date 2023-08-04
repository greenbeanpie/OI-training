#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"

constexpr int N = 200005;
int f[N][2], val[N], vis[N], fa[N], nowroot, sum;
vector<int> e[N];

inline void dp(int u)
{
	vis[u] = 1;
	f[u][0] = 0;
	f[u][1] = val[u];
	for (int to : e[u])
	{
		if (to != nowroot)
		{
			dp(to);
			f[u][0] += max(f[to][1], f[to][0]);
			f[u][1] += f[to][0];
		}
		else
		{
			f[to][1] = LLONG_MIN;
		}
	}
}
void circle(int u)
{
	vis[u] = 1;
	nowroot = u;
	while (!vis[fa[nowroot]])
	{
		nowroot = fa[nowroot];
		vis[nowroot] = 1;
	}
	dp(nowroot);
	int tempans = max(f[nowroot][0], f[nowroot][1]);
	vis[nowroot] = 1;
	nowroot = fa[nowroot];
	dp(nowroot);
	sum += max(tempans, max(f[nowroot][0], f[nowroot][1]));
}

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
	int v;
	for(int i=1;i<=n;i++){
		cin >> val[i] >> v;
		e[v].push_back(i);
		fa[i]=v;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			circle(i);
		}
	}
	cout << sum;
	return 0;
}