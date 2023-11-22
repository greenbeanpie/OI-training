#include <bits/stdc++.h>
using namespace std;
int cp,n,m,q;
int k1,k2;
int x[500005];
int y[500005];
int dp[500005];
void did()
{
	if(x[1]==y[1]||x[n]==y[m])
	{
		cout<<0;
	}
	else if((x[1]-y[1])*(x[n]-y[m])<=0)
	{
		cout<<0;
	}
	else if(n==1&&m==1)
	{
		cout<<1;
	}
	else if(n==2&&m==1)
	{
		int a,b,c;
		a=x[1];
		b=x[2];
		c=y[1];
		if(a<c&&b<c||a>c&&b>c)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(n==1&&m==2)
	{
		int a,b,c;
		a=x[1];
		b=y[1];
		c=y[2];
		if(a<b&&a<c||a>b&&a>c)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(n==2&&m==2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>cp>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=m;i++) cin>>y[i];
	did();
	while(q--)
	{
		cin>>k1>>k2;
		for(int i=1;i<=k1;i++)
		{
			int px,vx;
			cin>>px>>vx;
			x[px]=vx;
		}
		for(int i=1;i<=k2;i++)
		{
			int px,vx;
			cin>>px>>vx;
			y[px]=vx;
		}
		did();
	}
	return 0;
}
//I don't know how to do it a!!!!!!!!!!!
