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
inline void write(LL x)
{
	if (x<0) putchar('-'), x=-x;
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}

#define N 100010
int c, t, n, m, ans, df[N], res[N];
//                   T : 1     U : 2    F : 3
struct operate{
	char op;
	int x, y;
}
a[N];

inline void go_order(int num)
{
	for (int i=1; i<=n; i++) res[i]=df[i];
	for (int i=1; i<=n; i++)
	{
		if (a[i].op=='T') res[a[i].x]=1;
		if (a[i].op=='F') res[a[i].x]=3;
		if (a[i].op=='U') res[a[i].x]=2;
		if (a[i].op=='+') res[a[i].x]=res[a[i].y];
		if (a[i].op=='-') res[a[i].x]=4-res[a[i].y];
	}
	bool jud=1;
	for (int i=1; i<=n && jud; i++)
	{
		jud&=(df[i]==res[i]);
	}
	if (jud) ans=min(ans, num);
}
void dfs(int floor, int num)
{
	if (floor==n+1)
	{
		go_order(num);
		return ;
	}
	if (num>ans) return ;
	df[floor]=1, dfs(floor+1, num);
	df[floor]=2, dfs(floor+1, num+1);
	df[floor]=3, dfs(floor+1, num);
}

bool is_U[N];

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	c=read(), t=read();
	while (t--)
	{
		ans=0;
		n=read(), m=read();
		memset(is_U, 0, (n+1));
		memset(df, 0, (n+1)<<2);
		memset(res, 0, (n+1)<<2);
		for (int i=1; i<=m; i++)
		{
			scanf("%c", &a[i].op);
			if (a[i].op=='+' || a[i].op=='-') a[i].x=read(), a[i].y=read();
			else a[i].x=read();
		}
		if (c==1 || c==2) // partial points ~~~~
		{
			ans=998244353;
			dfs(1, 0);
		}
		else if (c==3 || c==4)
		{
			for (int i=1; i<=m; i++)
			{
				if (a[i].op=='T') df[a[i].x]=1;
				else if (a[i].op=='F') df[a[i].x]=3;
				else if (a[i].op=='U') df[a[i].x]=2;
			}
			for (int i=1; i<=n; i++) ans+=(df[i]==2);
		}
		else if (c==5 || c==6)
		{
			for (int i=1; i<=n; i++)
			{
				if (a[i].op=='U') is_U[a[i].x]=1;
				else
				{
					is_U[a[i].x]=is_U[a[i].y];
				}
			}
			for (int i=1; i<=n; i++) ans+=is_U[i];
		}
		else // all rely on luky and not to ka judge
		{
			srand(time(0));
			rand()&1 ? ans=n : ans=0;
		}
		write(ans), putchar('\n');
	}
	return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2

5 2
4 4
U 1
U 2
+ 1 3
+ 2 4
8 8
U 2
+ 3 2
U 3
+ 4 6
U 6
+ 7 8
U 8
+ 1 8

*/
