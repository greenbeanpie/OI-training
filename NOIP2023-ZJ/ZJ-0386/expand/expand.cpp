#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=500005;
int a[N],b[N],px[N],vx[N],py[N],vy[N];
bool f[2005][2005];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int C=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	f[0][0]=true;
	if(a[1]>b[1])
	{
		for(int i=1;i<=n;i++)
		{
			bool x=false;
			for(int j=1;j<=m;j++)
			{
				x=x||f[i-1][j-1];
				if(a[i]<=b[j]) x=false;
				else f[i][j]=x||f[i-1][j];
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			bool x=false;
			for(int j=1;j<=m;j++)
			{
				x=x||f[i-1][j-1];
				if(a[i]>=b[j]) x=false;
				else f[i][j]=x||f[i-1][j];
			}
		}
//		for(int i=1;i<=n;i++,puts(""))
//			for(int j=1;j<=m;j++)
//				cout<<f[i][j]<<' ';
	}
	if(f[n][m]) printf("1");
	else printf("0");
	while(q--)
	{
		int kx=read(),ky=read();
		for(int i=1;i<=kx;i++) px[i]=read(),vx[i]=read(),swap(a[px[i]],vx[i]);
		for(int i=1;i<=ky;i++) py[i]=read(),vy[i]=read(),swap(b[py[i]],vy[i]);
		memset(f,0,sizeof(f)),f[0][0]=true;
		if(a[1]>b[1])
		{
			for(int i=1;i<=n;i++)
			{
				bool x=false;
				for(int j=1;j<=m;j++)
				{
					x=x||f[i-1][j-1];
					if(a[i]<=b[j]) x=false;
					else f[i][j]=x||f[i-1][j];
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				bool x=false;
				for(int j=1;j<=m;j++)
				{
					x=x||f[i-1][j-1];
					if(a[i]>=b[j]) x=false;
					else f[i][j]=x||f[i-1][j];
				}
			}
	//		for(int i=1;i<=n;i++,puts(""))
	//			for(int j=1;j<=m;j++)
	//				cout<<f[i][j]<<' ';
		}
		if(f[n][m]) printf("1");
		else printf("0");
//		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
//		puts("");
//		for(int i=1;i<=m;i++) cout<<b[i]<<' ';
//		puts("");
		for(int i=1;i<=kx;i++) swap(a[px[i]],vx[i]);
		for(int i=1;i<=ky;i++) swap(b[py[i]],vy[i]);
	}
	return 0;
}
/*
195982977 303897138 437154869 81559605 365511323 302808478
342942401 297976421 445071632 83871721 304067809 427239638
*/