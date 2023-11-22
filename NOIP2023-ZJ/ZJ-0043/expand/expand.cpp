#include<iostream>
#include<cstdio>
using namespace std;
int o,n,m,q;
namespace June
{
	const int N=2010;
	int f[N][N];
	int a[N],b[N];
	int A[N],B[N];
	int solve()
	{
		if(a[1]==b[1]||a[n]==b[m]) return 0;
		if((a[1]<b[1])!=(a[n]<b[m])) return 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) f[i][j]=0;
		if(a[1]<b[1])
		{
			f[1][1]=1;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<m;j++)
					if(f[i][j]&&a[i]<b[j+1]) f[i][j+1]=1;
				if(i==n) break;
				for(int j=1;j<=m;j++)
					if(f[i][j]&&a[i+1]<b[j]) f[i+1][j]=1;
			}
			return f[n][m];
		}
		else
		{
			f[1][1]=1;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<m;j++)
					if(f[i][j]&&a[i]>b[j+1]) f[i][j+1]=1;
				if(i==n) break;
				for(int j=1;j<=m;j++)
					if(f[i][j]&&a[i+1]>b[j]) f[i+1][j]=1;
			}
			return f[n][m];
		}
	}
	void main()
	{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),A[i]=a[i];
		for(int i=1;i<=m;i++) scanf("%d",&b[i]),B[i]=b[i];
		printf("%d",solve());
		while(q--)
		{
			int lx,ly;
			scanf("%d%d",&lx,&ly);
			while(lx--)
			{
				int x,k;
				scanf("%d%d",&x,&k),a[x]=k;
			}
			while(ly--)
			{
				int x,k;
				scanf("%d%d",&x,&k),b[x]=k;
			}
			printf("%d",solve());
			for(int i=1;i<=n;i++) a[i]=A[i];
			for(int i=1;i<=m;i++) b[i]=B[i];
		}
	}
}
namespace Youth
{
	const int N=5e5+10;
	const int inf=2e9;
	int a[N],b[N];
	int A[N],B[N];
	int solve()
	{
		if(a[1]==b[1]||a[n]==b[m]) return 0;
		if((a[1]<b[1])!=(a[n]<b[m])) return 0;
		if(a[1]<b[1])
		{
			int l=1,r=1,mn=inf,mx=-inf;
			for(int i=1;i<=n;i++)
			{
				if(a[i]<mn)
				{
					while(l<=r&&b[l]<=mx) l++;
					if(l>r) return 0;
					while(r<m&&b[r+1]>a[i]) r++;
					mn=a[i],mx=-inf;
				}
				else mx=max(mx,a[i]);
			}
			return r==m;
		}
	}
	void main()
	{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),A[i]=a[i];
		for(int i=1;i<=m;i++) scanf("%d",&b[i]),B[i]=b[i];
		printf("%d",solve());
		while(q--)
		{
			int lx,ly;
			scanf("%d%d",&lx,&ly);
			while(lx--)
			{
				int x,k;
				scanf("%d%d",&x,&k),a[x]=k;
			}
			while(ly--)
			{
				int x,k;
				scanf("%d%d",&x,&k),b[x]=k;
			}
			printf("%d",solve());
			for(int i=1;i<=n;i++) a[i]=A[i];
			for(int i=1;i<=m;i++) b[i]=B[i];
		}
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&o,&n,&m,&q);
	if(o<=7) June::main(),exit(0);
	if(o<=14) Youth::main(),exit(0);
	return 0;
}