#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;

struct node
{
	int x, y, c;
	bool operator < (const node &b)const
	{
		return x < b.x;
	}
};

int c, T, n, m, k, d, ans;
int f[2][N], s[N], vis[N];
node chl[N];

void dfs(int now, int sum)
{
	if(now == n + 1)
	{
		int tot = sum;
		for(int i = 1;i <= m;i++)
		{
			int r = chl[i].x, l = chl[i].x - chl[i].y + 1;
			if(s[r] - s[l - 1] == r - l + 1) tot += chl[i].c;
		}
		ans = max(ans, tot);
		return;
	}
	
	if(s[now - 1] - s[now - k - 1] == k)
	{
		dfs(now + 1, sum);
		return;
	}
	s[now] = s[now - 1] + 1;
	dfs(now + 1, sum - d);
	s[now]--;
	dfs(now + 1, sum);
}

void dfs1(int now)
{
	if(now == n + 1) return;
	dfs1(now + 1);
	if(chl[now].y > k || chl[now].y * d >= chl[now].c)
	{
		f[1][now] = -1e15;
		f[0][now] = max(f[0][now + 1], f[1][now + 1]);
	}
	if(chl[now].x == chl[now + 1].x - chl[now + 1].y)
	{
		f[1][now] = max(f[1][now], f[0][now + 1] + chl[now].c - chl[now].y * d);
		f[0][now] = max(f[1][now + 1], f[0][now + 1]);
	}
}

signed main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> T;
	while(T--)
	{
		ans = 0;
		memset(s, 0, sizeof s);
		memset(f, 0, sizeof f);
		cin >> n >> m >> k >> d;
		for(int i = 1;i <= m;i++) cin >> chl[i].x >> chl[i].y >> chl[i].c;
		sort(chl + 1, chl + m + 1);
		if(n <= 19 && m <= 100)
		{
			dfs(1, 0);
			cout << ans << '\n';
			continue;
		}
		ans = 0;
		for(int i = 1;i <= m;i++)
		{
			if(chl[i].y > k || chl[i].y * d >= chl[i].c)
			{
				f[1][i] = -1e15;
				f[0][i] = max(f[0][i - 1], f[1][i - 1]);
			}
			else if(chl[i].x - chl[i].y == chl[i - 1].x)
			{
				f[1][i] = max(f[1][i], f[0][i - 1] + chl[i].c - chl[i].y * d);
				f[0][i] = max(f[1][i - 1], f[0][i - 1]);
			}
			else
			{
				f[1][i] = max(f[1][i - 1], f[0][i - 1]) + chl[i].c - chl[i].y * d;
				f[0][i] = f[1][i];
			}
		}
		cout << max(f[0][m], f[1][m]) << '\n';
	}
	
	return 0;
}
/*
1 1 
3 2 2 1
2 2 4
3 2 3
*/