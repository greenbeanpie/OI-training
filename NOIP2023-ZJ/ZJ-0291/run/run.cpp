#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, d, f[2][1000010];
struct node
{
	int x, y, v;
}chall[100010];
void Fre()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	return;
}
inline int max(int x, int y)
{
	return (x > y) ? x : y;
}
inline int read()
{
	int ans = 0, t = 1;
	char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		t = (ch == '-') ? -1 : 1;
	for (; isdigit(ch); ch = getchar())
		ans = (ans << 1) + (ans << 3) + (ch & 15);
	return ans * t;
}
void Read()
{
	n = read();
	m = read();
	k = read();
	d = read();
	for (int i = 1; i <= m; i++)
	{
		chall[i].x = read();
		chall[i].y = read();
		chall[i].v = read();
	}
	return;
}
bool cmp(node a,node b)
{
	return (a.x == b.x) ? a.y < b.y : a.x < b.x;		
}
void Work()
{
	sort(chall + 1, chall + 1 + m, cmp);
	memset(f, 0, sizeof(f));
	int cnt = 1, tmp1, tmp2;
	for (int i = 1; i <= n; i++)
	{
		tmp1 = 0;
		tmp2 = f[i & 1][0];
		for (int j = 1; j <= k; j++)
		{
			if (j > i) break;
			f[i & 1][j] = f[i & 1 ^ 1][j - 1] - d;
			while (chall[cnt].x == i &&  chall[cnt].y == j)
				tmp1 += chall[cnt++].v;
			f[i & 1][j] += tmp1;
			tmp2 = max(tmp2, f[i & 1][j]);
		}
		f[i & 1 ^ 1][0] = tmp2;
	}
	printf("%lld\n", tmp2);
	return;
}
signed main()
{
	Fre();
	int c = read();
	for (int t = read(); t; t--)
	{
		Read();
		Work();
	}
	return 0;
}