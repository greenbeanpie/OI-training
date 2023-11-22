#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define mod 998244353
inline LL read()
{
	LL x=0, y=1;
	char ch=getchar();
	for (; ch<'0' || ch>'9'; ch=getchar())
		if (ch=='-') y=-1;
	for (; ch<='9' && ch>='0'; ch=getchar())
		x=(x<<3)+(x<<1)+(ch&15);
	return x*y;
}

#define N 500010
int c, n, m, q;
int a[N], b[N], oa[N], ob[N];

inline void copy_to()
{
	for (int i=1; i<=n; i++) a[i]=oa[i];
	for (int i=1; i<=m; i++) b[i]=ob[i];
}

bool s[2010][2010]; // whether can cover B1~Bi with A1~Aj or not

inline bool can_cover() // actually it's totally wrong, but could pass when n==1 or n==2
{
	if (a[1]==b[1] || a[n]==b[m]) return 0;
	if (a[1]<b[1]) for (int i=1; i<=n; i++) swap(a[i], b[i]);
	if (a[n]<b[m]) return 0;
	for (int i=1; i<=m; i++) s[0][i]=1;
	for (int i=1; i<=m; i++) // Bi
	{
		for (int j=1; j<=n; j++) // Aj
		{
			if (a[j] > b[i]) s[i][j] |= s[i-1][j];
		}
	}
	return s[m][n];
}

inline void solve()
{
	copy_to();
	can_cover() ? putchar('1') : putchar('0');
//	putchar('\n');
	while (q--) // O(QNM)
	{
		int kx=read(), ky=read();
		for (int i=1; i<=kx; i++)
		{
			int px=read(), vx=read(); a[px]=vx;
		}
		for (int i=1; i<=ky; i++)
		{
			int py=read(), vy=read(); b[py]=vy;
		}
		can_cover() ? putchar('1') : putchar('0');
		copy_to();
//		putchar('\n');
	}
}

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c=read(), n=read(), m=read(), q=read();
	for (int i=1; i<=n; i++) oa[i]=read();
	for (int i=1; i<=m; i++) ob[i]=read();
	solve();
	return 0;
}
/*
3 2 2 3
1 6
1 7

2 1
1 2
2 1
2 1

1 0
1 2

2 0
1 2
2 8

1 1
1 2
2 4

*/
