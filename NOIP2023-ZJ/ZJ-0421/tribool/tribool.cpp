#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int inf = 1e9;
const char cc[] = {'T', 'F', 'U'};
int c, t, n, m, ans;
struct node {
	char op;
	int a, b;
} q[MAXN];
char s[MAXN], tt[MAXN];
char back(char c)
{
	if (c == 'T') return 'F';
	if (c == 'F') return 'T';
	if (c == 'U') return c;
}
void dfs(int pos, int cnt)
{
	if (cnt >= ans) return;
	if (pos == n + 1)
	{
		for (int i = 1; i <= n; i++)
			tt[i] = s[i];
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			if (q[i].op == '+')
			{
				a = q[i].a, b = q[i].b;
				tt[a] = tt[b];
			}
			else if (q[i].op == '-')
			{
				a = q[i].a, b = q[i].b;
				tt[a] = back(tt[b]);
			}
			else
			{
				a = q[i].a;
				tt[a] = q[i].op;
			}
		}
		for (int i = 1; i <= n; i++)
			if (s[i] != tt[i])
				return;
//		for (int i = 1; i <= n; i++)
//			cout << tt[i];
//		cout << endl;
		ans = cnt;
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		s[pos] = cc[i];
		dfs(pos + 1, cnt + (cc[i] == 'U'));
	}
}
void work()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> q[i].op;
		if (q[i].op == '+')
			cin >> q[i].a >> q[i].b;
		else if (q[i].op == '-')
			cin >> q[i].a >> q[i].b;
		else
			cin >> q[i].a;		
	}
	if (c <= 2)
	{
		ans = inf;
		dfs(1, 0);
		cout << ans << endl;
		return;
	}
	else if (c <= 4)
	{
		for (int i = 1; i <= n; i++)
			s[i] = 'A';
		for (int i = m; i >= 1; i--)
			if (s[q[i].a] == 'A')
				s[q[i].a] = q[i].op;
		ans = 0;
		for (int i = 1; i <= n; i++)
			ans += (s[i] == 'U');
		cout << ans << endl;
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
			tt[i] = 'A';
		for (int i = m; i >= 1; i--)
			if (tt[q[i].a] == 'A')
				tt[q[i].a] = q[i].op;
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			if (q[i].op == '+')
			{
				a = q[i].a, b = q[i].b;
				tt[a] = tt[b];
			}
		}
		ans = 0;
		for (int i = 1; i <= n; i++)
			ans += (tt[i] == 'U');
		cout << ans << endl;
		return;
	}
}
signed main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	while(t--)
		work();
	return 0;
}