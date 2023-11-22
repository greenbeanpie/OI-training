#include<bits/stdc++.h>
using namespace std;
long long t,n,m,q,i,j,k,a[500005],b[500005],c[500005],d[500005],g,f[2002][2002],x,y,u,v;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%lld%lld%lld%lld",&t,&n,&m,&q);
	for(i=1;i<=n;i=i+1){scanf("%lld",&a[i]);c[i]=a[i];}
	for(i=1;i<=m;i=i+1){scanf("%lld",&a[i]);d[i]=b[i];}
	if(a[1]==b[1])printf("0");
	else
	{
		f[1][1]=1;
		if(a[1]>b[1])g=1;else g=-1;
		for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
		{
			if(j>1&&a[i]*g>b[j]*g&&f[i][j-1])f[i][j]=1;
			if(i>1&&a[i]*g>b[j]*g&&f[i-1][j])f[i][j]=1;
			if(i>1&&j>1&&a[i]*g>b[j]*g&&f[i-1][j-1])f[i][j]=1;
		}
		printf("%lld",f[n][m]);
	}
	for(k=1;k<=q;k=k+1)
	{
		for(i=1;i<=n;i=i+1)a[i]=c[i];
		for(i=1;i<=m;i=i+1)b[i]=d[i];
		scanf("%lld%lld",&x,&y);
		for(i=1;i<=x;i=i+1){scanf("%lld%lld",&u,&v);a[u]=v;}
		for(i=1;i<=y;i=i+1){scanf("%lld%lld",&u,&v);b[u]=v;}
		if(a[1]==b[1])printf("0");
		else
		{
			f[1][1]=1;
			if(a[1]>b[1])g=1;else g=-1;
			for(i=1;i<=n;i=i+1)
			for(j=1;j<=m;j=j+1)
			{
				if(i>1||j>1)f[i][j]=0;
				if(j>1&&a[i]*g>b[j]*g&&f[i][j-1])f[i][j]=1;
				if(i>1&&a[i]*g>b[j]*g&&f[i-1][j])f[i][j]=1;
				if(i>1&&j>1&&a[i]*g>b[j]*g&&f[i-1][j-1])f[i][j]=1;
			}
			printf("%lld",f[n][m]);
		}
	}
	return 0;
}
