#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],aa[500010],bb[500010],l[100000],s=1;
long long int c,n,m,q;
void check()
{
	if(aa[1]<=bb[1])
	{
		l[s]=0;
		s++;
		return;
	}
	if(aa[n]<=bb[m])
	{
		l[s]=0;
		s++;
		return;
	}
	int minn=500005,maxn=-1,minm=500005,maxm=-1;
	for(int i=1;i<=n;i++)
	{
		if(aa[i]>maxn)
			maxn=aa[i];
		if(aa[i]<minn)
			minn=aa[i];
	}
	for(int i=1;i<=m;i++)
	{
		if(bb[i]>maxm)
			maxm=bb[i];
		if(bb[i]<minm)
			minm=bb[i];
	}
	if(maxn<maxm||minn<minm)
	{
		l[s]=0;
		s++;
		return;
	}
	l[s]=1;
	s++;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	memset(b,0,sizeof(b));
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	
	if(c==1||(n==1&&m==1))
	{
		int tot=2;
		if(a[1]>b[1])
			l[1]=1;
		else
			l[1]=0;
		for(int i=1;i<=q;i++)
		{
			for(int j=1;j<=n;j++)
				aa[j]=a[j];
			for(int j=1;j<=m;j++)
				bb[j]=b[j];
			int kx,ky;
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++)
			{
				int px,vx;
				cin>>px>>vx;
				aa[px]=vx;
			}
			for(int j=1;j<=ky;j++)
			{
				int py,vy;
				cin>>py>>vy;
				bb[py]=vy;
			}
			if(aa[1]>bb[1])
				l[tot]=1;
			else
				l[tot]=0;
			tot++;
		}
		for(int i=1;i<=q+1;i++)
			cout<<l[i];
		return 0;
	}
	if(c==2)
	{	
		int tot=2;
		if(n==1)
		{
			if(a[1]<=b[1]||a[1]<=b[2])
				l[1]=0;
			else
				l[1]=1;
		}
		if(n==2)
		{
			if(a[1]<=b[1]||a[1]<=b[2]||a[2]<=b[2])
				l[1]=0;
			else
				l[1]=1;
		}
		for(int i=1;i<=q;i++)
		{
			memset(bb,0,sizeof(bb));
			for(int j=1;j<=n;j++)
				aa[j]=a[j];
			for(int j=1;j<=m;j++)
				bb[j]=b[j];
			int kx,ky;
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++)
			{
				int px,vx;
				cin>>px>>vx;
				aa[px]=vx;
			}
			for(int j=1;j<=ky;j++)
			{
				int py,vy;
				cin>>py>>vy;
				bb[py]=vy;
			}
			if(n==1)
			{
				if(aa[1]<=bb[1]||aa[1]<=bb[2])
					l[tot]=0;
				else
					l[tot]=1;
			}
			if(n==2)
			{
				if(aa[1]<=bb[1]||aa[1]<=bb[2]||aa[2]<=bb[2])
					l[tot]=0;
				else
					l[tot]=1;
			}
			tot++;
		}
		for(int i=1;i<=q+1;i++)
			cout<<l[i];
		return 0;
	}
	for(int j=1;j<=n;j++)
		aa[j]=a[j];
	for(int j=1;j<=m;j++)
		bb[j]=b[j];
	check();
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++)
			aa[j]=a[j];
		for(int j=1;j<=m;j++)
			bb[j]=b[j];
		int kx,ky;
		cin>>kx>>ky;
		for(int j=1;j<=kx;j++)
		{
			int px,vx;
			cin>>px>>vx;
			aa[px]=vx;
		}
		for(int j=1;j<=ky;j++)
		{
			int py,vy;
			cin>>py>>vy;
			bb[py]=vy;
		}
		check();
	}
	for(int i=1;i<=q+1;i++)
		cout<<l[i];
	return 0;
}

