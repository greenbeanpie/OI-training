#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MAX = 1e3 + 5;
const int MOD = 1e9 + 7;
inline int read ();
struct node
{
	int ti;ll v;
} ;
int ty,t,n,m,k,d;
ll ans,dp[MAX][MAX];
vector <node> p[MAX];
vector <ll> sum[MAX];
bool cmp (node x,node y);
ll check (int x,int y);
int main ()
{
	freopen ("run.in","r",stdin);
	freopen ("run.out","w",stdout);
	ty = read ();t = read ();
	while (t--)
	{
		n = read ();m = read ();k = read ();d = read ();
		for (int i = 1;i <= n;++i)
			for (int j = 0;j <= min (n,k);++j) dp[i][j] = -INF;
		ans = -INF;
		for (int i = 1;i <= m;++i)
		{
			int x = read (),y = read (),v = read ();
			p[x].push_back ({x - y + 1,v});
		}
		for (int i = 1;i <= n;++i) sort (p[i].begin (),p[i].end (),cmp);
		for (int i = 1;i <= n;++i)
		{
			if (!p[i].size ()) continue;
			sum[i].push_back (p[i][0].v);
			for (int j = 1;j < p[i].size ();++j) sum[i].push_back (sum[i][j - 1] + p[i][j].v);
		}	
		dp[0][0] = 0;	
		for (int i = 1;i <= n;++i)
		{
			for (int j = 0;j <= min (i,k);++j)
			{
				int l = max (i - j + 1,1),r = i;
				dp[i][0] = max (dp[i][0],dp[i - 1][j]);
				if (j) dp[i][j] = max (dp[i][j],dp[i - 1][j - 1] + check (l,r) - d);
			}
		}
		for (int i = 0;i <= min (n,k);++i) ans = max (ans,dp[n][i]);
		printf ("%lld\n",ans);
		for (int i = 1;i <= n;++i) p[i].clear (),sum[i].clear ();
		for (int i = 1;i <= n;++i)
			for (int j = 0;j <= min (n,k);++j) dp[i][j] = -INF;
	}
	return 0;
}
inline int read ()
{
	int s = 0,f = 1;
	char ch = getchar ();
	while (('0' > ch || ch > '9') && ch != EOF)
	{
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while ('0' <= ch && ch <= '9')
	{
		s = s * 10 + ch - '0';
		ch = getchar ();
	}
	return s * f;
}
bool cmp (node x,node y)
{
	return x.ti < y.ti;
}
ll check (int x,int y)
{
	int l = 0,r = p[y].size () - 1,ans = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (x <= p[y][mid].ti) ans = mid,r = mid - 1;
		else l = mid + 1;
	}
	if (ans == -1) return 0;
	if (ans == 0) return sum[y][sum[y].size () - 1];
	else return sum[y][sum[y].size () - 1] - sum[y][ans - 1];
}
