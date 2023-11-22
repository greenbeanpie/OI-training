#include<bits/stdc++.h>
#define int long long
using namespace std;
int xx[2005],yy[2005],x[2005],y[2005],n,m;
int getsum()
{
	if((xx[1]-yy[1])*(xx[n]-yy[m])<=0) return 0;
	int now=0,flag=0,i,j;
	if(xx[1]-yy[1]<0) flag=1;
	for(i=1;i<=m;i++)
	{
		for(j=now+1;j<=n;j++)
		{
			if(flag&&xx[j]>yy[i]) break;
			if(!flag&&xx[j]<yy[i]) break;
		}
		j--;
		if(j==now)
		{
			for(j=now;j>=1;j--)
			{
				if(flag&&xx[j]<yy[i]) break;
				if(!flag&&xx[j]>yy[i]) break;
			}
			if(!j) return 0;
		}
		now=j;
	}
	return (now==n);
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,q,i,kx,ky,a,b;
	scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",x+i);
		xx[i]=x[i];
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",y+i);
		yy[i]=y[i];
	}
	printf("%lld",getsum());
	while(q--)
	{
		scanf("%lld%lld",&kx,&ky);
		for(i=1;i<=kx;i++)
		{
			scanf("%lld%lld",&a,&b);
			xx[a]=b;
		}
		for(i=1;i<=ky;i++)
		{
			scanf("%lld%lld",&a,&b);
			yy[a]=b;
		}
		printf("%lld",getsum());
		for(i=1;i<=n;i++)
			xx[i]=x[i];
		for(i=1;i<=m;i++)
			yy[i]=y[i];
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
