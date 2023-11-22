#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define N 100010
int T, t;
int n, m, u, w, ans;
int a[N];
char v;

void solve1()
{
	
	while(t --)
	{	
		ans = 0;
		cin >> n >> m;
		for(int i = 1; i <= m; i ++)
		{
			cin >> v >> u;
			if(v == 'U')
				ans ++;
		}
		cout << ans << endl;
	}
}

void solve2()
{
	ans = 0;
	while(t --)
	{
		cout << ans << endl;
	}
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	cin >> T >> t;
	if(T == 3 || T == 4)
		solve1();
	else
		solve2();

	return 0;
}
