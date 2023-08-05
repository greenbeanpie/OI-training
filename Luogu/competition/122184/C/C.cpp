#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#ifndef ONLINE_JUDGE
#define cc_hash_table unordered_map
#endif
vector<int> e[1000005];
int dep[1000005], dep2[1000005];
int ht[1000005];
bool vis[1000005];
multiset<int, greater<int>> s;
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int u, v;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	dep[1] = 1;
	vis[1]=1;
	int maxdep = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i : e[now])
		{
			if (!vis[i])
			{
				vis[i]=1;
				dep[i] = dep[now] + 1;
				if (e[i].size())
				{
					q.push(i);
				}
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		s.insert(dep[i]);
		sum += dep[i];
	}
	if (sum % 2 == 1)
	{
		cout << -1;
		return 0;
	}
	sum /= 2;
	for (int i : s)
	{
		if (sum - i >= 0)
		{
			sum -= i;
			++ht[i];
		}
		if (!sum)
		{
			break;
		}
	}
	if (sum)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (ht[dep[i]])
		{
			--ht[dep[i]];
			cout << 0 << " ";
		}
		else
		{
			cout << 1 << " ";
		}
	}
	return 0;
}