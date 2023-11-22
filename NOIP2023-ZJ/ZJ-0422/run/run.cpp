#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100002;
int n, m, p, q, a[N], b[N], c[N], d[N], ans, cnt, sum, tot, C, T, run[N];
void dfs(int x, int y)
{
	if(y > p) return;
	if(x > n)
	{
		sum = 0;
		for (int i = 1; i <= n; i++) sum = sum - q * run[i];
		for (int i = 1; i <= m; i++)
		{
			int flag = 1;
			for (int j = a[i] - b[i] + 1; j <= a[i]; j++)
			{
				if(run[j] == 0)
				{
					flag = 0;
					break;
				}
			}
			if(flag == 1) sum = sum + c[i];
		}
		ans = max(ans, sum);
		return;
	}
	run[x] = 1;
	dfs(x + 1, y + 1);
	run[x] = 0; 
	dfs(x + 1, 0);
}
void sub1()
{
	while (T--)
	{
		ans = -1e18;
		cin >> n >> m >> p >> q;
		for (int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> c[i];
		dfs(1, 0);
		cout << ans << endl;
	}
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin >> C >> T;
	if(C <= 2) { sub1(); return 0; }
	return 0;
}
/*
1 2
3 2 2 1
2 2 4
3 2 3
3 2 2 1
2 2 4
3 2 3
*/
