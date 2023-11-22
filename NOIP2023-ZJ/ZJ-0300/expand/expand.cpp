#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ct,n,m,q;
const int M=5e5+10;
int a[M],b[M],c[M],d[M];
struct Node
{
	int p,v;
}cx[M],cy[M];
bool ys;
void dfs(int x,int y,int f)
{
//	printf("%d %d\n",x,y);
	if(x>=n&&y>=m)
	{
		ys=1;
		return;
	}
	if(ys)return;
	if(x<n&&(c[x+1]-d[y])*f>0)dfs(x+1,y,f);
	if(y<m&&(c[x]-d[y+1])*f>0)dfs(x,y+1,f);
}
//int mxc[M],mnc[M],mxd[M],mnd[M];
void solve()
{
	if((ll)(c[1]-d[1])*(c[n]-d[m])<=0)
	{
		printf("0");
		return;
	}
	int f=1;//1+ -1- 
	if(c[1]-d[1]<0)f=-1;
	ys=0;
	dfs(1,1,f);
	if(ys)printf("1");
	else printf("0");
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&ct,&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),c[i]=a[i];
	for(int i=1;i<=m;++i)scanf("%d",&b[i]),d[i]=b[i];
	solve();
	while(q--)
	{
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=kx;++i)
		{
			scanf("%d%d",&cx[i].p,&cx[i].v);
			c[cx[i].p]=cx[i].v;
		}
		for(int i=1;i<=ky;++i)
		{
			scanf("%d%d",&cy[i].p,&cy[i].v);
			d[cy[i].p]=cy[i].v;
		}
		solve();
		for(int i=1;i<=kx;++i)c[cx[i].p]=a[cx[i].p];
		for(int i=1;i<=ky;++i)d[cy[i].p]=b[cy[i].p];
	}
	return 0;
}
