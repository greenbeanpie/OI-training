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
int rol[N];
LL c, t, n, m, k, d, ans;
struct challenge{
	int x, y, v;
}
a[N];

void dfs(int floor, int idx, int num)
{
	if (num>k) return ;
	if (floor==n)
	{
//		cout<<' '<<idx<<endl;
		LL ache=0;
		for (int i=1; i<=n; i++)
		{
			if (idx&(1<<(i-1))) rol[i]=rol[i-1]+1, ache-=d;
			else rol[i]=0;
		}
		for (int i=1; i<=m; i++)
		{
			if (rol[a[i].x] >= a[i].y) ache+=a[i].v;
		}
		ans=max(ans, ache);
		return ;
	}
	dfs(floor+1, (idx<<1)|1, num+1);
	dfs(floor+1, idx<<1, 0);
}

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	c=read(), t=read();
	while (t--)
	{
		ans= -(1ll<<62);
		n=read(), m=read(), k=read(), d=read();
		for (int i=1; i<=m; i++)
			a[i].x=read(), a[i].y=read(), a[i].v=read();
		if (n<=20) // not to ka judge :)
			dfs(0, 0, 0);
		else
			ans=0;
		write(ans), putchar('\n');
	}
	return 0;
}
/*

*/
