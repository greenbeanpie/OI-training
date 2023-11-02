#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define int long long
// #pragma GCC optimize(2)

const int N = 3e5 + 5, mod = 998244353;

int n;

set<int> e[N], q;

int /* prework[N], */ in[N], father[N];

void dfs1(int u, int fa = -1)
{
	for (int i : e[u])
	{
		if (i != fa)
		{
			father[i] = u;
			dfs1(i, u);
		}
	}
}

int dfs()
{
	int ans = 0;
	// if(q.size()==1)
	for (auto i = q.begin(); i != q.end(); i++)
	{
		// if (in[i] == 1)
		// {
		// 	--in[i];
		// 	--in[father[i]];
		// 	ans += dfs();
		// 	++in[father[i]];
		// 	++in[i];
		// }
		int val = *i;
		auto temp = *e[val].begin();
		e[temp].erase(val);
		e[val].erase(temp);
		--i;
		q.erase(val);
		if (e[temp].size() == 1)
		{
			q.insert(temp);
		}
		else if(e[temp].size()==0){
			return 1;
			q.erase(temp);
		}
		ans += dfs();
		if (e[temp].size() == 1)
		{
			q.erase(temp);
		}
		else if (e[temp].size() == 0)
		{
			q.insert(temp);
		}
		q.insert(val);
		++i;
		ans %= mod;
		e[val].insert(temp);
		e[temp].insert(val);
	}
	return max(1ll, ans) % mod;
}

int quickpower(int a, int b, int p = mod)
{
	int ans = 1, base = a;
	while (b)
	{
		if (b & 1)
		{
			ans *= base;
			ans %= mod;
		}
		base *= base;
		base %= mod;
		b >>= 1;
	}
	return ans % mod;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("neo.in", "r", stdin);
	freopen("neo.out", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;
	// prework[0] = prework[1] = 1;
	// for (int i = 2; i <= n; i++)
	// {
	// 	prework[i] = i * prework[i - 1] % mod;
	// }

	for (int i = 1, u, v; i < n; i++)
	{
		cin >> u >> v;
		e[u].emplace(v), e[v].emplace(u);
		++in[u], ++in[v];
	}
	bool flag = 1;
	for (int i = 1; i <= n; i++)
	{
		if (e[i].size() > 2)
		{
			flag = 0;
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 1)
		{
			q.insert(i);
		}
	}
	if (flag)
	{
		cout << quickpower(2, n - 1, mod);
	}
	else
	{
		cout << dfs() % mod << endl;
	}
	return 0;
}
