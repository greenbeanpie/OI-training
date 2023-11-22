#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,q,kx,ky,maxx,maxy,minx,miny;
int x[500005],y[500005],yy[500005],xx[500005];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>xx[i];
	for(int i=1;i<=m;i++)
		cin>>yy[i];
	for(int i=1;i<=n;i++)
		x[i]=xx[i];
	for(int i=1;i<=m;i++)
		y[i]=yy[i];
	if((x[1]-y[1]>0 && x[n]-y[m]<0) || (x[1]-y[1]<0 && x[n]-y[m]>0) || x[1]-y[1]==0 || x[n]-y[m]==0)
			cout<<"0";
	else
	{
		if(x[1]>y[1])
		{
			int cnt=1,f=0;
			for(int i=1;i<=n;i++)
			{
				while(y[cnt]<x[i])
				{
					cnt++;
					if(cnt==m)
					{
						f=1;
						break;		
					}
					if(y[cnt]==x[i])
					{
						f=2;
						break;
					}	
				}
				if(f)
					break;	
			}
			if(f==1)
				cout<<"1";
			else
				cout<<"0";
		}
		if(x[1]<y[1])
		{
			int cnt=1,f=0;
			for(int i=1;i<=n;i++)
			{
				while(y[cnt]>x[i])
				{
					cnt++;
					if(cnt==m)
					{
						f=1;
						break;		
					}
					if(y[cnt]==x[i])
					{
						f=2;
						break;
					}	
				}
				if(f)
					break;	
			}
			if(f==1)
				cout<<"1";
			else
				cout<<"0";
		}
		}	
	for(int k=1;k<=q;k++)
	{
		for(int i=1;i<=n;i++)
			x[i]=xx[i];
		for(int i=1;i<=m;i++)
			y[i]=yy[i];
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++)
		{
			int px,v;
			cin>>px>>v;
			x[px]=v;
		}
		for(int i=1;i<=ky;i++)
		{
			int py,v;
			cin>>py>>v;
			y[py]=v;
		}
		if((x[1]-y[1]>0 && x[n]-y[m]<0) || (x[1]-y[1]<0 && x[n]-y[m]>0) || x[1]-y[1]==0 || x[n]-y[m]==0)
		{
			cout<<"0";
			continue;
		}
		if(x[1]>y[1])
		{
			int cnt=1,f=0;
			for(int i=1;i<=n;i++)
			{
				while(y[cnt]<x[i])
				{
					cnt++;
					if(cnt==m)
					{
						f=1;
						break;		
					}
					if(y[cnt]==x[i])
					{
						f=2;
						break;
					}	
				}
				if(f)
					break;	
			}
			if(f==1)
				cout<<"1";
			else
				cout<<"0";
		}
		if(x[1]<y[1])
		{
			int cnt=1,f=0;
			for(int i=1;i<=n;i++)
			{
				while(y[cnt]>x[i])
				{
					cnt++;
					if(cnt==m)
					{
						f=1;
						break;		
					}
					if(y[cnt]==x[i])
					{
						f=2;
						break;
					}	
				}
				if(f)
					break;	
			}
			if(f==1)
				cout<<"1";
			else
				cout<<"0";
		}
	}
	return 0;
}
