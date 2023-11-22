#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,q,kx,ky,x,y,a[500010],b[500010],f[500010],g[500010];
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=m;i++)
	cin>>b[i];
	if((a[1]==b[1])||(a[n]==b[n])||(a[1]-b[1]<0&&a[n]-b[n]>0)||(a[1]-b[1]>0&&a[n]-b[n]<0))
	cout<<"0";
	else
	{
		int maxa=0,maxb=0;
		for(int i=1;i<=n;i++)
		if(a[i]>maxa)
		maxa=a[i];
		for(int i=1;i<=m;i++)
		if(b[i]>maxb)
		maxb=b[i];
		if((maxb-maxa<=0&&b[1]-a[1]>0)||(maxb-maxa>=0&&b[1]-a[1]<0))
		cout<<"0";
		else
		cout<<1;
	}
	while(q--)
	{
		cin>>kx>>ky;
		for(int i=1;i<=n;i++)
		f[i]=a[i];
		for(int i=1;i<=m;i++)
		g[i]=b[i];
		for(int i=1;i<=kx;i++)
		{
			cin>>x>>y;
			f[x]=y;
		}
		for(int i=1;i<=ky;i++)
		{
			cin>>x>>y;
			g[x]=y;
		}
		if((f[1]==g[1])||(f[n]==g[n])||(f[1]-g[1]<0&&f[n]-g[n]>0)||(f[1]-g[1]>0&&f[n]-g[n]<0))
		cout<<"0";
		else
		{
			int maxf=0,maxg=0;
			for(int i=1;i<=n;i++)
			if(f[i]>maxf)
			maxf=f[i];
			for(int i=1;i<=m;i++)
			if(g[i]>maxg)
			maxg=g[i];
			if((maxg-maxf<=0&&g[1]-f[1]>0)||(maxg-maxf>=0&&g[1]-f[1]<0))
			cout<<"0";
			else
			cout<<1;
		}
		
	}
}
