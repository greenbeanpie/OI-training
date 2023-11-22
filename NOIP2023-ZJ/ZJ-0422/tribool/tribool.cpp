#include<bits/stdc++.h>
using namespace std;
const int N = 100002;
int n, m, p, q, a[N], b[N], c[N], d[N], ans, cnt, sum, tot, C, T;
char s[N], t[N], r[N], S[5];
void dfs(int x)
{
	if(x > n) 
	{
		sum = 0;
		for (int i = 1; i <= n; i++) r[i] = t[i];
		for (int i = 1; i <= m; i++)
		{
			if(s[i] == '+') t[b[i]] = t[c[i]];	
			else if(s[i] == '-')
			{
				if(t[c[i]] == 'F') t[b[i]] = 'T';
				else if(t[c[i]] == 'T') t[b[i]] = 'F';
				else t[b[i]] = 'U';	
			}
			else t[b[i]] = s[i];
		}
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			if(t[i] == 'U') sum++;
			if(t[i] != r[i])
			{
				flag = 0;
				break;
			}
		}
		if(flag == 1) ans = min(ans, sum);
		for (int i = 1; i <= n; i++) t[i] = r[i];
		return;
	}
	for (int i = 1; i <= 3; i++) 
	{
		t[x] = S[i];
		dfs(x + 1);
	}
}
void sub1()
{
	while (T--)
	{
		cin >> n >> m;
		ans = 250;
		for (int i = 1; i <= m; i++)
		{
			cin >> s[i];
			if(s[i] == '+') cin >> b[i] >> c[i];	
			else if(s[i] == '-') cin >> b[i] >> c[i];
			else cin >> b[i];
		}
		dfs(1);
		cout << ans << endl;
	}
}
void sub2()
{
	while (T--)
	{
		cin >> n >> m; 
		ans = 0;
		for (int i = 1; i <= n; i++) d[i] = 0;
		for (int i = 1; i <= m; i++)
		{
			cin >> s[i];
			if(s[i] == '+') cin >> b[i] >> c[i];	
			else if(s[i] == '-') cin >> b[i] >> c[i];		
			else cin >> b[i];
		}
		for (int i = m; i >= 1; i--)
		{
			if(d[b[i]] == 0)
			{
				d[b[i]] = 1; 
				if(s[i] == 'U') ans++;
			}
		}
		cout << ans << endl;
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin >> C >> T;
	S[1] = 'T'; S[2] = 'F'; S[3] = 'U';
	if(C <= 2) { sub1(); return 0; }
	if(C <= 4) { sub2(); return 0; }
	return 0;
}
/*
1
4
6
3
5
5

2 1
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
*/
