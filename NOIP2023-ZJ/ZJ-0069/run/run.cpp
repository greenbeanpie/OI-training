#include<bits/stdc++.h>
using namespace std;
long long c,s,t,n,m,k,i,j,d,b,a[1001][1001],x[100001],y[100001],v[100001],f[1001][1001];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c<=9)
	{
		for(s=1;s<=t;s=s+1)
		{
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);b=0;
			for(i=1;i<=n;i=i+1)
			for(j=0;j<=n;j=j+1)
			{
				a[i][j]=0;
				f[i][j]=-9999999999999999;
			}
			for(i=1;i<=m;i=i+1)
			{
				scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
				a[x[i]][y[i]]=a[x[i]][y[i]]+v[i];
			}
			for(i=1;i<=n;i=i+1)
			for(j=1;j<=n;j=j+1)
			a[i][j]=a[i][j]+a[i][j-1];
			for(i=1;i<=n;i=i+1)
			{
				f[i][0]=b+a[i][0];b=f[i][0];
				for(j=1;j<=min(n,k);j=j+1)
				{
					f[i][j]=f[i-1][j-1]-d+a[i][j];
					b=max(b,f[i][j]);
				}
			}
			printf("%lld\n",b);
		}
		return 0;
	}
	else
	{
		for(s=1;s<=t;s=s+1)
		{
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);b=0;
			for(i=1;i<=m;i=i+1)
			{
				scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
				if(y[i]<=k&&v[i]-y[i]*d>0)b=b+v[i]-y[i]*d;
			}
			printf("%lld\n",b);
		}
		return 0;
	}
	return 0;
}
