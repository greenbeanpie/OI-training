#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
const int MAXM = 5*1e5+5;
int c,n,m,q,f[MAXN][MAXN],p[MAXM],v[MAXM];
int X[MAXN],Y[MAXN],XX[MAXN],YY[MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-f;}ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;
}
void solve()
{
	
	f[1][1]=1;
	if(X[1]>Y[1])
	{
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(!f[i][j]) continue;
				if(i+1<=n&&j+1<=m&&X[i+1]>Y[j+1]) f[i+1][j+1]|=f[i][j];
				if(i+1<=n&&X[i+1]>Y[j]) f[i+1][j]|=f[i][j];
				if(j+1<=m&&X[i]>Y[j+1]) f[i][j+1]|=f[i][j]; 
			}
		}
		printf("%d",f[n][m]);
	}
	else if(X[1]==Y[1]) printf("0");
	else 
	{
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(!f[i][j]) continue;
				if(i+1<=n&&j+1<=m&&X[i+1]<Y[j+1]) f[i+1][j+1]|=f[i][j];
				if(i+1<=n&&X[i+1]<Y[j]) f[i+1][j]|=f[i][j];
				if(j+1<=m&&X[i]<Y[j+1]) f[i][j+1]|=f[i][j]; 
			}
		}
		printf("%d",f[n][m]);
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) X[i]=read(),XX[i]=X[i];
	for(int i=1;i<=m;i++) Y[i]=read(),YY[i]=Y[i];
	solve();
	while(q--)
	{
		int kx=read(),ky=read();
		
		for(int i=1;i<=kx;i++)p[i]=read(),v[i]=read(),X[p[i]]=v[i];
		for(int i=1;i<=ky;i++)p[i+kx]=read(),v[i+kx]=read(),Y[p[i+kx]]=v[i+kx];
		solve();
		for(int i=1;i<=kx;i++)X[p[i]]=XX[p[i]];
		for(int i=1;i<=ky;i++)Y[p[i+kx]]=YY[p[i+kx]];
	}
	puts("");
	return 0;
}
