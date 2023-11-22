#include<bits/stdc++.h>
using namespace std;

#define int long long

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

bool Max_if;

int C, t, n, m, k, d, Max = -0x7fffffff;

int a[1005], b[1005], c[1005];

int s[1005];

inline void check()
{
//	for(int i = 1; i <= n; ++ i ) cout << s[i]-s[i - 1] << " ";
//	cout << endl;
	
	int ans = -(s[n] * d);
	for(int i = 1; i <= m; ++ i )
	{
		if(s[a[i]] - s[a[i] - b[i]] == b[i]) ans += c[i];
	}
	
//	cout << ans << " " << Max << endl;
	if(Max_if == 0) 
	{
		Max_if = 1;
		Max = ans;
	}
	else{
		Max = max(Max, ans);
	}
	
}

inline void dfs(int p)
{
	if(p == n + 1) 
	{
		
		check();
		return;
	}
	s[p] = s[p - 1] + 1;
	if(s[p] - s[p - k - 1] <= k) dfs(p + 1);
	//!!p- k   ---> p-k-1
	s[p] = s[p - 1];
	dfs(p + 1);
}
signed main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	C = read(), t = read();
	while(t --)
	{
		n = read(), m = read(), k = read(), d = read();
		for(int i = 1; i <= m; ++ i )
		{
			a[i] = read();
			b[i] = read();
			c[i] = read();
		}
		Max = 0; 
		Max_if = 0;
		for(int i = 0; i <= n; ++ i ) s[i] = 0;
		dfs(1);
		cout << Max << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

