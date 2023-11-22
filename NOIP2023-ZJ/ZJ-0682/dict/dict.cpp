#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define N 3010
#define M 3010
#define inf 0x3f3f3f
int n, m;
int c;
string s;
int a[N][5], ans[N];

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		a[i][0] = inf, a[i][1] = -1;
	for(int i = 1; i <= n; i ++)
	{
		cin >> s;
		for(int j = 0; j < m; j ++)
		{
			c = s[j] - 'a';
			a[i][0] = min(a[i][0], c);
			a[i][1] = max(a[i][1], c);
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		bool flag = true;
		for(int j = 1; j <= n; j ++)
		{
			if(i == j)
				continue;
			if(a[i][0] >= a[j][1])
				flag = false;
		}
		if(flag)
			ans[i] = 1;
		else
			ans[i] = 0;
	}
	for(int i = 1; i <= n; i ++)
		cout << ans[i];
	return 0;
}
