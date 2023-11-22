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
		printf("QQ %d %d\n",i,a[i]);
	return true ;
}
int work2()
{
	int a[MAXN]={},c=0;
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
			printf("-- %d\n",i);
		}
	return c ;
}
void dfs(int dep,int sum)
{
	if (dep==n+1)
	{
		if (check())
			if (sum<ans)
				ans=sum;
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
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("ans.out","w",stdout);
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
	else if (c>=3 && c<=6)
	{
		while (t--)
		{
			readin();
			ans=n;
			printf("%d\n",work2());
			printf("%d\n",check());
		}
	}
	return 0;
}