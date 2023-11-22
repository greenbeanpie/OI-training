#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN=1e5+5;
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
int c ,t ,ans=MAXN+5;
int typ[MAXN],op[MAXN][3],n,m;
int NOT(int a)
{
	if (a==0)
		return 1;
	if (a==1)
		return 0;
	return 2 ;
}
bool check()
{
	int a[11];
	for (int i=1;i<=n;i++)
		a[i]=typ[i];
	for (int i=1;i<=m;i++)
	{
		if (op[i][0]==0)
			a[op[i][1]]=0;
		if (op[i][0]==1)
			a[op[i][1]]=1;
		if (op[i][0]==2)
			a[op[i][1]]=2;
		if (op[i][0]==3)
			a[op[i][1]]=a[op[i][2]];
		if (op[i][0]==4)
			a[op[i][1]]=NOT(a[op[i][2]]);
	}
	for (int i=1;i<=n;i++)
		if (a[i]!=typ[i])
			return false;
	return true ;
}
int work2()
{
	int a[MAXN]={},c=0;
	for (int i=1;i<=m;i++)
	{
		if (op[i][0]==0)
			a[op[i][1]]=0;
		if (op[i][0]==1)
			a[op[i][1]]=1;
		if (op[i][0]==2)
			a[op[i][1]]=2;
		if (op[i][0]==3)
			a[op[i][1]]=a[op[i][2]];
		if (op[i][0]==4)
			a[op[i][1]]=NOT(a[op[i][2]]);
	}
	for (int i=1;i<=n;i++)
		if (a[i]==2)
		{
			c++;
	//printf("-- %d\n",i);
		}
	return c ;
}
void dfs(int dep,int sum)
{
	if (dep==n+1)
	{
		if (check())
		{
			if (sum<ans)
				ans=sum;
		}
		return ;
	}
	typ[dep]=0;
	dfs(dep+1,sum);
	typ[dep]=1;
	dfs(dep+1,sum);
	typ[dep]=2;
	dfs(dep+1,sum+1);
}
void readin()
{
	read(n),read(m);
	for (int i=1;i<=m;i++)
	{
		char ch;
		char v=inalpha();
		if (v=='F')
		{
			int x;read(x);
			op[i][0]=0,op[i][1]=x;
		}
		if (v=='T')
		{
			int x;read(x);
			op[i][0]=1,op[i][1]=x;
		}
		if (v=='U')
		{
			int x;read(x);
			op[i][0]=2,op[i][1]=x;
		}
		if (v=='+')
		{
			int x,y;read(x),read(y);
			op[i][0]=3,op[i][1]=x,op[i][2]=y;
		}
		if (v=='-')
		{
			int x,y;read(x),read(y);
			op[i][0]=4,op[i][1]=x,op[i][2]=y;
		}
	}
}
int fa[MAXN+3];
/*
void build()
{
	fa[n+1]=n+1,fa[n+2]=n+2,fa[n+3]=n+3;
	for (int i=1;i<=n;i++)
		fa[i]=i;
	for (int i=1;i<=n;i++)
	{
		if (op[i][0]==2)
			fa[i]=n+3;
		
	}
}*/
bool work3()
{
	c=0;
	for (int i=1;i<=m;i++)
	{
		if (op[i][0]==0)
			typ[op[i][1]]=0;
		if (op[i][0]==1)
			typ[op[i][1]]=1;
		if (op[i][0]==2)
			typ[op[i][1]]=2;
		if (op[i][0]==3)
			typ[op[i][1]]=typ[op[i][2]];
		if (op[i][0]==4)
			typ[op[i][1]]=NOT(typ[op[i][2]]);
	}
	for (int i=1;i<=n;i++)
		if (typ[i]==2)
		{
			c++;
		}
	if (ans==c)
		return 1;
	ans=c;
	return 0;	
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	read(c),read(t);
	if (c<=2)
	{
		while(t--)
		{
			readin();
			ans=n;
			dfs(1,0);
			printf("%d\n",ans);
		}
	}
	if (c>=3 && c<=4)
	{
		while (t--)
		{
			readin();
			ans=n;
			printf("%d\n",work2());
		}
	}
	if (c>=5 && c<=6)
	{
		while (t--)
		{
			readin();
			ans=0;
			for (int i=1;i<=n;i++)
				typ[i]=0;
			while (1)
			{
				if (work3())
					break;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}