#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int c, T, n, m, ans;
int a[N], b[N];
char op[N]; int x[N], y[N];

void work(int res)
{
	for(int i = 1 ; i <= n ; i ++)
		b[i] = a[i];
	for(int i = 1 ; i <= m ; i ++)
	{
		if(op[i] == 'T') b[x[i]] = 1;
		else if(op[i] == 'F') b[x[i]] = -1;
		else if(op[i] == 'U') b[x[i]] = 0;
		else if(op[i] == '+') b[x[i]] = b[y[i]];
		else b[x[i]] = -b[y[i]];
	}
	for(int i = 1 ; i <= n ; i ++)
		if(a[i] != b[i]) return;
	ans = min(ans, res);
}

void dfs(int x, int s)
{
	if(s > ans) return;
	if(x > n)
	{
		work(s);
		return;
	}
	a[x] = 1;
	dfs(x + 1, s);
	a[x] = -1;
	dfs(x + 1, s);
	a[x] = 0;
	dfs(x + 1, s + 1);
}

int main()
{
	
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);	
	
	cin >> c >> T;
	
	if(c == 1 || c == 2 || c == 9 || c == 10)
	{
		while(T --)
		{
			cin >> n >> m;
			for(int i = 1 ; i <= m ; i ++)
			{
				cin >> op[i];
				if(op[i] == '+' || op[i] == '-') cin >> x[i] >> y[i];
				else cin >> x[i];
			}
			ans = N;
			dfs(1, 0);
			cout << ans << "\n";
		}
	}
	if(c == 3 || c == 4)
	{
		int pos; char opt;
		while(T --)
		{
			scanf("%d%d", &n, &m);
			for(int i = 1 ; i <= n ; i ++) a[i] = 0;
			for(int i = 1 ; i <= m ; i ++)
			{
				cin >> opt;
				scanf("%d", &pos);
				if(opt == 'U') a[pos] = 1;
				else a[pos] = 0;
			}
			int ans = 0;
			for(int i = 1 ; i <= n ; i ++)
				ans += a[i];
			printf("%d\n", ans);
		}		
	}
	
	return 0;
}
