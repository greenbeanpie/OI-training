#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int ya[N],yb[N];
int a[N],b[N];
int c,n,m,q;
int work()
{
	if(a[1]>b[m] && a[n]<b[1]) return 0;
	if(a[1]<b[m] && a[n]>b[1]) return 0;
	if(a[1]==b[1] || a[n]==b[m]) return 0;
	return 1;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=m;i++) 
	{
		scanf("%d",ya+i);
		a[i]=ya[i];
	}
	for(int i=1;i<=m;i++) 
	{
		scanf("%d",yb+i);
		b[i]=yb[i];
	}
	cout<<work();
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++) a[j]=ya[j];
		for(int j=1;j<=m;j++) b[j]=yb[j];
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int j=1;j<=kx;j++)
		{
			int u,v;
		    scanf("%d%d",&u,&v);
		    a[u]=v;
		}
		for(int j=1;j<=ky;j++)
		{
			int u,v;
		    scanf("%d%d",&u,&v);
		    b[u]=v;
		}
		cout<<work();
	}
	return 0;
}