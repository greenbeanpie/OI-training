#include<bits/stdc++.h>
#define maxm 2010
using namespace std;
int c,n,m,q;
int x[maxm],y[maxm];
int read(int x=0,int y=1,char ch=getchar())
{
	for(;!isdigit(ch);ch=getchar())
		if(ch=='-')y=-1;
	for(;isdigit(ch);ch=getchar())
		x=x*10+ch-'0';
	return x*y;
}
void solve1()
{
	if(x[1]!=y[1])cout<<"1";
	else cout<<"0";
	while(q--)
	{
		int kx=read(),ky=read();
		for(int i=1,p,v;i<=kx;i++)
		{
			p=read();v=read();
			x[p]=v;
		}
		for(int i=1,p,v;i<=ky;i++)
		{
			p=read();v=read();
			y[p]=v;
		}
		if(x[1]!=y[1])cout<<"1";
		else cout<<"0";
	}
	return ;
}
bool vis[maxm][maxm];
void solve2()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x[i]>y[j])vis[i][j]=1;
			else break;
		}
			
	}
	int last=0;
	bool bl=1;
	for(int i=1;i<=n;i++)
	{
		bl=0;
		for(int j=1;j<=last;j++)
			if(vis[i][j])vis[i][j]=1;
		for(int j=last+1;j<=m;j++)
		{
			if(!vis[i][j])break;
			last=j;bl=1;
		}
		if(!bl)break;
	}
	if(last==m)ans++;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x[i]<y[j])vis[i][j]=1;
			else break;
		}
			
	}
	last=0;
	bl=1;
	for(int i=1;i<=n;i++)
	{
		bl=0;
		for(int j=1;j<=last;j++)
			if(vis[i][j])vis[i][j]=1;
		for(int j=last+1;j<=m;j++)
		{
			if(!vis[i][j])break;
			last=j;bl=1;
		}
		if(!bl)break;
	}
	if(last==m)ans++;
	if(ans)cout<<"1";
	else cout<<"0";
	while(q--)
	{
		int kx=read(),ky=read();
		for(int i=1,p,v;i<=kx;i++)
		{
			p=read();v=read();
			x[p]=v;
		}
		for(int i=1,p,v;i<=ky;i++)
		{
			p=read();v=read();
			y[p]=v;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(x[i]>y[j])vis[i][j]=1;
				else break;
			}
				
		}
		int last=0;
		bool bl=1;
		for(int i=1;i<=n;i++)
		{
			bl=0;
			for(int j=1;j<=last;j++)
				if(vis[i][j])vis[i][j]=1;
			for(int j=last+1;j<=m;j++)
			{
				if(!vis[i][j])break;
				last=j;bl=1;
			}
			if(!bl)break;
		}
		if(last==m)ans++;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(x[i]<y[j])vis[i][j]=1;
				else break;
			}
				
		}
		last=0;
		bl=1;
		for(int i=1;i<=n;i++)
		{
			bl=0;
			for(int j=1;j<=last;j++)
				if(vis[i][j])vis[i][j]=1;
			for(int j=last+1;j<=m;j++)
			{
				if(!vis[i][j])break;
				last=j;bl=1;
			}
			if(!bl)break;
		}
		if(last==m)ans++;
		if(ans)cout<<"1";
		else cout<<"0";
	}
	return ;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	for(int i=1;i<=n;i++)
		x[i]=read();
	for(int i=1;i<=m;i++)
		y[i]=read();
	if(n==1&&m==1)
	{
		solve1();
		return 0;
	}
	if(n<=2000&&m<=2000)
	{
		solve2();
		return 0;
	}
	return 0;
}
