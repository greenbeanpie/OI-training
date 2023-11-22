#include<bits/stdc++.h>
using namespace std;
long long tong[2005][2005];
long long f[100005];
struct gcxt
{
	int x,y;
	long long z;
} a[100005];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int type,T;
	scanf("%d%d",&type,&T);
	while (T--)
	{
		int n,m,k,d;
		memset(tong,0,sizeof(tong));
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].z);
			for (int j=a[i].y;j<=k;j++)
				if (a[i].x-j+1>=0)
				tong[a[i].x][j]+=a[i].z;
		}
		for (int i=1;i<=n;i++) f[i]=0;
		f[0]=0;
		for (int i=1;i<=n;i++)
		{
			f[i]=max(f[i],f[i-1]);
			for (int j=0;j<i;j++)
			{
				if (i-j>k) continue;
				long long sum=0;
				for (int now=j+1;now<=i;now++)
				{
					int del=now-j;
					sum+=tong[now][del];
				}
				f[i]=max(f[i],f[j]-(i-j)*d+sum);
			}
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}
