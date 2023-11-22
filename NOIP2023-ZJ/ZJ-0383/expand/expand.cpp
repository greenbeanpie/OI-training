#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int c, n, m, q;
int x[N], y[N], sx[N], sy[N];

bool check()
{
	int flag = 0;
	if((x[1] < y[1] && x[n] > y[m]) || (x[1] > y[1] && x[n] < y[m])) return 0;
	if(x[1] == y[1] || x[n] == y[m]) return 0;
	if(x[1] > y[1]) flag = 1;
	int mx = 0, my = 0, mnx = 1e9, mny = 1e9;
	for(int i = 1;i <= n;i++) mx = max(mx, x[i]), mnx = min(mnx, x[i]);
	for(int i = 1;i <= m;i++) my = max(my, y[i]), mny = min(mny, y[i]);
	if(mx == my || mnx == mny) return 0;
	if(flag && (mx < my || mnx < mny)) return 0;
	if(!flag && (mx > my || mnx > mny)) return 0;
	int cnt1 = 1, cnt2 = 1;
	return 1;
}

signed main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> x[i];
		sx[i] = x[i];
	}
	for(int j = 1;j <= m;j++)
	{
		cin >> y[j];
		sy[j] = y[j];
	}
	cout << check();
	while(q--)
	{
		int kx, ky;
		cin >> kx >> ky;
		memcpy(x, sx, sizeof x);
		for(int i = 1;i <= kx;i++)
		{
			int t1, t2;
			cin >> t1 >> t2;
			x[t1] = t2;
		}
		for(int i = 1;i <= ky;i++)
		{
			int t1, t2;
			cin >> t1 >> t2;
			y[t1] = t2;
		}
		cout << check();
	}
	
	return 0;
}