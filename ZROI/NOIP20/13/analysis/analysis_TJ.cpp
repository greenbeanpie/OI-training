#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

template <typename T>
bool chkmin(T &x, T y) { return x > y ? x = y, 1 : 0; }
template <typename T>
bool chkmax(T &x, T y) { return x < y ? x = y, 1 : 0; }

int readint()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int n, tot;
ll A, B;
int v[1000005], nxt[1000005], h[500005];
ll d[500005][2][2], tmp[2][2];

void addedge(int x, int y)
{
	v[++tot] = y;
	nxt[tot] = h[x];
	h[x] = tot;
	v[++tot] = x;
	nxt[tot] = h[y];
	h[y] = tot;
}

void dfs(int u, int fa)
{
	d[u][0][0] = 0, d[u][1][0] = 1ll << 60;
	d[u][0][1] = d[u][1][1] = 1ll << 60;
	for (int p = h[u]; p; p = nxt[p])
	{
		if (v[p] == fa)
			continue;
		dfs(v[p], u);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				tmp[i][j] = 1ll << 60;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int l = 0; l < 2; l++)
					{
						chkmin(tmp[i ^ 1][k | l | (j == 0)], d[u][i][k] + d[v[p]][j][l] + (j == 0) * B);
						chkmin(tmp[i][k | l | (j == 1)], d[u][i][k] + d[v[p]][j][l] + (j == 1) * B + 2 * A);
					}
				}
			}
		}
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				d[u][i][j] = tmp[i][j];
	}
}

int main()
{
#ifndef CODESPACE
#ifndef ONLINE_JUDGE
	freopen("analysis.in", "r", stdin);
	freopen("analysis.out", "w", stdout);
#endif
#endif
#ifdef CODESPACE
	freopen("analysis.in", "r", stdin);
	freopen("analysis_TJ.out", "w", stdout);
#endif
	n = readint();
	A = readint();
	B = readint();
	for (int i = 1; i < n; i++)
		addedge(readint(), readint());
	dfs(1, -1);
	printf("%lld\n", min(min(d[1][0][0] / 2, d[1][0][1] / 2 - B), (d[1][1][1] - B) / 2));
	return 0;
}