#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;

int n, m;
char s[N][N], ss[N][N];

int work(int now)
{
	for(int i = 1;i <= n;i++)
	{
		if(i == now) continue;
		for(int j = 1;j <= m;j++)
		{
			if(s[now][j] < ss[i][j]) break;
			else if(s[now][j] > ss[i][j]) return 0;
		}
	}
	return 1;
}

signed main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> s[i][j];
			ss[i][j] = s[i][j];
		}
		sort(s[i] + 1, s[i] + m + 1);
		sort(ss[i] + 1, ss[i] + m + 1, greater<int>());
	}
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	
	for(int i = 1;i <= n;i++)
	{
		cout << work(i);
	}
	
	return 0;
}