#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
const int inf = 1e9;
int c, n, m, q;
int x[MAXN], y[MAXN];
int prexmi[MAXN], preymi[MAXN];
int prexma[MAXN], preyma[MAXN];
int l1[MAXN], l2[MAXN];
signed main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
srand(time(0));
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= m; i++) cin >> y[i];
	if (c == 1)
	{
		int num = 1 - (x[1] == y[1]);
		cout << num;
		while(q--)
		{
			int k1, k2, a, b;
			cin >> k1 >> k2;
			while(k1--)
			{
				cin >> a >> b;
				x[a] = b;
			}
			while(k2--)
			{
				cin >> a >> b;
				y[a] = b;
			}
			num = 1 - (x[1] == y[1]);
			cout << num;
		}
		return 0;
	}
	else if (c == 2)
	{
		int num = 1;
		if ((x[1] - y[1]) * (x[n] - y[m]) <= 0) num = 0;
		cout << num;
		while(q--)
		{
			int k1, k2, a, b;
			cin >> k1 >> k2;
			while(k1--)
			{
				cin >> a >> b;
				x[a] = b;
			}
			while(k2--)
			{
				cin >> a >> b;
				y[a] = b;
			}
			if ((x[1] - y[1]) * (x[n] - y[m]) <= 0) num = 0;
			cout << num;
		}
		return 0;
	}
	int lim = (x[1] - y[1]) / abs(x[1] - y[1]);
	int TT = 10000, FFFF = 0;
	while(TT--)
	{
		int flag = 1, len = 0;
		for (int i = 1; i <= n; i++) l1[i] = max(1, rand() % (m + m) + 1), len += l1[i];
		int now = 1;
		for (int i = 1; i <= len; i++)
		{
			int j = i;
			if (i > m) j = m;
			if ((x[now] - y[j]) / abs(x[now] - y[j]) != lim)
			{
				flag = 0;
				break;
			}
			l1[now]--;
			if (!l1[now])now++;
		}
		if (flag){FFFF = 1; break;}
	}
	cout << FFFF;
	while(q--)
	{
		int k1, k2, a, b;
		cin >> k1 >> k2;
		while(k1--)
		{
			cin >> a >> b;
			x[a] = b;
		}
		while(k2--)
		{
			cin >> a >> b;
			y[a] = b;
		}
		lim = (x[1] - y[1]) / abs(x[1] - y[1]);
	TT = 10000, FFFF = 0;
	while(TT--)
	{
		int flag = 1, len = 0;
		for (int i = 1; i <= n; i++) l1[i] = max(1, rand() % (m + m) + 1), len += l1[i];
		int now = 1;
		for (int i = 1; i <= len; i++)
		{
			int j = i;
			if (i > m) j = m;
			if ((x[now] - y[j]) / abs(x[now] - y[j]) != lim)
			{
				flag = 0;
				break;
			}
			
			l1[now]--;
			if (!l1[now])now++;
		}
		if (flag){FFFF = 1; break;}
	}
	cout << FFFF;
	}
//	int num = 1;
//	if ((x[1] - y[1]) * (x[n] - y[m]) <= 0) num = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			
//		}
//	}
//	cout << num;
//	else
//	{
//		int num = 1;
//		if ((x[1] - y[1]) * (x[n] - y[m]) <= 0) num = 0;
//		int ff = (x[1] - y[1]) / abs(x[1] - y[1]);
//		prexmi[0] = inf, preymi[0] = inf;
//		prexma[0] = -inf, preyma[0] = -inf;
//		for (int i = 1; i <= n; i++)
//			prexmi[i] = min(prexmi[i - 1], x[i]),
//			prexma[i] = max(prexma[i - 1], x[i]);
//		for (int i = 1; i <= m; i++)
//			preymi[i] = min(preymi[i - 1], y[i]),
//			preyma[i] = max(preyma[i - 1], y[i]);
//		if (n <= m)
//		{
//			for (int i = 1; i <= m; i++)
//			{
//				
//			}
//		}
//		cout << num;
//		while(q--)
//		{
//			int k1, k2, a, b;
//			cin >> k1 >> k2;
//			while(k1--)
//			{
//				cin >> a >> b;
//				x[a] = b;
//			}
//			while(k2--)
//			{
//				cin >> a >> b;
//				y[a] = b;
//			}
//			num = 1 - (x[1] == y[1]);
//			cout << num;
//		}
//		return 0;
//	}
	return 0;
}
// gl & hf