#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int c, T, n, m, ans = 1e9;
char x[N], str[N], lim[N];
int ch[N], nw[N], to[N];

void dfs(int now, int sum)
{
	if(now == n + 1)
	{
		for(int i = 1;i <= n;i++) str[i] = x[i];
		for(int i = 1;i <= m;i++)
		{
			if(lim[i] == 'T' || lim[i] == 'F' || lim[i] == 'U') str[nw[i]] = lim[i];
			else if(lim[i] == '+') str[nw[i]] = str[to[i]];
			else if(lim[i] == '-')
			{
				if(str[to[i]] == 'U') str[nw[i]] = 'U';
				else if(str[to[i]] == 'F') str[nw[i]] = 'T';
				else if(str[to[i]] == 'T') str[nw[i]] = 'F';
			}
		}
		for(int i = 1;i <= n;i++)
			if(x[i] != str[i]) return;
		ans = min(ans, sum);
		return;
	}
	
	x[now] = 'T', dfs(now + 1, sum);
	x[now] = 'F', dfs(now + 1, sum);
	x[now] = 'U', dfs(now + 1, sum + 1);
}

void solve()
{
	ans = 1e9;
	for(int i = 1;i <= m;i++)
	{
		cin >> lim[i] >> nw[i];
		if(lim[i] == '+' || lim[i] == '-') cin >> to[i];
	}
	dfs(1, 0);
	cout << ans << '\n';
}

signed main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> m;
		for(int i = 0;i <= n;i++) ch[i] = 0, x[i] = 'A';
		if(n <= 10 && m <= 10)
		{
			solve();
			continue;
		}
		for(int i = 1;i <= m;i++)
		{
			char op;
			int t1, t2;
			cin >> op;
			if(op == 'T' || op == 'F' || op == 'U')
			{
				cin >> t1;
				x[t1] = op;
				ch[t1] = 0;
			}
			else if(op == '+')
			{
				cin >> t1 >> t2;
				if(x[t2] != 'A')
				{
					x[t1] = x[t2];
					ch[t1] = 0;
				}
				else if(ch[t2])
				{
					ch[t1] = ch[t2];
					if(ch[t1] == -1 * t1) x[t1] = 'U';
					if(x[abs(ch[t2])] == 'U') x[t1] = 'U';
				}
				else
				{
					ch[t1] = t2;
					if(ch[t1] == -1 * t1) x[t1] = 'U';
				}
			}
			else if(op == '-')
			{
				cin >> t1 >> t2;
				if(x[t2] == 'T')
				{
					x[t1] = 'F';
					ch[t1] = 0;
				}
				else if(x[t2] == 'F')
				{
					x[t1] = 'T';
					ch[t1] = 0;
				}
				else if(x[t2] == 'U')
				{
					x[t1] = 'U';
					ch[t1] = 0;
				}
				else if(ch[t2])
				{
					ch[t1] = -1 * ch[t2];
					if(ch[t1] == -1 * t1) x[t1] = 'U';
					if(x[abs(ch[t2])] == 'U') x[t1] = 'U';
				}
				else 
				{
					ch[t1] = -1 * t2;
					if(ch[t1] == -1 * t1) x[t1] = 'U';;
				}
			}
		}
		int sum = 0;
		for(int i = 1;i <= n;i++)
		{
			if(x[i] == 'U' || ch[i] == -1 * i)
			{
				sum++;
				x[i] = 'U'; 
			}
			else if((x[abs(ch[i])] == 'U' || ch[abs(ch[i])] == -1 * ch[abs(ch[i])]) && ch[i] != 0)
			{
				sum++;
				x[abs(ch[i])] = 'U';
			}
//			cout << i << " " << x[i] << " " << ch[i] << '\n';
		}
		cout << sum << '\n';
	}
	
	return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2
*/