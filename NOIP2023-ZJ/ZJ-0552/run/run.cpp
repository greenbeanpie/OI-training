#include <bits/stdc++.h>
using namespace std;

#define LL long long
const LL INF = 1e16;

int c, T, n, m, k, d;
LL ans;
struct node{
	LL x, y, v;
} a[100005];
int vis[1000], s[1000];
LL f[1005][1005];

bool cmp(node a, node b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

void work()
{
	LL cnt = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(vis[i]) s[i] = s[i - 1] + 1, cnt ++;
		else s[i] = 0;
	}
	LL res = -cnt * d;
	for(int i = 1 ; i <= m ; i ++)
		if(s[a[i].x] >= a[i].y) res += a[i].v;
	ans = max(ans, res);
}

void dfs(int day, int s)
{
	if(day > n)
	{
		work();
		return;
	}
	dfs(day + 1, 0);
	if(s == k) return;
	vis[day] = 1;
	dfs(day + 1, s + 1);
	vis[day] = 0;
}

int main()
{
	
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);	
	
	scanf("%d%d", &c, &T);
	if(c == 1 || c == 2)
	{
		while(T --)
		{
			scanf("%d%d%d%d", &n, &m, &k, &d);
			for(int i = 1 ; i <= m ; i ++)
				scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].v);
			ans = 0;
			dfs(1, 0);
			printf("%lld\n", ans);
		}
	}
	if(c >= 3 && c <= 9)
	{
		while(T --)
		{
			scanf("%d%d%d%d", &n, &m, &k, &d);
			for(int i = 1 ; i <= m ; i ++)
				scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].v);
			sort(a + 1, a + 1 + m, cmp);
			for(int i = 0 ; i <= n ; i ++)
			{
				for(int j = 0 ; j <= k ; j ++)
				{
					f[i][j] = -INF;
				}
			}
			for(int i = 0 ; i <= n ; i ++) f[i][0] = 0;
			int l = 1; 
			for(int i = 0 ; i < n ; i ++)
			{
				LL v = 0;
				for(int j = 0 ; j <= min(i, k) ; j ++)
				{
					while(l <= m && a[l].x <= i + 1 && a[l].y <= j + 1) v += a[l ++].v;
					f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + v - d);
					f[i + 1][0] = max(f[i + 1][0], f[i][j]); 
				}
			}
			ans = 0;
			for(int i = 0 ; i <= k ; i ++) ans = max(ans, f[n][i]);
			cout << ans << "\n";
		}
	}
	if(c == 17 || c == 18)
	{
		while(T --)
		{
			scanf("%d%d%d%d", &n, &m, &k, &d);
			ans = 0;
			for(int i = 1 ; i <= m ; i ++)
			{
				scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].v);
				if(a[i].y <= k && a[i].y * d < a[i].v)
					ans += a[i].v - a[i].y * d;
			}
			printf("%lld\n", ans);
		}
	}
	
	return 0;
}
