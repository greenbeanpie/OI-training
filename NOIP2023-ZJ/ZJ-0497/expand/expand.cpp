#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
int n,m,a[10001],c,q,b[10001],w,z,x[10001],y[10001],mina=1e10,minb=1e10;
int k,v;
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	IOS;
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	if(a[1]<b[1])
	{
		for(int i=1,maxa=0,maxb=0;i<=max(n,m);i++)
		{
			maxa=max(maxa,a[i]);
			if(i<=n)mina=min(mina,a[i]);
			maxb=max(maxb,b[i]);
			if(i<=m)minb=min(minb,b[i]);
			if(maxa>=maxb||mina>=minb)
			{
				cout<<0;
				break;
			}
		}
		cout<<1;
	}
	else if(a[1]>b[1])
	{
		for(int i=1,maxa=0,maxb=0;i<=max(n,m);i++)
		{
			maxa=max(maxa,a[i]);
			if(i<=n)mina=min(mina,a[i]);
			maxb=max(maxb,b[i]);
			if(i<=m)minb=min(minb,b[i]);
			if(maxa<=maxb||mina<=minb)
			{
				cout<<0;
				break;
			}
		}
		cout<<1;
	}
	else cout<<0;
	while(q--)
	{
		cin>>w>>z;
		for(int i=1;i<=n;i++)x[i]=a[i];
		for(int i=1;i<=m;i++)y[i]=b[i];
		for(int i=1;i<=w;i++)cin>>k>>v,x[k]=v;
		for(int i=1;i<=z;i++)cin>>k>>v,y[k]=v;
		for(int i=1;i<=n;i++)cout<<x[i]<<' '<<y[i]<<endl;
		mina=minb=1e10;
		if(x[1]<y[1])
		{
			bool is=1;
			for(int i=1,maxa=0,maxb=0;i<=max(n,m);i++)
			{
				maxa=max(maxa,x[i]);
				if(i<=n)mina=min(mina,x[i]);
				maxb=max(maxb,y[i]);
				if(i<=m)minb=min(minb,y[i]);
				if(maxa>=maxb||mina>=minb)
				{
					cout<<0;is=0;
					break;
				}
			}
			if(!is)continue;
			if(x[n]<y[m])cout<<1;
			else cout<<0;
		}
		else if(x[1]>y[1])
		{
			bool is=1;
			for(int i=1,maxa=0,maxb=0;i<=max(n,m);i++)
			{
				maxa=max(maxa,x[i]);
				if(i<=n)mina=min(mina,x[i]);
				if(i<=m)minb=min(minb,y[i]);
				maxb=max(maxb,y[i]);
				if(maxa<=maxb||mina<=minb)
				{
					cout<<0;is=0;
					break;
				}
			}
			if(!is)continue;
			if(x[n]>y[m])cout<<1;
			else cout<<0;
		}
		else cout<<0;
	}
}
