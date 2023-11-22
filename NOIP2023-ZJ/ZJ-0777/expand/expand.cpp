#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,x[500010],y[500010],max1,k,max2,xt[500010],yt[500010];
int check()
{
	int flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if((x[i]-y[j])*k<=0)flag=0;
			}
		}
		if(!flag)cout<<0;
		else cout<<1;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>x[i],xt[i]=x[i];
	for(int i=1;i<=m;i++)cin>>y[i],yt[i]=y[i];
	
	int t1=1,t2=1;
	k=x[1]-y[1];
	if(k<0)k=-1;
	else if(k>0)k=1;
	else k=0;/*
	if(k)while(t1<=n&&t2<=m)
	{
		if((x[t1]-y[t1])*k>0)
	}*/
	if(n==1&&m==1)
	{
		for(int i=1;i<=q+1;i++)cout<<1;
	}
	else if(n<=2&&m<=2)
	{
		check();
		for(int i=1;i<=q;i++)
		{
			for(int j=1;j<=n;j++)x[j]=xt[j];
			for(int j=1;j<=m;j++)y[j]=yt[j];
			int kx,ky,p,v;
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++)
			{
				cin>>p>>v;
				x[p]=v;
				check();
			}
			for(int j=1;j<=ky;j++)
			{
				cin>>p>>v;
				y[p]=v;
				check();
			}
		}
	}
	
}
