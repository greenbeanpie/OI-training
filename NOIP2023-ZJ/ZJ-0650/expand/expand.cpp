#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int c, n, m, q, ka, kb;

int a[2005], b[2005], ta[2005], tb[2005];

bool check()
{
	int l = 1, r = 1;
	bool p, f = 1;
	if(ta[1] - tb[1] > 0) p = 1;
	else if(ta[1] - tb[1] < 0) p = 0;
	if(ta[1] == tb[1]) return false;
		
	while((ta[1] - tb[r] > 0) == p && r <= m) ++ r;
	r -= 1;
	
//	cout << 1 <<":" <<l <<" " << r << endl;
	
	for(int i = 2; i <= n; ++ i )
	{
//		++ l;
		while((ta[i] - tb[l] > 0) != p && l <= r) ++ l;
		if(l > r)
		{
			f = 0;
			break;
		}
		else{
			f = 1;
		}
		while((ta[i] - tb[r] > 0) == p && r <= m) ++ r;
		if((ta[i] - tb[r] > 0) != p) r -= 1;
//		cout << i <<":" <<l <<" " << r << endl;
	}
	if((ta[n] - tb[m] > 0) != p) f = 0;
	return f;
}

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	for(int i = 1; i <= n; ++ i ) a[i] = read();
	for(int i = 1; i <= m; ++ i ) b[i] = read();
	
	for(int i = 1; i <= n; ++ i ) ta[i] = a[i];
	for(int i = 1; i <= m; ++ i ) tb[i] = b[i];
	
	if(check()) cout << 1;
		   else cout << 0;
	
	while(q --)
	{
		for(int i = 1; i <= n; ++ i ) ta[i] = a[i];
		for(int i = 1; i <= m; ++ i ) tb[i] = b[i];
		ka = read(), kb = read();
		while(ka --)
		{
			int x = read(), y = read();
			ta[x] = y;
		}
		while(kb --)
		{
			int x = read(), y = read();
			tb[x] = y;
		}
		if(check()) cout << 1;
		 	   else cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

