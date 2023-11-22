#include<iostream>
#include<vector>
using namespace std;

#define N 500010
#define M 500010
#define Q 70

int c,n,m,q;
int x[Q][N],y[Q][M];

bool check(int* a,int *b)
{
	if(a[1]>b[1])
	{
		int i=1,j=1,k=1;
		while(i!=n+1&&j!=m+1)
		{
			if(a[i]<=b[j])
			{
				bool flag=true;
				int t=j;
				for(int j=1;j<=t;j++)
				{
					if(a[i]>b[j])
					{
						flag=false;
						j++;
						break;
					}
				}
				if(flag)return false;
			}
			if(i<n||j>=m)i++;
			if(j<m||i-1>=n)j++;
		}
		return true;
	}
	else if(a[1]<b[1])
	{
		int i=1,j=1,k=1;
		while(i!=n+1&&j!=m+1)
		{
			if(a[i]>=b[j])
			{
				bool flag=true;
				int t=j;
				for(int j=1;j<=t;j++)
				{
					if(a[i]<b[j])
					{
						flag=false;
						j++;
						break;
					}
				}
				if(flag)return false;
			}
			if(i<n||j>=m)i++;
			if(j<m||i-1>=n)j++;
		}
		return true;
	}
	return false;
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x[0][i];
		for(int j=1;j<=q;j++)x[j][i]=x[0][i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>y[0][i];
		for(int j=1;j<=q;j++)y[j][i]=y[0][i];
	}
	for(int i=1;i<=q;i++)
	{
		int kx,ky;
		cin>>kx>>ky;
		for(int j=0;j<kx;j++)
		{
			int px,vx;
			cin>>px>>vx;
			x[i][px]=vx;
		}
		for(int j=0;j<ky;j++)
		{
			int py,vy;
			cin>>py>>vy;
			y[i][py]=vy;
		}
	}
	for(int i=0;i<=q;i++)
	{
		if(check(x[i],y[i]))cout<<1;
		else cout<<0;
	}
	return 0;
}