#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= (b); i++) 

using namespace std;

const int N = 5e5 + 10;

int x[N], y[N];

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	int c, n, m, q;
	cin >> c >> n >> m >> q;
	rep(i, 1, n) cin >> x[i];
	rep(i, 1, m) cin >> y[i];
	
	int k = x[1] - y[1];
	int p = x[n] - y[m];
	if(k * p > 0) cout << 1;
	else cout << 0;
	
	while(q--)
	{
		int kx, ky;
		cin >> kx >> ky;
		rep(i, 1, kx) 
		{
			int u, v;
			cin >> u >> v;
			x[u] = v;
		}
		
		rep(i, 1, ky)
		{
			int u, v;
			cin >> u >> v;
			y[u] = v;
		}
		
		int k = x[1] - y[1];
		int p = x[n] - y[m];
		if(k * p > 0) cout << 1;
		else cout << 0;
	}
}