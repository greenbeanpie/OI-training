#include <iostream>

using namespace std;

const int N = 5e5 + 5;

int c, n, m, q, top;
int a[N], b[N], a1[N], b1[N], stk[N], lma[N], lmi[N];

inline int read()
{
	char c = getchar();
	int f = 1, sum = 0;
	while(c < '0' || c > '9')
	{
		if(c == '-') f = -f;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		sum = (sum << 1) + (sum << 3) + (c ^ 48);
		c = getchar();
	}
	return sum * f;
}

inline bool check()
{
	bool f = 1; int j = 1;
	for(int i = 1; i <= m; ++ i)
	{
		while(j && a[j] <= b[i]) j = lma[j];
		if(!j) {f = 0; break;}
		while(j < n && a[j] > b[i]) j ++ ;
	}
	while(f && j <= n)
	{
		if(a[j] <= b[m]) {f = 0; break;}
		j ++ ;
	}
	if(f) return 1; f = 1, j = 1;
	for(int i = 1; i <= m; ++ i)
	{
		while(j && a[j] >= b[i]) j = lmi[j];
		if(!j) {f = 0; break;}
		while(j < n && a[j] < b[i]) j ++ ;
	}
	while(f && j <= n)
	{
		if(a[j] >= b[m]) {f = 0; break;}
		j ++ ;
	}
	if(f) return 1;
	return 0;
}

inline void init()
{
	top = 0;
	for(int i = 1; i <= n; ++ i)
	{
		while(top && a[stk[top]] <= a[i]) top -- ;
		lma[i] = stk[top], stk[ ++ top] = i;
	} top = 0;
	for(int i = 1; i <= n; ++ i)
	{
		while(top && a[stk[top]] >= a[i]) top -- ;
		lmi[i] = stk[top], stk[ ++ top] = i;
	}
}

inline void solve1()
{
	init();
	if(check()) putchar('1');
	else putchar('0');
	for(int i = 1; i <= q; ++ i)
	{
		for(int i = 1; i <= n; ++ i)
			a[i] = a1[i];
		for(int i = 1; i <= m; ++ i)
			b[i] = b1[i];
		int k1, k2, p, v;
		k1=  read(), k2 = read();
		for(int i = 1; i <= k1; ++ i)
			p = read(), v = read(), a[p] = v;
		for(int i = 1; i <= k2; ++ i)
			p = read(), v = read(), b[p] = v;
		if(k1) init();
		if(check()) putchar('1');
		else putchar('0');
	}
}

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	for(int i = 1; i <= n; ++ i)
		a[i] = read(), a1[i] = a[i];
	for(int i = 1; i <= m; ++ i)
		b[i] = read(), b1[i] = b[i];
	solve1();
}