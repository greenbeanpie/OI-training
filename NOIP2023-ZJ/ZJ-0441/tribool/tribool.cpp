#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
inline int read ();
int ty,t,n,m,cnt,ans,vis[MAX],a[MAX],b[MAX],st[MAX];
//st[i] for i,the priority
char str[30][2];int x[30],y[30];
vector <pair <int,int> > ve[MAX];
void dfs (int u,int ti);
void solve (int x);
bool check ();
int main ()
{
	freopen ("tribool.in","r",stdin);
	freopen ("tribool.out","w",stdout);
	ty = read ();t = read ();
	if (ty <= 2)
	{
		while (t--)
		{
			n = read ();m = read ();ans = INF;
			for (int i = 1;i <= m;++i)
			{
				scanf ("%s",str[i]);x[i] = read ();
				if (str[i][0] == '+' || str[i][0] == '-') y[i] = read ();
			}
			solve (1);
			printf ("%d\n",ans);
		}
		return 0;
	}
	while (t--)
	{
		n = read ();m = read ();cnt = 0;
		for (int i = 1;i <= n;++i) a[i] = 0,st[i] = 0,ve[i].clear ();
		for (int i = 1;i <= m;++i)
		{
			char s[2];scanf ("%s",s);
			if (s[0] == '+')
			{
				int x = read (),y = read ();
				ve[y].push_back ({x,i});
				st[x] = i;
				for (int j = 1;j <= n;++j) vis[j] = 0;
				dfs (y,i);
			}
			else if (s[0] == '-')
			{
				int x = read (),y = read ();
			}
			else
			{
				int x = read ();
				if (s[0] == 'T') a[x] = 1;
				if (s[0] == 'F') a[x] = 2;
				if (s[0] == 'U') a[x] = 3;
				if (ty >= 5)
				{
					st[x] = i;
					for (int j = 1;j <= n;++j) vis[j] = 0;
					dfs (x,i);	
				}			
			}
		}
		for (int i = 1;i <= n;++i)
			if (a[i] == 3) ++cnt;
		printf ("%d\n",cnt);
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
void dfs (int u,int ti)
{
	vis[u] = 1;
	for (int i = 0;i < ve[u].size ();++i)
	{
		int v = ve[u][i].first;
		if (vis[v] || st[v] != ve[u][i].second) continue;
		a[v] = a[u];//st[v] = ti;
		dfs (v,ti);
	}
}
void solve (int x)
{
	if (x == n + 1)
	{
		if (check ())
		{
			int sum = 0;
			for (int i = 1;i <= n;++i) sum += (a[i] == 3);
			ans = min (ans,sum);
		}
		return ;
	}
	for (int i = 1;i <= 3;++i) a[x] = i,solve (x + 1);
}
bool check ()
{
	for (int i = 1;i <= n;++i) b[i] = a[i];
	for (int i = 1;i <= m;++i)
	{
		if (str[i][0] == '+') b[x[i]] = b[y[i]];
		else if (str[i][0] == '-')
		{
			if (b[y[i]] == 3) b[x[i]] = b[y[i]];
			else b[x[i]] = 3 - b[y[i]];
		}
		else
		{
			if (str[i][0] == 'F') b[x[i]] = 1;
			if (str[i][0] == 'T') b[x[i]] = 2;
			if (str[i][0] == 'U') b[x[i]] = 3;
		}
	}
	for (int i = 1;i <= m;++i)
		if (a[i] != b[i]) return 0;
	return 1;
}
