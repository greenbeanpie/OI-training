#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN=5e5+5;
int c,n,m,q;
int x[MAXN],y[MAXN];
int st[2002][2002];
void read(int &x)
{
	x=0;
	char ch=getchar();
	while (ch>'9' || ch<'0')
		ch=getchar();
	while (ch>='0' && ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
}
char inalpha()
{
	char ch=getchar();
	while ((ch!='T' && ch!='U' && ch!='F') && (ch!='+' && ch!='-')) 
		ch=getchar();
	return ch;
}
int tmp[MAXN];
bool check()
{
	tmp[n+1]=m+1;
	if(tmp[n]<m)
		return 0;
	for (int i=1;i<=n;i++)
	{
		bool fl=0;
		for (int j=1;j<=st[i][0];j+=2)
		{
			if (tmp[i-1]+1>=st[i][j] && (tmp[i]<=st[i][j+1]))
				fl=1;
		}
		if (!fl)
			return 0;
	}
	return 1 ;
}
bool nans=0;
void dfs(int dep)
{
	if (nans==1)
		return ;
	if (dep==n+1)
	{
		if (check())
			nans=1;
		return ;		
	}
	for (int i=tmp[dep-1];i<=m+1;i++)
		tmp[dep]=i,dfs(dep+1);
}
bool pre()
{
	if (x[1]>y[1])
	{		
		if (x[n]<y[m])
		{
			return 0;
		}
		y[m+1]=-0x3f3f3f3f;
		for (int i=1;i<=n;i++)
		{
			st[i][0]=0;
			for (int j=1;j<=m;j++)
			{
				if (y[j]<x[i])
				{
					st[i][++st[i][0]]=j;
					while (y[j]<x[i] &&j<=m)
						j++;
					st[i][++st[i][0]]=j-1;
					j--;
				}
			}
		}
	}
	else
	{		
		y[m+1]=0x3f3f3f3f;
		if (x[n]>y[m])
		{
			return 0;
		}
		for (int i=1;i<=n;i++)
		{
			st[i][0]=0;
			for (int j=1;j<=m;j++)
			{
				if (y[j]>x[i])
				{
					st[i][++st[i][0]]=j;
					while (y[j]>x[i] &&j<=m)
						j++;
					st[i][++st[i][0]]=j-1;
					j--;
				}
			}
		}
	}
	return 1 ;
}
void cg()
{
	if (pre()==0 || (x[1]==y[1] || x[n]==y[m]))
	{
		printf("0");
	}
	tmp[0]=1;
	dfs(1);
	printf("%d",nans);
	for (int i=1;i<=q;i++)
	{
		int kx,ky;
		int t1[2001],t2[2001];
		for (int i=1;i<=n;i++)
			t1[i]=x[i];
		for (int i=1;i<=m;i++)
			t2[i]=y[i];
		read(kx),read(ky);
		//printf("%d %d\n",kx,ky);
		for (int j=1;j<=kx;j++)
		{
			int px,vx;
			read(px),read(vx);
		//	printf("%d %d\n",px,vx);
			x[px]=vx;
		}
		for (int j=1;j<=ky;j++)
		{
			int py,vy;
			read(py),read(vy);
		//	printf("%d %d\n",py,vy);
			y[py]=vy;
		}
		if (x[1]==y[1] || x[n]==y[m])
		{
			printf("0");
			for (int i=1;i<=n;i++)
				x[i]=t1[i];
			for (int i=1;i<=m;i++)
				y[i]=t2[i];
			continue ;

		}
		if (pre()==0)
		{
			printf("0");
			for (int i=1;i<=n;i++)
				x[i]=t1[i];
			for (int i=1;i<=m;i++)
				y[i]=t2[i];
			continue ;
		}
		nans=0;
		tmp[0]=1;
		dfs(1);
		printf("%d",nans);
		for (int i=1;i<=n;i++)
			x[i]=t1[i];
		for (int i=1;i<=m;i++)
			y[i]=t2[i];
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	read(c),read(n),read(m),read(q);
//	printf("%d %d %d %d\n",c,n,m,q);
	for (int i=1;i<=n;i++)
		read(x[i]);//printf("%d ",x[i]);
	for (int i=1;i<=m;i++)
		read(y[i]);//printf("%d ",y[i]);
	if (c==1)
	{
		cg();
	}
	if (c==2)
	{
		cg();
	}
	if (c>=3 &&c<=4)
	{
		cg();
	}
	return 0;
}
