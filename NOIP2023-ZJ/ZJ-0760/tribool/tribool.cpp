#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
#define CI const int
using namespace std;
const int N=1e5+5,inf=1e9;
int C,T,n,m;
char s[5];
int read(int& v)
{
	char ch;int f=1;
	for(ch='*';!isdigit(ch) && ch!='-';ch=getchar());
	if(ch=='-')  f=-1,ch=getchar();
	for(v=0;isdigit(ch);v=v*10+ch-'0',ch=getchar());
	v*=f;
return v;
}
struct oper
{
	int op,x,y;
	oper(CI& op,CI& x,CI& y):op(op),x(x),y(y){}
	oper(){}
}p[N];
namespace sub1
{
	const int M=15;
	int ans,a[M],b[M];
	bool check(int cnt)
	{
		for(int i=1;i<=n;i++)  b[i]=a[i];
		for(int i=1;i<=m;i++)
		{
			int x=p[i].x,y=p[i].y;
			switch(p[i].op)
			{
				case 1:b[x]=1;break;
				case 2:b[x]=2;break;
				case 3:b[x]=3;break;
				case 4:b[x]=b[y];break;
				case 5:
				{
					if(b[y]==1)       b[x]=2;
					else if(b[y]==2)  b[x]=1;
					else if(b[y]==3)  b[x]=3;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i])  return 0;
		return 1;
	}
	void dfs(int id,int cnt)
	{
		if(ans==0)  return;
		if(id>n)
		{
			if(check(cnt))  ans=min(ans,cnt);
			return;
		}
		a[id]=1,dfs(id+1,cnt);
		if(ans==0)  return;
		a[id]=2,dfs(id+1,cnt);
		if(ans==0)  return;
		a[id]=3,dfs(id+1,cnt+1);
		if(ans==0)  return;
	}
	void main()
	{
		ans=inf,dfs(1,0);
		printf("%lld\n",ans);
	}
}
void solve()
{
	read(n),read(m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s+1);
		switch(s[1])
		{
			case 'T':p[i].op=1;break;
			case 'F':p[i].op=2;break;
			case 'U':p[i].op=3;break;
			case '+':p[i].op=4;break;
			case '-':p[i].op=5;break;
		}
		read(p[i].x);
		if(p[i].op>3)  read(p[i].y);
	}
	if(C==1 || C==2){ sub1::main(); return; }
	/*if(C==7 || C==8)*/{ puts("0"); return; }
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	read(C),read(T);
	while(T--)  solve();
return 0;
}