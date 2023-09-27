#include <bits/stdc++.h> //T4 BF
using namespace std;
const int N = 1e5 + 5, M = 2e5 + 5;
int h1[N], h2[N], e[M * 2], ipx, ne[M * 2], len[M * 2];
void add(int h[], int u, int v, int l)
{
	e[ipx] = v, ne[ipx] = h[u], len[ipx] = l, h[u] = ipx++;
}
int n, m;
long long dis[N];
typedef pair<long long, int> PLI;
void dij(int h[])
{
	priority_queue<PLI, vector<PLI>, greater<PLI>> q;
	for (int i = 1; i <= n; i++)
		q.push(make_pair(dis[i], i));
	while (q.size())
	{
		int x = q.top().second;
		q.pop();
		for (int i = h[x]; ~i; i = ne[i])
		{
			int y = e[i];
			if (dis[y] > dis[x] + len[i])
			{
				dis[y] = dis[x] + len[i];
				q.push(make_pair(dis[y], y));
			}
		}
	}
}
int main()
{
	freopen("coin.in", "r", stdin);
	freopen("coin.out", "w", stdout);
	memset(h1, -1, sizeof(h1));
	memset(h2, -1, sizeof(h2));
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		add(h1, u, v, l);
		add(h2, v, u, l);
	}
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	dij(h1);
	dij(h2);
	for (int i = 2; i <= n; i++)
	{
		if (dis[i] == dis[0])
			cout << "-1 ";
		else
			cout << dis[i] << " ";
	}
	return 0;
}