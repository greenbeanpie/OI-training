#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int c, n, m, q, kx, ky, p, v; bool f;
int X[N], Y[N], x[N], y[N];

void dfs1(int i1, int i2)
{
	if(x[i1] <= y[i2] || f) return;
	if(i1 == n && i2 == m)
	{
		f = true;
		return;
	}
	dfs1(i1 + 1, i2);
	dfs1(i1, i2 + 1);
	dfs1(i1 + 1, i2 + 1);
}

void dfs2(int i1, int i2)
{
	if(x[i1] >= y[i2] || f) return;
	if(i1 == n && i2 == m)
	{
		f = true;
		return;
	}
	dfs2(i1 + 1, i2);
	dfs2(i1, i2 + 1);
	dfs2(i1 + 1, i2 + 1);
}

int main()
{
	
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);	
	
	cin >> c >> n >> m >> q;
	if(c == 1 || c == 2)
	{
		for(int i = 1 ; i <= n ; i ++) cin >> X[i];
		for(int i = 1 ; i <= m ; i ++) cin >> Y[i];
		if(n == 1) X[ ++ n] = X[1];
		if(m == 1) Y[ ++ m] = Y[1];
		if((X[1] > Y[1] && X[2] > Y[2]) || (X[1] < Y[1] && X[2] < Y[2])) cout << 1;
		else cout << 0;
		while(q --)
		{
			for(int i = 1 ; i <= n ; i ++) x[i] = X[i];
			for(int i = 1 ; i <= m ; i ++) y[i] = Y[i];
			cin >> kx >> ky;
			for(int i = 1 ; i <= kx ; i ++)
			{
				cin >> p >> v;
				x[p] = v;
			}
			for(int i = 1 ; i <= ky ; i ++)
			{
				cin >> p >> v;
				y[p] = v;
			}
			if((x[1] > y[1] && x[2] > y[2]) || (x[1] < y[1] && x[2] < y[2])) cout << 1;
			else cout << 0;
		}
		return 0;
	}
	for(int i = 1 ; i <= n ; i ++) cin >> X[i], x[i] = X[i];
	for(int i = 1 ; i <= m ; i ++) cin >> Y[i], y[i] = Y[i]; 
	if(x[1] > y[1] && x[n] > y[m])
	{
		f = false;
		dfs1(1, 1);
		if(f) cout << 1;
		else cout << 0;
	}
	else if(x[1] < y[1] && x[n] < y[m])
	{
		f = false;
		dfs2(1, 1);
		if(f) cout << 1;
		else cout << 0;
	}
	else cout << 0;	
	while(q --)
	{
		for(int i = 1 ; i <= n ; i ++) x[i] = X[i];
		for(int i = 1 ; i <= m ; i ++) y[i] = Y[i];
		cin >> kx >> ky;
		for(int i = 1 ; i <= kx ; i ++)
		{
			cin >> p >> v;
			x[p] = v;
		}
		for(int i = 1 ; i <= ky ; i ++)
		{
			cin >> p >> v;
			y[p] = v;
		}
		if(x[1] > y[1] && x[n] > y[m])
		{
			f = false;
			dfs1(1, 1);
			if(f) cout << 1;
			else cout << 0;
		}
		else if(x[1] < y[1] && x[n] < y[m])
		{
			f = false;
			dfs2(1, 1);
			if(f) cout << 1;
			else cout << 0;
		}
		else cout << 0;	 
	}	
	return 0;
}
