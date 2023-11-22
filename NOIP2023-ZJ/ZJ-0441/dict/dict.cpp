#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 3e3 + 5;
const int MOD = 1e9 + 7;
inline int read ();
int n,m,mx[MAX],mn[MAX];char s[MAX][MAX];
int main ()
{
	freopen ("dict.in","r",stdin);
	freopen ("dict.out","w",stdout);
	n = read ();m = read ();
	for (int i = 1;i <= n;++i) mn[i] = INF;
	for (int i = 1;i <= n;++i) scanf ("%s",s[i] + 1);
	for (int i = 1;i <= n;++i)
		for (int j = 1;j <= m;++j)
			mx[i] = max (mx[i],s[i][j] - 'a'),mn[i] = min (mn[i],s[i][j] - 'a');
	for (int i = 1;i <= n;++i)
	{
		int ok = 1;
		for (int j = 1;j <= n;++j)
		{
			if (i == j) continue;
			if (mn[i] >= mx[j]) {ok = 0;break;}
		}
		if (ok) printf ("1");
		else printf ("0");
	}
	puts ("");
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
