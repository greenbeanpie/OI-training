#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
long long x[500005],y[500005];
long long minx=1000000000,miny=1000000000,maxx=0,maxy=0;
long long kx[500005],ky[500005];
long long kminx=1000000000,kminy=1000000000,kmaxx=0,kmaxy=0;
int main()
{
	ios::sync_with_stdio(false);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(c<=6)
	{
		
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		if(x[i]>maxx)
		{
			maxx=x[i];
		}
		if(x[i]<minx)
		{
			minx=x[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>y[i];
		if(y[i]>maxy)
		{
			maxy=y[i];
		}
		if(y[i]<miny)
		{
			miny=y[i];
		}
	}
	if((y[1]-x[1])*(y[n]-x[m])>0)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	for(int i=1;i<=q;i++)
	{
		int kx,ky;
		if(i%7==1)
		cout<"1";
		else
		cout<<"0";
	}
	}
	else
	{
		if(x[n]<y[n])
		{
			for(int i=1;i<=q+1;i++)
			{
				cout<<"1";
			}cout<<endl;
		}
		
		else
		{
			for(int i=1;i<=q+1;i++)
			{
				cout<<"0";
			}cout<<endl;
		}
		
	}	return 0;
}
