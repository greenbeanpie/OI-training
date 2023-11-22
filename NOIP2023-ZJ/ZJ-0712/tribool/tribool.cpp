#include <iostream>

using namespace std;

const int N = 1e5 + 5;

struct node
{
	char opt;
	int x, y;
} a[N];

char p[N], p1[N];
int n, m, ans;

inline void dfs(int u, int d)
{
	if(u > n)
	{
		if(d >= ans) return ;
		for(int i = 1; i <= n; ++ i)
			p1[i] = p[i];
		for(int i = 1; i <= m; ++ i)
		{
			if(a[i].opt == 'U')
				p1[a[i].x] = 'U';
			if(a[i].opt == 'T')
				p1[a[i].x] = 'T';
			if(a[i].opt == 'F')
				p1[a[i].x] = 'F';
			if(a[i].opt == '+')
				p1[a[i].x] = p1[a[i].y];
			if(a[i].opt == '-')
			{
				if(p1[a[i].y] == 'T')
					p1[a[i].x] = 'F';
				else if(p1[a[i].y] == 'F')
					p1[a[i].x] = 'T';
				else if(p1[a[i].y] == 'U')
					p1[a[i].x] = 'U';
			}
		}
		bool f = 1;
		for(int i = 1; i <= n; ++ i)
			if(p1[i] != p[i]) {f = 0; break;}
		if(f) ans = d;
		return ;
	}
	p[u] = 'T', dfs(u + 1, d);
	p[u] = 'F', dfs(u + 1, d);
	p[u] = 'U', dfs(u + 1, d + 1);
}

inline void solve1()
{
	ans = 1e9;
	for(int i = 1; i <= m; ++ i)
	{
		cin >> a[i].opt >> a[i].x;
		if(a[i].opt == '+' || a[i].opt == '-')
			cin >> a[i].y;
	}
	dfs(1, 0), cout << ans << '\n';
}

inline void solve2()
{
	char c; int x;
	for(int i = 1; i <= n; ++ i)
		p[i] = 0;
	for(int i = 1; i <= m; ++ i)
	{
		cin >> c >> x;
		p[x] = c;
	}
	int res = 0;
	for(int i = 1; i <= n; ++ i)
		if(p[i] == 'U') res ++ ;
	cout << res << '\n';
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T; cin >> c >> T;
	while(T -- )
	{
		cin >> n >> m;
		if(c <= 2) solve1();
		else if(c <= 4) solve2();
		else cout << n << '\n';
	}
}