#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#ifdef CODESPACE
#pragma GCC optimize("Ofast")
#endif

struct node
{
	int to, val;
	// int dream; // my dream SPFA has broken.
};

const int N = 1005;
vector<node> e[N];

cc_hash_table<int, bool> cnt[N];
int n, m, k, T;

int Genshin(int t, int s = 1) // You're right,but Genshin Impact is a open-world game developed by Mihoyo(Hoyoverse). In the world, you can control the energy of elements, ......(I forgot it), at the same time, to find the truth of the world.
{
	for (int i = 1; i <= n; i++)
	{
		cnt[i].clear();
	}
	queue<node> q;
	q.push({s, k});
	while (q.size())
	{
		auto now = q.front();
		q.pop();
		if (now.to == t)
		{
			continue;
		}
		for (auto i : e[now.to])
		{
			auto cur = now.val - i.val;
			if (cur < 0)
			{
				continue;
			}
			if (!cnt[i.to][cur])
			{
				cnt[i.to][cur] = 1;
				q.push({i.to, cur});
			}
		}
	}
	return cnt[t].size();
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >>
		n >> m >> k >> T;
	for (int i = 1, u, v, val; i <= m; i++)
	{
		cin >> u >> v >> val;
		e[u].push_back({v, val});
		// e[v].push_back({u, val});
	}
	int t;
	while (T--)
	{
		cin >> t;
		cout << Genshin(t) << '\n';
	}
	return 0;
}