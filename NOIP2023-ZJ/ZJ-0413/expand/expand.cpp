#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int c,n,m,q;
ll kx,ky,xx[N],xy[N],yx[N],yy[N];
ll a[N],b[N],aa[N],bb[N];
int flag,mx[2005],vis;
bool tt;
void solve()
{
	if(a[1]-b[1]>0) flag=1;
	else flag=-1;
	if(a[1]==b[1]) printf("0");
	else{
		vis=0;
		for(int i=0;i<=n+1;i++)
			mx[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(flag*(a[i]-b[j])>0) mx[i]=j;
				else break;
		for(int i=1;i<=n;i++)
			if(mx[i-1]>mx[i]&&mx[i-1]>=i) mx[i]=mx[i-1];
		/*
		for(int i=1;i<=n;i++)
			cout<<mx[i]<<" ";
		cout<<endl;
		*/
		for(int i=1;i<=n;i++)
			if(mx[i]<i)
			{
				vis--;
				break;
			}
		vis++;
		
		for(int i=0;i<=n+1;i++)
			mx[i]=m+1;
		for(int i=n;i>=1;i--)
			for(int j=m;j>=1;j--)
				if(flag*(a[i]-b[j])>0) mx[i]=j;
				else break;
		for(int i=n;i>=1;i--)
			if(mx[i+1]<mx[i]&&mx[i+1]<=i) mx[i]=mx[i+1];
		/*
		for(int i=1;i<=n;i++)
			cout<<mx[i]<<" ";
		cout<<endl;
		*/
		for(int i=n;i>=1;i--)
			if(mx[i]>i)
			{
				vis--;
				break;
			}
		vis++;
		
		if(vis>=2) printf("1");
		else printf("0");
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),aa[i]=a[i];
	for(int i=1;i<=m;i++)
		scanf("%lld",&b[i]),bb[i]=b[i];
	if(n>m)
	{
		tt=true;
		for(int i=1;i<=n;i++)
		{
			swap(a[i],b[i]);
			swap(aa[i],bb[i]);
		}
		swap(n,m);
	}

	solve();
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&kx,&ky);
		for(int j=1;j<=n;j++)
			a[j]=aa[j];
		for(int j=1;j<=m;j++)
			b[j]=bb[j];
		for(int j=1;j<=kx;j++)
			scanf("%lld%lld",&xx[j],&xy[j]);
		for(int j=1;j<=ky;j++)
			scanf("%lld%lld",&yx[j],&yy[j]);
		if(tt)
		{
			for(int j=1;j<=max(kx,ky);j++)
			{
				swap(xx[j],yx[j]);
				swap(xy[j],yy[j]);
			}
			swap(kx,ky);
		}
		for(int j=1;j<=kx;j++)
			a[xx[j]]=xy[j];
		for(int j=1;j<=ky;j++)
			b[yx[j]]=yy[j];
		solve();
	}
	return 0;
}
