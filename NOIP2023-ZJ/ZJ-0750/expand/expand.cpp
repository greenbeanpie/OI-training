#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;

int c, n, m, q;
int x[maxn], y[maxn];
int x11[maxn], y11[maxn];
int maxx, maxy, minx, miny;
bool flag;
bool visit[5005][5005];

void check(int nowx, int nowy, bool op)
{
	if (flag) return;
	if (nowx == n && nowy == m)
	{
		flag = true;
		return;
	}
	if (nowx > n || nowy > m) return;
	if (op)
	{
		if (x[nowx + 1] > y[nowy] && !visit[nowx + 1][nowy])
		{
			visit[nowx + 1][nowy] = 1;
			check(nowx + 1, nowy, op);
		}
		if (x[nowx] > y[nowy + 1] && !visit[nowx][nowy + 1])
		{
			visit[nowx][nowy + 1] = 1;
			check(nowx, nowy + 1, op);
		}
		if (x[nowx + 1] > y[nowy + 1] && !visit[nowx + 1][nowy + 1])
		{
			visit[nowx + 1][nowy + 1] = 1;
			check(nowx + 1, nowy + 1, op);
		}
	}
	else
	{
		if (x[nowx + 1] < y[nowy] && !visit[nowx + 1][nowy])
		{
			visit[nowx + 1][nowy] = 1;
			check(nowx + 1, nowy, op);
		}
		if (x[nowx] < y[nowy + 1] && !visit[nowx][nowy + 1])
		{
			visit[nowx][nowy + 1] = 1;
			check(nowx, nowy + 1, op);
		}
		if (x[nowx + 1] < y[nowy + 1] && !visit[nowx + 1][nowy + 1])
		{
			visit[nowx + 1][nowy + 1] = 1;
			check(nowx + 1, nowy + 1, op);
		}
	}
}

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> x11[i];
		x[i] = x11[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> y11[i];
		y[i] = y11[i];
	}
	flag = false;
	memset(visit, 0, sizeof(visit));
	check(1, 1, x[1] > y[1]);
	cout << flag;
	while (q--)
	{
		minx = miny = 0x3f3f3f3f;
		maxx = maxy = 0;
		int kx, ky;
		cin >> kx >> ky;
		for (int i = 1; i <= n; i++)
		{
			x[i] = x11[i];
		}
		for (int i = 1; i <= m; i++)
		{
			y[i] = y11[i];
		}
		for (int i = 1; i <= kx; i++)
		{
			int p, v;
			cin >> p >> v;
			x[p] = v;
		}
		for (int i = 1; i <= ky; i++)
		{
			int p, v;
			cin >> p >> v;
			y[p] = v;
		}
		flag = false;
		memset(visit, 0, sizeof(visit));
		check(1, 1, x[1] > y[1]);
		cout << flag;
	}
	return 0;
}
