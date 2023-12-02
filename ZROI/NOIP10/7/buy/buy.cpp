#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 5, M = 26;

multiset<int> s[N];

int num[N][M], costs[M], ans[M];

int n, m;

int minans = LLONG_MAX;

double st = clock();

void dfs(int now, int cost, int lastans)
{
	minans = min(minans, lastans);
	if (clock() - st >= 3.9 * CLOCKS_PER_SEC)
	{
		cout << minans << endl;
		exit(0);
	}
	if (now == m + 1)
	{
		return;
	}
	dfs(now + 1, cost, lastans);
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		s[i].insert(num[i][now]);
		res += *s[i].begin();
	}
	res += cost + costs[now];
	if (res >= lastans)
	{
		cerr << "Genshin" << endl;
	}
	else
	{
		dfs(now + 1, cost + costs[now], res);
	}
	for (int i = 1; i <= n; i++)
	{
		// res -= *s[i].begin();
		s[i].erase(s[i].find(num[i][now]));
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("buy.in", "r", stdin);
	freopen("buy.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	// FastIO::read(n, m);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> num[i][j];
			// FastIO::read(num[i][j]);
			// s[j].insert(num[j][i]);
			// sum[i] += num[j][i];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> costs[i];
		// FastIO::read(costs[i]);
	}
	dfs(1, 0, LLONG_MAX);
	cout << minans << endl;
	// FastIO::write(minans);
	// FastIO::flush();
	return 0;
}
