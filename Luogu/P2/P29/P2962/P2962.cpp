#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

struct node
{
	int now = 0, time = 0;
};

int n, m;
vector<int> e[36];
int status,light[36];
bool vis[36];
cc_hash_table<int, int> ht;
int ans = 0x3f3f3f;

void dfs1(int dep, int last)
{
	if (ht[status] == 0)
	{
		ht[status] = dep;
	}
	else
	{
		ht[status] = min(ht[status], dep);
	}
	if (dep == (n + 1) / 2)
	{
		return;
	}
	for (int i = last + 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			for (int j : e[i])
			{
				if (status & (1ll << (j - 1)))
				{
					status -= 1ll << (j - 1);
				}
				else
				{
					status += 1ll << (j - 1);
				}
			}
			if (!ht[status] || ht[status] > dep + 1)
				dfs1(dep + 1, i);
			for (int j : e[i])
			{
				if (status & (1ll << (j - 1)))
				{
					status -= 1ll << (j - 1);
				}
				else
				{
					status += 1ll << (j - 1);
				}
			}
			vis[i] = false;
		}
	}
}
void dfs2(int dep, int last)
{
	if (ht[status])
	{
		ans = min(ans, ht[status] + dep);
		return;
	}
	if (dep == (n + 1) / 2)
	{
		return;
	}
	for (int i = last + 1; i <= n; i++)
	{
		if (vis[i])
		{
			vis[i] = false;
			for (int j : e[i])
			{
				if (status & (1ll << (j - 1)))
				{
					status -= 1ll << (j - 1);
				}
				else
				{
					status += 1ll << (j - 1);
				}
			}
			dfs1(dep + 1, i);
			for (int j : e[i])
			{
				if (status & (1ll << (j - 1)))
				{
					status -= 1ll << (j - 1);
				}
				else
				{
					status += 1ll << (j - 1);
				}
			}
			vis[i] = true;
		}
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P2962.in", "r", stdin);
	freopen("P2962.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		e[i].push_back(i);
		int ans=0;
		for(int j:e[i]){
			ans+=(1<<(j-1));
		}
	}
	dfs1(0, 0);
	fill(vis, vis + n + 1, 1);
	status = (1ll << n) - 1;
	dfs2(0, 0);
	cout << ans;
	return 0;
}